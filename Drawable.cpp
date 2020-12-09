#include "Drawable.h"
#include "Application.h"
//#include "models/worker.h"
//#include "models/bedna.h"
//#include "models/suzi_smooth.h"
#include "models/sphere.h"

int Drawable::drawables = 0;

Drawable::Drawable(Shader* shader, glm::vec3 setPosition, glm::vec3 setScale) {
	VAO = drawables;
	VBO = drawables;
	this->shader = shader;

	drawables++;
	model = glm::mat4(1.0f);
	renderObject();

	model = glm::scale(model, setScale);
	model = glm::translate(model, setPosition);
}
Drawable::~Drawable() {
	delete this;
}


void Drawable::draw() {
	this->shader->setModelMatrix(model);

	glBindVertexArray(VAO);
	// draw triangles
	glDrawArrays(GL_TRIANGLES, 0, (GLsizei)pocetPrvku); //mode,first,count
	glBindVertexArray(VAO);
}
void Drawable::setPosition(glm::vec3 position) {
	this->model = glm::translate(model, position);
}

void Drawable::renderObject() {

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
