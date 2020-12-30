#include "Object.h"
#include "Application.h"




Object::Object(Mesh* mesh,Shader* shader, glm::vec3 setPosition, glm::vec3 setScale) {

	this->mesh = mesh;
	this->shader = shader;
	this->texture = nullptr;
	this->objModel = nullptr;

	model = glm::mat4(1.0f);
	model = glm::scale(model, setScale);
	model = glm::translate(model, setPosition);
}

Object::Object(Mesh *mesh, Shader *shader, Texture *tex, glm::vec3 setPosition, glm::vec3 setScale) {
    this->mesh = mesh;
    this->shader = shader;
    this->texture = tex;

    this->objModel = nullptr;

    model = glm::mat4(1.0f);
    model = glm::scale(model, setScale);
    model = glm::translate(model, setPosition);
}

Object::Object(Model* objModel, Shader* shader, Texture *tex, glm::vec3 setPosition, glm::vec3 setScale)
{
	this->shader = shader;
	this->objModel = objModel;
	this->texture = tex;

	this->mesh = nullptr;

	model = glm::mat4(1.0f);
	model = glm::scale(model, setScale);
	model = glm::translate(model, setPosition);
}


Object::Object(Model* objModel, Shader* shader, glm::vec3 setPosition, glm::vec3 setScale)
{
	this->shader = shader;
	this->objModel = objModel;
	this->texture = nullptr;

	this->mesh = nullptr;

	model = glm::mat4(1.0f);
	model = glm::scale(model, setScale);
	model = glm::translate(model, setPosition);
}

Object::~Object() {
	delete this;
}

void Object::draw() {

	this->shader->setModelMatrix(model);

	if(	this->texture != NULL){
		this->texture->bind(this->shader,"textura");
	} else
		this->texture->unbind();


	if (mesh != NULL)
		this->mesh->draw();
	if (objModel != NULL)
		this->objModel->draw();
}
void Object::setPosition(glm::vec3 position) {
	this->model = glm::translate(model, position);
}

void Object::rotate(float rotateX)
{
	this->model = glm::rotate(model, glm::radians(rotateX), glm::vec3(0.0f, 1.0f, 0.0f));
}

void Object::setCurve(BezierCurve *curve) {
	this->curve = curve;
}

void Object::move() {

	if(this->curve == nullptr) return;


	const float shift = 0.005f;

	model = glm::mat4(1.0f);
	model = glm::translate(model, curve->getPoint(curve_t));

	if (curve_forward)
	{
		curve_t += shift;
		if (curve_t > 1)
		{
			curve_t = 1;
			curve_forward = false;
		}
	}
	else
	{
		curve_t -= shift;
		if (curve_t < 0)
		{
			curve_t = 0;
			curve_forward = true;
		}
	}

}





