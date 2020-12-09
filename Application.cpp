#include "Application.h"
#include "Scene.h"

Application* Application::objectInstance = NULL;
int Application::width = 800;
int Application::height = 600;
std::string Application::title = "ZPG";

Application* Application::getWindow() {
	if (Application::objectInstance == NULL)
		return Application::objectInstance = new Application(Application::width, Application::height, Application::title.c_str());
	return Application::objectInstance;
}

Application::Application(int width, int height, const char* title) {
	if (!glfwInit()) {
		fprintf(stderr, "ERROR: could not start GLFW3\n");
		exit(EXIT_FAILURE);
	}

	// nutne udelat downgrade macbook
    this->setVerGL();

    window = glfwCreateWindow(width, height, title, NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);
	
	glfwSetErrorCallback(controller->error_callback);

	// start GLEW extension handler
	glewExperimental = GL_TRUE;
	glewInit();
	glEnable(GL_DEPTH_TEST); 

	int fwidth = 800, fheight = 600;
	float ratio = fwidth / (float)fheight;
	glViewport(0, 0, fwidth, fheight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);

	GL_CHECK_ERRORS();
	glGetError();
	scene = new Scene;
	controller->setController(window);
    getVerGL();
}


Application::~Application() {
	delete scene;
	glfwDestroyWindow(window);
	glfwTerminate();
}


void Application::mainloop() {

	glEnable(GL_DEPTH_TEST);
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		scene->drawObj();
		glfwPollEvents();
		glfwSwapBuffers(window);
	}
}


void Application::KeysClicked(int key) {
	switch (key)
	{
		case GLFW_KEY_Q:
			scene->getCamera()->moveUp();
			break;
		case GLFW_KEY_E:
			scene->getCamera()->moveDown();
			break;
		case GLFW_KEY_W:
			scene->getCamera()->moveForward();
			break;
		case GLFW_KEY_S:
			scene->getCamera()->moveBack();
			break;
        case GLFW_KEY_D:
			scene->getCamera()->moveLeft();
            break;
        case GLFW_KEY_A:
			scene->getCamera()->moveRight();
            break;
        case GLFW_KEY_K:
			scene->getLight()->move(glm::vec3(0.0f, -0.5f, 0.0f));
            break;
        case GLFW_KEY_I:
			scene->getLight()->move(glm::vec3(0.0f, 0.5f, 0.0f));
            break;
        case GLFW_KEY_J:
			scene->getLight()->move(glm::vec3(-0.5f, 0.0f, 0.0f));
            break;
        case GLFW_KEY_L:
			scene->getLight()->move(glm::vec3(0.5f, 0.0f, 0.0f));
            break;
        case GLFW_KEY_U:
			scene->getLight()->move(glm::vec3(0.0f, 0.0f, 0.5f));
            break;
        case GLFW_KEY_O:
			scene->getLight()->move(glm::vec3(0.0f, 0.0f, -0.5f));
            break;
	}
}
void Application::setVerGL() {

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void Application::getVerGL() {
	// get version info
	printf("OpenGL Version: %s\n", glGetString(GL_VERSION));
	printf("Using GLEW %s\n", glewGetString(GLEW_VERSION));
	printf("Vendor %s\n", glGetString(GL_VENDOR));
	printf("Renderer %s\n", glGetString(GL_RENDERER));
	printf("GLSL %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));
	int major, minor, revision;
	glfwGetVersion(&major, &minor, &revision);
	printf("Using GLFW %i.%i.%i\n", major, minor, revision);
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	float ratio = width / (float)height;
	glViewport(0, 0, width, height);
}

Scene* Application::getScene() {
	return scene;
}