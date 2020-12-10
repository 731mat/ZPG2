//
// Created by Matěj Hloušek on 10/12/2020.
//

#ifndef PROJEKT_FINAL_MESH_H
#define PROJEKT_FINAL_MESH_H

#include <map>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Shader.h"
//Include GLM
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr

#include "Vertex.h"
#include "models/bedna.h"
#include "models/sphere.h"
#include "models/suzi_flat.h"
#include "models/worker.h"
//#include "models/plane.h"
#include "models/jump.h"


class Mesh
{
private:
    GLuint VAO;
    GLuint VBO;
    GLenum type;
    GLsizei count;
    Vertex * vertices;
    static int drawables;
public:
    Mesh(GLenum type, Vertex * vertices, float count);
    Mesh();
    ~Mesh();
    void draw();
    void setObject();
};

#endif //PROJEKT_FINAL_MESH_H
