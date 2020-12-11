//
// Created by Matěj Hloušek on 10/12/2020.
//

#include "Texture.h"
#include "Shader.h"
#include <cstdio>
#include "./external/stb_image.h"
#define STB_IMAGE_IMPLEMENTATION


Texture::Texture()
{
    //this->path = path;
    //loadTexture();
}

Texture::~Texture()
{
    delete this;
}

void Texture::loadTexture(Shader* shader)
{

    char path[200] = "/Users/hlousek/Documents/skola/5sem/ZPG/projekt_final/textures/wall-small.png";

    GLuint x =1;
    glGenTextures(1, &x);
    glBindTexture(GL_TEXTURE_2D, x);

    //stbi_set_flip_vertically_on_load(1);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    int width, height, nrChannels;
    unsigned char* data = stbi_load(path, &width, &height, &nrChannels, 4);

    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    }
    else
    {
        cout << "Failed to load texture" << endl;
        exit(-1);
    }
    stbi_image_free(data);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, x);


    glActiveTexture(GL_TEXTURE0);

    glUniform1i(glGetUniformLocation(shader->getID(), "textura"), 0);

}
