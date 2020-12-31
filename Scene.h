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
#include "MeshManager.h"
#include "Texture.h"
#include "SkyBox.h"
#include "Terrain.h"


class Scene : public OnChangeLightObserver{
private:

    Shader *lambert, *phong, *skybox_shader, *phong_bez_txt, *terrain_shader;
    Camera* camera;
    Light* light, *light2, *light3;
    Texture *texture,*texture2;
    SkyBox* skybox;
    std::vector<Object*> objects;
    std::vector<Light*> lights;
    Terrain* terrain;


    MeshManager* mshManager;
    GLuint index;

    void createObj();
    void compileShaders();

public:


    Scene();
    ~Scene();
    void drawObj();
    void updatePositionObj();
    void addObj(bool plant = false);
    void delObj();
    void moveObj(glm::vec3 position);
    void rotObj(float rotateX);

    void updateLight(Light* light);
    Camera* getCamera();
    Light* getLight(int i);
    MeshManager* getObjMan();
};


#endif //PROJEKT_FINAL_SCENE_H
