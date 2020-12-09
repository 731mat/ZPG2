//
// Created by Matěj Hloušek on 16.10.20.
//

#ifndef PROJEKT_FINAL_ONCHANGECAMERASUBJECT_H
#define PROJEKT_FINAL_ONCHANGECAMERASUBJECT_H


#include <glm/mat4x4.hpp> // glm::mat4
#include "OnChangeCameraObserver.h"
#include <list>
#include <iostream>
class OnChangeCameraSubject {

public:
    virtual void registerObserver(OnChangeCameraObserver* observer) = 0;
    virtual void removeObserver(OnChangeCameraObserver* observer) = 0;
    virtual void notifyObserver() = 0;

protected:
    std::list<OnChangeCameraObserver*> camsObservers;

};


#endif //PROJEKT_FINAL_ONCHANGECAMERASUBJECT_H
