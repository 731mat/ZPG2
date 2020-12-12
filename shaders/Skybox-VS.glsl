#version 400

in vec3 in_Position;


uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;
out vec3 texCoord;


void main () 
{
  gl_Position =  projectionMatrix *  viewMatrix * vec4 (in_Position, 1.0);
  texCoord = in_Position;
}
