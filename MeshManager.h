//
// Created by Matěj Hloušek on 10/12/2020.
//

#ifndef PROJEKT_FINAL_OBJECTMANAGER_H
#define PROJEKT_FINAL_OBJECTMANAGER_H


#include <map>
#include "Object.h"
#include "Mesh.h"
#include "Model.h"

class Model;
class MeshManager
{
private:
    std::map< std::string, Mesh> models;
    std::map< std::string, Model> objModels;
public:
    Mesh* getMesh(std::string name);
    void setMesh(std::string name, Mesh* mesh);
    Model* getObj(std::string name);
    void setObj(std::string name, Model* model);
    MeshManager();
    ~MeshManager();
};


#endif //PROJEKT_FINAL_OBJECTMANAGER_H
