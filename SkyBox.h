//
// Created by Matěj Hloušek on 11/12/2020.
//

#ifndef PROJEKT_FINAL_SKYBOX_H
#define PROJEKT_FINAL_SKYBOX_H

#include <string>
#include <GL/glew.h>
#include <vector>
#include "Shader.h"
#include "OnChangeCameraObserver.h"



class SkyBox :public OnChangeCameraObserver {

private:
    std::string sDirectory;
    Shader* shader;
    GLuint skyboxVAO, skyboxVBO;
    glm::mat4 viewMat, projectionMat;


    unsigned int cubemapTexture;

public:
    SkyBox(Shader* shader);

    ~SkyBox();
    unsigned int loadCubemap(vector<std::string> faces);

    void drawSkybox();
    void updateCamera(Camera* camera);

};


#endif //PROJEKT_FINAL_SKYBOX_H
