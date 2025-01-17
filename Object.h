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
#include "Mesh.h"
#include "Model.h"
#include "Texture.h"
#include "BezierCurve.h"

class Shader;
class Mesh;
class Model;
class Texture;

class Object {
private:
	glm::mat4 model;
	Mesh* mesh;
	Model* objModel;
	Shader* shader;
	Texture* texture;
    BezierCurve *curve = nullptr;

	float curve_t = 0;
	bool curve_forward = true;


public:
	Object(Mesh* mesh, Shader* shader, glm::vec3 setPosition, glm::vec3 setScale);
	Object(Mesh* mesh, Shader* shader,Texture* tex, glm::vec3 setPosition, glm::vec3 setScale);
	Object(Model* objModel, Shader* shader, glm::vec3 setPosition, glm::vec3 setScale);
	Object(Model* objModel, Shader* shader, Texture *tex, glm::vec3 setPosition, glm::vec3 setScale);
	~Object();
	void setPosition(glm::vec3 position);
	void rotate(float rotateX);
	void draw();
	void move();
	void setCurve(BezierCurve *curve);
};
#endif //PROJEKT_FINAL_OBJECT_H