//
// Created by Matěj Hloušek on 16.10.20.
//

#ifndef PROJEKT_FINAL_ONCHANGELIGHTOBSERVER_H
#define PROJEKT_FINAL_ONCHANGELIGHTOBSERVER_H


#include <glm/mat4x4.hpp> // glm::mat4
class Light;
class OnChangeLightObserver{

public:
    virtual void updateLight(Light* light) = 0;
};

#endif //PROJEKT_FINAL_ONCHANGELIGHTOBSERVER_H
