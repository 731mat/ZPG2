//
// Created by Matěj Hloušek on 10/12/2020.
//

#ifndef PROJEKT_FINAL_VERTEX_H
#define PROJEKT_FINAL_VERTEX_H


typedef struct Vertex
{
    float Position[3];
    float Normal[3];
    float TextMap[2];
    float Texture[2];
    float Tangent[3];
} Vertex;


#endif //PROJEKT_FINAL_VERTEX_H
