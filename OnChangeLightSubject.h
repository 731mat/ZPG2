//
// Created by Matěj Hloušek on 16.10.20.
//

#ifndef PROJEKT_FINAL_ONCHANGELIGHTSUBJECT_H
#define PROJEKT_FINAL_ONCHANGELIGHTSUBJECT_H


#include <glm/mat4x4.hpp> // glm::mat4
#include "OnChangeLightObserver.h"
#include <list>
#include <iostream>
class OnChangeLightSubject {

public:
    virtual void registerObserver(OnChangeLightObserver* observer) = 0;
    virtual void removeObserver(OnChangeLightObserver* observer) = 0;
    virtual void notifyObserver() = 0;

protected:
    std::list<OnChangeLightObserver*> lightObservers;

};


#endif //PROJEKT_FINAL_ONCHANGELIGHTSUBJECT_H
