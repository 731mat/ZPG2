//
// Created by Matěj Hloušek on 11/12/2020.
//

#ifndef PROJEKT_FINAL_LIGHTMANAGER_H
#define PROJEKT_FINAL_LIGHTMANAGER_H

#include <vector>
#include "Light.h"

class LightManager {

private:
    std::vector<Light> lishts;
public:
    LightManager();
    ~LightManager();


};


#endif //PROJEKT_FINAL_LIGHTMANAGER_H
