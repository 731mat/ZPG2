//
// Created by Matěj Hloušek on 10/12/2020.
//

#ifndef PROJEKT_FINAL_TEXTURE_H
#define PROJEKT_FINAL_TEXTURE_H


#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <cstdio>
#include <string>

//Include GLM
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr

#include <SOIL/SOIL.h>



class Shader;

class Texture {
private:
    std::string path;

public:
    Texture();
    ~Texture();
    void loadTexture(Shader* shader);
};



#endif //PROJEKT_FINAL_TEXTURE_H
