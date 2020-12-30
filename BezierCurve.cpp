//
// Created by Matěj Hloušek on 28/12/2020.
//

#include "BezierCurve.h"

BezierCurve::BezierCurve(glm::vec3 v1, glm::vec3 v2, glm::vec3 v3, glm::vec3 v4)
{
    this->v1 = v1;
    this->v2 = v2;
    this->v3 = v3;
    this->v4 = v4;
}

glm::vec3 BezierCurve::getPoint(float t)
{
    glm::vec3 p1 = v1 * std::pow(1-t, 3.f);
    glm::vec3 p2 = v2 * (3*t * std::pow(1-t, 2.f));
    glm::vec3 p3 = v3 * (3*t*t * (1-t));
    glm::vec3 p4 = v4 * (t*t*t);
    return p1 + p2 + p3 + p4;
}


