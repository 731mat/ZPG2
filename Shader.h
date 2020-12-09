#ifndef PROJEKT_FINAL_SHADER_H
#define PROJEKT_FINAL_SHADER_H

#include "ShaderLoader.h"
#include "glm/vec3.hpp" // glm::vec3
#include "glm/vec4.hpp" // glm::vec4
#include "glm/mat4x4.hpp" // glm::mat4
#include "glm/gtc/matrix_transform.hpp" // glm::translate, glm::rotate, glm::scale, glm::perspective
#include "glm/gtc/type_ptr.hpp" // glm::value_ptr

#include "Camera.h"
#include "opengl_helper.h"	// tohle je helper soubor na kontrolu chyb
#include <vector>

class Shader : public ShaderLoader, OnChangeCameraObserver, OnChangeLightObserver {

private:
	GLuint programID;
	GLuint matrixID;	//GLuint viewMatrixID;

	GLuint viewMatrixID;
	GLuint projectMatrixID;
	GLuint lightPositionID;
	GLuint viewPositionID;

public:
	Shader(const char *vertexFile, const char *fragmentFile);
	~Shader();
	void setShader();

	GLint getShader();
	void shaderRotate(float rotationx);
	void setModelMatrix(glm::mat4 matrix);
	void updateCamera(Camera* camera);
	void updateLight(Light* light);
	void updateLights(std::vector<Light*> lights);

	GLuint getID() { return this->programID;  }
};
#endif //PROJEKT_FINAL_SHADER_H