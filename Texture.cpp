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
}

Texture::Texture(std::string path)
{
    this->path = path;
    loadTexture();
}

Texture::~Texture()
{
    delete this;
}

void Texture::loadTexture()
{



    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);


    // Setup texture scaling filtering
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);


    //stbi_set_flip_vertically_on_load(1);





    int width, height, nrChannels;
    unsigned char* data = stbi_load(("../textures/"+path).c_str(), &width, &height, &nrChannels, 4);

    if(stbi_failure_reason())
        std::cout <<"Chyby nacitani textury: "<< stbi_failure_reason()<< " [" << path << "]"<< std::endl;

    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    }
    else
    {
        cout << "Failed to load texture" << endl;
        exit(-1);
    }
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


    glGenerateMipmap(GL_TEXTURE_2D);
    glGetError();

    stbi_image_free(data);

}



void Texture::bind(Shader* shader, const GLchar *nazev ) {

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, id);
    glUniform1i(glGetUniformLocation(shader->getID(), nazev), 0);
    shader->send(nazev,0);

    glGetError();
    //unbind();
}

void Texture::bind(Shader* shader, const GLchar *nazev, int offset) {

    glActiveTexture(GL_TEXTURE0 + offset);
    glBindTexture(GL_TEXTURE_2D, id);
    glUniform1i(glGetUniformLocation(shader->getID(), nazev), offset);
    shader->send(nazev,offset);

    glGetError();
    //unbind();
}

void Texture::unbind() {
    glBindTexture(GL_TEXTURE_2D, 0);
}

int Texture::getId() {
    return id;
}
