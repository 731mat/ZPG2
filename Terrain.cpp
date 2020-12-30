//
// Created by Matěj Hloušek on 28/12/2020.
//

#include "Terrain.h"



Terrain::Terrain(Shader *shader, int w, int h, glm::vec3 setPosition) {

    terrainVBO = 0;
    terrainVAO = 0;

    this->width = w;
    this->height = h;

    viewMat = glm::mat4(1.f);
    projectionMat = glm::mat4(1.f);

    modelMat = glm::mat4(1.0f);
    modelMat = glm::translate(modelMat, setPosition);

    this->shader = shader;

    snowTexture = new Texture("snow.png");
    grassTexture = new Texture("grass.jpg");
    waterTexture = new Texture("watter.png");

    auto arr = GenerateTriangleStripData(width, height);

    glGenVertexArrays(1, &terrainVAO);
    glGenBuffers(1, &terrainVBO);
    glBindVertexArray(terrainVAO);
    glBindBuffer(GL_ARRAY_BUFFER, terrainVBO);
    glBufferData(GL_ARRAY_BUFFER, arr.size() * sizeof(TerrainVertex), arr.data(), GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(TerrainVertex), (GLvoid*)0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(TerrainVertex), (GLvoid*)offsetof(TerrainVertex, Normal));

}

Terrain::~Terrain()
{

}


std::vector<TerrainVertex> Terrain::GenerateTriangleStripData(int width, int height)
{
    vector<TerrainVertex> result;
    result.reserve(width * height * 2);

    auto terrain = GenerateTerrain(width, height);

    for (int y = 0; y < height - 1; y++)
        for (int x = 0; x < width; x++)
        {
            result.push_back(terrain[y * width + x]);
            result.push_back(terrain[(y + 1) * width + x]);
        }

    return result;
}

std::vector<TerrainVertex> Terrain::GenerateTerrain(int width, int height)
{
    std::vector<TerrainVertex> terrain = std::vector<TerrainVertex>(width * height);

    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++)
        {
            glm::vec2 c = 4.0f * glm::vec2(x / (float)(width), y / (float)(height));
            auto value = 10 * glm::perlin(c);

            terrain[y * width + x].Position = glm::vec3(-width / 2 + x, value, -height / 2 + y);
        }


    for (int y = 1; y < height - 1; y++)
        for (int x = 1; x < width - 1; x++)
        {
            glm::vec3 mid = terrain[y * height + x].Position;

            glm::vec3 v1 = normalize(terrain[y * height + x + 1].Position - mid); // left
            glm::vec3 v2 = normalize(terrain[(y - 1) * height + x].Position - mid); // down
            glm::vec3 v3 = normalize(terrain[y * height + x - 1].Position - mid); // right
            glm::vec3 v4 = normalize(terrain[(y + 1) * height + x].Position - mid); // up

            glm::vec3 v12 = normalize(cross(v1, v2));
            glm::vec3 v23 = normalize(cross(v2, v3));
            glm::vec3 v34 = normalize(cross(v3, v4));
            glm::vec3 v41 = normalize(cross(v4, v1));

            terrain[y * width + x].Normal = normalize(v12 + v23 + v34 + v41);
        }

    return terrain;
}

void Terrain::draw() {

    shader->setShader();

    this->shader->setModelMatrix(modelMat);

    this->grassTexture->bind(this->shader, "grassTexture", 0);
    this->snowTexture->bind(this->shader, "snowTexture", 1);
    this->waterTexture->bind(this->shader, "waterTexture", 2);

    glBindVertexArray(terrainVAO);

    for (int i = 0; i < height; i++)
    {
        glDrawArrays(GL_TRIANGLE_STRIP, 2 * i * width, width * 2);
    }

    this->grassTexture->unbind();
    this->snowTexture->unbind();
    this->waterTexture->unbind();
}