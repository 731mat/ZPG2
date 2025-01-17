#version 330

layout(location = 0)in vec3 in_Position;
layout(location = 1)in vec3 normal;
layout(location = 2)in vec2 inTexCoord;

out vec4 ex_worldPosition;
out vec3 ex_worldNormal;

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;
uniform mat4 normalMatrix; 

void main () {

  //gl_Position = vec4(in_Position, 1.0f);
  gl_Position = ( projectionMatrix *  viewMatrix * modelMatrix ) * vec4 (in_Position, 1.0);
  //ex_worldPosition = modelMatrix * vec4(in_Position, 1.0);
  //ex_worldNormal = vec3((modelMatrix)*vec4(normal, 1.0));
  ex_worldPosition = modelMatrix * vec4(in_Position, 1.0);
  ex_worldNormal = normal;
  //ex_worldNormal = mat3(transpose(inverse(modelMatrix))) * normal;
}
