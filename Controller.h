#ifndef PROJEKT_FINAL_CONTROLLER_H
#define PROJEKT_FINAL_CONTROLLER_H
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Camera.h"
class Controller {
private:
	//static Application app;
public:
	Controller();
	~Controller();
	void setController(GLFWwindow* window);
	static void error_callback(int error, const char* description);
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void window_focus_callback(GLFWwindow* window, int focused);
	static void window_iconify_callback(GLFWwindow* window, int iconified);
	static void window_size_callback(GLFWwindow* window, int width, int height);
	static void cursor_callback(GLFWwindow *window, double x, double y);
	static void button_callback(GLFWwindow* window, int button, int action, int mode);

};
#endif //PROJEKT_FINAL_CONTROLLER_H