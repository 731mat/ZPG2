//
// Created by Matěj Hloušek on 28/12/2020.
//

#ifndef PROJEKT_FINAL_BEZIERCURVE_H
#define PROJEKT_FINAL_BEZIERCURVE_H
#include <vector>
#include <glm/vec2.hpp> // glm::vec3
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr


class BezierCurve {
private:
    glm::vec3 v1, v2, v3, v4;

public:

    BezierCurve(glm::vec3 v1, glm::vec3 v2, glm::vec3 v3, glm::vec3 v4);
    glm::vec3 getPoint(float t);
};


#endif //PROJEKT_FINAL_BEZIERCURVE_H
