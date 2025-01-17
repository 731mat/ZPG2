#include "Camera.h"

#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr
#include <glm/gtx/rotate_vector.hpp>
#include <list>

Camera::Camera() {


	//position
	eye = glm::vec3(0.f, 0.f, 20);
	//direction
	center = glm::vec3(0, 0, -1.f);
	//idk exactly
	UP = glm::vec3(0.f, 1.f, 0.f);

	curX = 0;
	curY = 0;
}
Camera::~Camera() {

}


glm::vec3 Camera::getEye() {
	return eye;
}
glm::vec3 Camera::getCenter(){
    return center;
}

float Camera::getPosX() {
	return eye.x;
}
float Camera::getPosY() {
	return eye.y;
}
float Camera::getPosZ() {
	return eye.z;
}

glm::mat4 Camera::getProjection(){
	return glm::perspective(45.f, 4.0f / 3.0f, 0.1f, 100.0f);
}

 glm::mat4 Camera::getView(void){
	 return glm::lookAt(eye, eye + center, UP);
 }

 void Camera::registerObserver(OnChangeCameraObserver* observer) {
	 camsObservers.push_back(observer);
	 printf("camera - Registrovano\n");
 }
 void Camera::removeObserver(OnChangeCameraObserver* observer){
	 camsObservers.remove(observer);
	 printf("Odstraneno");
 }
 void Camera::notifyObserver() {
	 std::list<OnChangeCameraObserver*>::iterator pos = this->camsObservers.begin();
	 while (pos != this->camsObservers.end())
	 {
		 ((OnChangeCameraObserver*)(*pos))->updateCamera(this);
		 ++pos;
	 }

 }

void Camera::lookAt(glm::vec3 center, glm::vec3 UP){
	this->center = center;
	this->UP = UP;
}


 void Camera::moveForward() {
	 eye += center * 0.3f;
	 notifyObserver();
 }

 void Camera::moveBack() {
	 eye -= center * 0.3f;
	 notifyObserver();
 }

 void Camera::moveRight() {
	 eye -= 0.3f * glm::normalize(glm::cross(center, UP));
	 notifyObserver();
 }

 void Camera::moveLeft() {
	 eye += 0.3f * glm::normalize(glm::cross(center, UP));
	 notifyObserver();
 }

 void Camera::moveUp() {
	 center -= 0.030f * UP;
	 notifyObserver();
 }

 void Camera::moveDown() {
	 center += 0.030f * UP;
	 notifyObserver();
 }

void Camera::cursorCallback(float x, float y) {
	if (curX == 0)
		curX = x;
	if (curY == 0)
		curY = y;

	float dx = -(x - curX) / 100.0;
	float dy = -(y - curY) / 100.0;

	center = glm::rotateX(glm::normalize(this->center), dy);
	center = rotateY(center, dx);
	center = rotateX(center, dy);
	UP = rotateY(UP, dx);
	lookAt(center, UP);
	//printf("%f, %f\n", dx, dy);
	curX = x;
	curY = y;
	notifyObserver();
}