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
    std::vector<glm::vec2> points;
    float bernsteionPolymonial(unsigned int n, unsigned int i, float t);
    float binomialCoeff(float n, float k);
public:
    BezierCurve(std::vector<glm::vec2> points);
    glm::vec2 getPoint(float t);
};


#endif //PROJEKT_FINAL_BEZIERCURVE_H
