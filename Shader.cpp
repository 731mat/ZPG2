#include "Shader.h"
//Include GLM  
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr



Shader::Shader(const char *vertexFile, const char *fragmentFile) {
	programID = loadShader(vertexFile, fragmentFile);
	glUseProgram(programID);
	matrixID = glGetUniformLocation(programID, "modelMatrix");

	viewMatrixID = glGetUniformLocation(programID, "viewMatrix");
	projectMatrixID = glGetUniformLocation(programID, "projectionMatrix");
	lightPositionID = glGetUniformLocation(programID, "lightArray");
	viewPositionID = glGetUniformLocation(programID, "viewPosition");

    lightObjectsID = glGetUniformLocation(programID, "lightObjects");

    glm::mat4 r = glm::mat4();
    glUniformMatrix4fv(matrixID, 1, GL_FALSE, &r[0][0]);
}

void Shader::setTexture(GLint tex)
{
	this->setShader();
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, tex);
	glUniform1i(this->getShader(), 0);
}


void Shader::setShader() {
    glUseProgram(programID);
}

Shader::~Shader() {
	this->deleteShader();
}

GLint Shader::getShader() {
	return programID;
}

void Shader::updateCamera(Camera* camera) {
	setShader();
	//printf("update camera\n");

	glm::vec3 cam = camera->getEye();
	glUniformMatrix4fv(viewMatrixID, 1, GL_FALSE, &camera->getView()[0][0]);
	glUniformMatrix4fv(projectMatrixID, 1, GL_FALSE, &camera->getProjection()[0][0]);
	//printf("%f, %f, %f\n", camera->getPosX(),camera->getPosY(), camera->getPosZ());

	glUniform3f(viewPositionID,cam.x, cam.y, cam.z);
}

void Shader::updateLight(Light* light) {
	light->draw();
	setShader();
	glm::vec3 lig = light->getPosition();
	//glUniform3f(lightPositionID, lig.x, lig.y, lig.z);
	//send("lightObjects[0].position", lig);
	//send("lightArray", lig);

	//printf("LIGHT [%f,%f,%f] \n", lig.x, lig.y, lig.z);
}
void Shader::updateLights(std::vector<Light*> lights){
	glm::vec3 position[5];
	for (unsigned int i = 0; i < lights.size(); i++) {
		position[i] = lights[i]->getPosition();
		this->send(("lightObjects["+std::to_string(i)+ "].position").c_str(), lights[i]->getPosition());
		this->send(("lightObjects["+std::to_string(i)+ "].lightType").c_str(), (int)lights[i]->getType());
		this->send(("lightObjects["+std::to_string(i)+ "].direction").c_str(), lights[i]->getPositionDirection());
		this->send(("lightObjects["+std::to_string(i)+ "].cutOff").c_str(), glm::cos(glm::radians(12.5f)));
		this->send(("lightObjects["+std::to_string(i)+ "].outerCutOff").c_str(), glm::cos(glm::radians(17.5f)));
	}

    this->send("light_count", (int)(lights.size()));

    //glUniform3fv(lightPositionID, lights.size(), &position[0][0]);
}



void Shader::setModelMatrix(glm::mat4 matrix) {
	setShader();
	glUniformMatrix4fv(matrixID, 1, GL_FALSE, &matrix[0][0]);
}

void Shader::send(const GLchar * name,glm::mat4 value)
{
    GLint location = glGetUniformLocation(programID, name);
    glUniformMatrix4fv(location, 1, GL_FALSE, value_ptr(value));
}

void Shader::send(const GLchar * name, glm::vec3 value)
{
	GLint location = glGetUniformLocation(programID, name);
	setShader();
	glUniform3fv(location, 1, value_ptr(value));
}

void Shader::send(const GLchar * name, int value)
{
	GLint location = glGetUniformLocation(programID, name);
	setShader();
	glUniform1i(location, value);
}

void Shader::send(const GLchar * name, float value)
{
	GLint location = glGetUniformLocation(programID, name);
	setShader();
	glUniform1f(location, value);
}







