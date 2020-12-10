//
// Created by Matěj Hloušek on 10/12/2020.
//

#include "ObjectManager.h"

Mesh* ObjectManager::getMesh(std::string name)
{
    return &models[name];
}

void ObjectManager::setMesh(std::string name, Mesh* mesh)
{
    models[name] = *mesh;
}

ObjectManager::ObjectManager()
{
}

ObjectManager::~ObjectManager()
{
    delete this;
}

