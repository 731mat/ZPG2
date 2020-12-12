#include "Light.h"
#include "Application.h"

Light::Light(Shader* shader, MeshManager* mshManager,LightType type) {

	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
	objLig = new Object(mshManager->getMesh("sphere"), shader, getPosition(), glm::vec3(0.5, 0.5, 0.5));
	this->type = type;
}
Light::Light(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->type = LightType::Directional;
}

Light::~Light() {}

glm::vec3 Light::getPosition() {
	return glm::vec3(x, y, z);
}
glm::vec3 Light::getPositionDirection() {
	return glm::vec3( 2, 2, 2);
}
void Light::draw() {
	objLig->draw();

}

void Light::setPosition(glm::vec3 vector){
    this->x = vector.x;
    this->y = vector.y;
    this->z = vector.z;
    objLig->setPosition(vector);
    notifyObserver();
}
void Light::move(glm::vec3 vector)
{
	this->x += vector.x;
	this->y += vector.y;
	this->z += vector.z;
	objLig->setPosition(vector);
	notifyObserver();
}

void Light::registerObserver(OnChangeLightObserver* observer) {
	lightObservers.push_back(observer);
}
void Light::removeObserver(OnChangeLightObserver* observer) {
	lightObservers.remove(observer);
}
void Light::notifyObserver() {
	std::list<OnChangeLightObserver*>::iterator pos = this->lightObservers.begin();
	while (pos != this->lightObservers.end())
	{
		((OnChangeLightObserver*)(*pos))->updateLight(this);
		++pos;
	}
}

LightType Light::getType() {
	return this->type;
}
