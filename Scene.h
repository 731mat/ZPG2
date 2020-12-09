//
// Created by Matěj Hloušek on 09/12/2020.
//

#ifndef PROJEKT_FINAL_SCENE_H
#define PROJEKT_FINAL_SCENE_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>


//Include GLM
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr

//Include the standard C++ headers
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <vector>

#include "Shader.h"
#include "Camera.h"
#include "Controller.h"
#include "Object.h"
#include "Light.h"
#include "opengl_helper.h"

class Scene : public OnChangeLightObserver{
private:

    Shader *lambert, *phong;
    Camera* camera;
    Light* light, *light2;
    Object* plane;
    std::vector<Object*> objects;

    void createObj();
    void compileShaders();

public:

    std::vector<Light*> lights;
    Scene();
    ~Scene();
    void drawObj();
    void addObj(double x, double y);
    void updateLight(Light* light);
    Camera* getCamera();
    Light* getLight();
};


#endif //PROJEKT_FINAL_SCENE_H
