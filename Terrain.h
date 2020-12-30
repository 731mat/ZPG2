//
// Created by Matěj Hloušek on 28/12/2020.
//

#ifndef PROJEKT_FINAL_TERRAIN_H
#define PROJEKT_FINAL_TERRAIN_H

#include <vector>
#include <glm/vec2.hpp> // glm::vec3
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr
#include <glm/gtc/noise.hpp>

#include "Texture.h"
#include "Shader.h"
#include "OnChangeCameraObserver.h"



struct TerrainVertex {
    glm::vec3 Position;
    glm::vec3 Normal = glm::vec3(0,1,0);
};


class Terrain {
private:
    Shader* shader;
    GLuint terrainVAO, terrainVBO;
    glm::mat4 viewMat, projectionMat, modelMat;
    int width, height;


    Texture *grassTexture = nullptr;
    Texture *snowTexture = nullptr;
    Texture *waterTexture = nullptr;


    std::vector<TerrainVertex> GenerateTriangleStripData(int width, int height);
    std::vector<TerrainVertex> GenerateTerrain(int width, int height);



public:
    Terrain(Shader* shader, int w, int h,glm::vec3 setPosition);
    ~Terrain();

    void draw();
};


#endif //PROJEKT_FINAL_TERRAIN_H
