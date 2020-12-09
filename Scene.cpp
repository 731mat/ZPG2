//
// Created by Matěj Hloušek on 09/12/2020.
//
#include "Scene.h"



Scene::Scene() {
    compileShaders();
    camera = new Camera;
    light = new Light(lambert);
    light2 = new Light(20, 0, -50);
    lights.push_back(light);
    lights.push_back(light2);

    phong->updateLights(lights);

    light2->registerObserver((OnChangeLightObserver*)phong);
    light->registerObserver((OnChangeLightObserver*)phong);

    camera->registerObserver((OnChangeCameraObserver*)lambert);
    camera->registerObserver((OnChangeCameraObserver*)phong);

    objects.push_back(new Object(phong, glm::vec3(0, 2, 0), glm::vec3(1, 1, 1)));
    objects.push_back(new Object(phong, glm::vec3(0, -2, 0), glm::vec3(1, 1, 1)));
    objects.push_back(new Object(phong, glm::vec3(-2, 0, 0), glm::vec3(1, 1, 1)));
    objects.push_back(new Object(phong, glm::vec3(2, 0, 0), glm::vec3(1, 1, 1)));

    camera->notifyObserver();
    light->notifyObserver();

}

Scene::~Scene() {

    delete light;
    delete camera;
    for (unsigned int i = 0; i < objects.size(); i++)
        delete objects[i];
}


void Scene::compileShaders() {

    lambert = new Shader("../shaders/Lambert-VS.glsl", "../shaders/Lambert-FS.glsl");
    phong = new Shader("../shaders/Phong-VS.glsl", "../shaders/Phong-FS.glsl");

}

void Scene::drawObj() {
    glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    light->draw();
    updateLight(light);
    for (unsigned int i = 0; i < objects.size(); i++){
        glStencilFunc(GL_ALWAYS, i+1, 0xFF);
        objects[i]->draw();
    }
}


void Scene::addObj(double x, double y) {
    int width = 600, height = 800;
    GLbyte color[4];
    GLfloat depth;
    GLuint index;
    int newy = (int)height-y;

    glReadPixels(x, newy, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, color);
    glReadPixels(x, newy, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &depth);
    glReadPixels(x, newy, 1, 1, GL_STENCIL_INDEX, GL_UNSIGNED_INT, &index);
    printf("Clicked on pixel %d, %d, color % 02hhx % 02hhx % 02hhx % 02hhx, depth %f, stencil index %u\n", x, y, color[0], color[1], color[2], color[3], depth, index);

    glm::vec3 screenX = glm::vec3(x, newy, depth);
    glm::mat4 view = getCamera()->getCamera();
    glm::mat4 projection = getCamera()->getProjection();
    glm::vec4 viewPort = glm::vec4(0, 0, height, width);
    glm::vec3 pos = glm::unProject(screenX, view, projection, viewPort);
    objects.push_back(new Object(phong, glm::vec3(pos.x, pos.y, pos.z), glm::vec3(1, 1, 1)));
    printf("unProject[%f, %f, %f]\n", pos.x, pos.y, pos.z);
}



void Scene::updateLight(Light* light) {
    phong->updateLights(lights);
}
Camera* Scene::getCamera() {
    return camera;
}

Light* Scene::getLight() {
    return light;
}