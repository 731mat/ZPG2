#ifndef PROJEKT_FINAL_OBJECT_H
#define PROJEKT_FINAL_OBJECT_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

//Include GLM
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr
#include "Shader.h"


class Object {
private:
	glm::mat4 model;
	Shader* shader;
	static int objects;
	GLuint VAO;
	GLuint VBO;

public:
	Object(Shader* shader, glm::vec3 setPosition, glm::vec3 setScale);
	~Object();
	void setPosition(glm::vec3 position);
	void draw();
	void renderObject();
	GLint getID();
};
#endif //PROJEKT_FINAL_OBJECT_H