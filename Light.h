#ifndef PROJEKT_FINAL_LIGHT_H
#define PROJEKT_FINAL_LIGHT_H
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include "OnChangeLightSubject.h"
//#include "Object.h"

class Object;
class Shader;
class Light : public OnChangeLightSubject {
private:
	float x, y, z;
	Object* objLig;
public:
	Light(Shader* shader);
	Light(float x, float y, float z);
	~Light();
	glm::vec3 getPosition();
	glm::vec3 getPositionDirection();
	void draw();
	void move(glm::vec3 moveVec);
	void registerObserver(OnChangeLightObserver* observer);
	void removeObserver(OnChangeLightObserver* observer);
	void notifyObserver();
};
#endif //PROJEKT_FINAL_LIGHT_H