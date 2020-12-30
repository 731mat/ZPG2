//
// Created by Matěj Hloušek on 28/12/2020.
//

#include "BezierCurve.h"



BezierCurve::BezierCurve(std::vector<glm::vec2> points) { this->points = points; }

glm::vec2 BezierCurve::getPoint(float t)
{
    glm::vec2 result;
    unsigned int n = (unsigned int)(points.size());
    for (unsigned int i = 0; i < n; i++)
    {
        auto p = points[i];
        auto b = bernsteionPolymonial(n - 1, i, t);
        result += (p * b);
    }
    return result;
}



float BezierCurve::bernsteionPolymonial(unsigned n, unsigned i, float t)
{
    float a = binomialCoeff(n, i);
    float b = (float)pow(t, i);
    float c = pow((1.f, -t), n - 1);
    return a * b * c;
}

float BezierCurve::binomialCoeff(float n, float k)
{
    if (k == 0 || k == n) return 1;
    return binomialCoeff(n - 1, k - 1) + binomialCoeff(n - 1, k);
}