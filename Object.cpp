#include "Object.h"
#include "Application.h"
//#include "models/worker.h"
//#include "models/bedna.h"
//#include "models/suzi_smooth.h"
#include "models/sphere.h"

int Object::objects = 0;

Object::Object(Shader* shader, glm::vec3 setPosition, glm::vec3 setScale) {
	VAO = objects;
	VBO = objects;
	this->shader = shader;

	objects++;
	model = glm::mat4(1.0f);
	renderObject();

	model = glm::scale(model, setScale);
	model = glm::translate(model, setPosition);
}
Object::~Object() {
	delete this;
}


GLint Object::getID() {
    return shader->getID();
}

void Object::draw() {
	this->shader->setModelMatrix(model);

	glBindVertexArray(VAO);
	// draw triangles
	glDrawArrays(GL_TRIANGLES, 0, (GLsizei)pocetPrvku); //mode,first,count
	glBindVertexArray(VAO);
}
void Object::setPosition(glm::vec3 position) {
	this->model = glm::translate(model, position);
}

void Object::renderObject() {

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glGenBuffers(1, &VBO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertices[0]), static_cast<GLvoid*>(nullptr));
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(vertices[0]), reinterpret_cast<GLvoid*>(sizeof(vertices[0].Position)));
	glBindVertexArray(0);


}
