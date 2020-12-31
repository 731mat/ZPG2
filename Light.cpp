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

Light::Light(float x, float y, float z, LightType typ) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->type = typ;
}

Light::~Light() {}

glm::vec3 Light::getPosition() {
	if(isOff) return glm::vec3(0, 0, 0);
	return glm::vec3(x, y, z);
}

glm::vec3 Light::getPositionDirection() {
	if(isOff) return glm::vec3(0, 0, 0);
	return direction;
}

void Light::setPositionSource(glm::vec3 v) {
    this->x = v.x;
    this->y = v.y;
    this->z = v.z;
}

void Light::setPositionDirection(glm::vec3 v) {
    this->direction = normalize(v);
}


void Light::draw() {
	if(!isOff) objLig->draw();
}

void Light::setPosition(glm::vec3 vector){
    this->x = vector.x;
    this->y = vector.y;
    this->z = vector.z;
	if(objLig != nullptr) objLig->setPosition(vector);
    notifyObserver();
}
void Light::move(glm::vec3 vector)
{
	this->x += vector.x;
	this->y += vector.y;
	this->z += vector.z;
	if(objLig != nullptr) objLig->setPosition(vector);
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






