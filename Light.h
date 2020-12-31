#ifndef PROJEKT_FINAL_LIGHT_H
#define PROJEKT_FINAL_LIGHT_H
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include "OnChangeLightSubject.h"
#include "MeshManager.h"
#include "Drawable.h"



enum class LightType {
	Point = 1,
	Directional = 2,
	Spotlight = 3
};


class Object;
class Shader;
class MeshManager;
class Light : public OnChangeLightSubject,Drawable {
private:
	LightType type;
	float x, y, z;
    glm::vec3 direction = glm::vec3( 0, 0, -1);
	Object* objLig = nullptr;
	bool isOff = false;
public:

	Light(Shader* shader, MeshManager* mshManager,LightType typ);
	Light(float x, float y, float z);
	Light(float x, float y, float z,LightType typ);
	~Light();
	glm::vec3 getPosition();
	glm::vec3 getPositionDirection();
	void setPositionSource(glm::vec3 v);
    void setPositionDirection(glm::vec3 v);

	LightType getType();

	void draw();
	void move(glm::vec3 moveVec);
	void setPosition(glm::vec3 moveVec);
	void registerObserver(OnChangeLightObserver* observer);
	void removeObserver(OnChangeLightObserver* observer);
	void notifyObserver();

	void disable() { isOff = true; }
	void enable() { isOff = false; }
	bool isOn() { return !isOff; }

};
#endif //PROJEKT_FINAL_LIGHT_H