#version 330
layout(location = 0) in vec3 position;
layout(location = 1) in vec3 normal;

out vec3 worldPosition;
out vec3 worldNormal;

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;


void main()
{
    gl_Position = (projectionMatrix * viewMatrix * modelMatrix) * vec4(position, 1.0f);

    worldPosition = vec3(modelMatrix * vec4(position, 1.0));
    mat3 m = transpose(inverse(mat3(modelMatrix)));
    worldNormal = normalize(m * normal);
}