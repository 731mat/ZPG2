//
// Created by Matěj Hloušek on 10/12/2020.
//

#ifndef PROJEKT_FINAL_OBJECTMANAGER_H
#define PROJEKT_FINAL_OBJECTMANAGER_H


#include <map>
#include "Object.h"
#include "Mesh.h"


class ObjectManager
{
private:
    std::map< std::string, Mesh> models;
public:
    Mesh* getMesh(std::string name);
    void setMesh(std::string name, Mesh* mesh);
    ObjectManager();
    ~ObjectManager();
};


#endif //PROJEKT_FINAL_OBJECTMANAGER_H
