//
// Created by Matěj Hloušek on 16.10.20.
//

#ifndef PROJEKT_FINAL_ONCHANGECAMERAOBSERVER_H
#define PROJEKT_FINAL_ONCHANGECAMERAOBSERVER_H

#include <glm/mat4x4.hpp> // glm::mat4
class Camera;
class OnChangeCameraObserver{

public:

    virtual void updateCamera(Camera* camera) = 0;
};

#endif //PROJEKT_FINAL_ONCHANGECAMERAOBSERVER_H
