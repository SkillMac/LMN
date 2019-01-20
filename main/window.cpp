#include "window.h"
#include "draw.h"

Dialog *Dialog::instance = NULL;
static Draw *draw = Draw::get_instance();

Dialog *Dialog::get_singleton()
{
	if (!instance) {
		instance = new Dialog();
	}
	return instance;
}

void Dialog::init()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, LMN_GLFW_OPENGL_MAJOR);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, LMN_GLFW_OPENGL_MINOR);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
}

void framebuffer_size_callback(GLFWwindow * window, int width, int height)
{
	draw->change_frame(width,height);
}

void Dialog::processInput()
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

void Dialog::setup(const std::string title, int width, int height)
{
	window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);

	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
	}
	glfwMakeContextCurrent(window);

	draw->set_glad_gl_loader();

	draw->change_frame(width,height);

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	while (!glfwWindowShouldClose(window))
	{
		processInput();

		draw->run();
		draw->run_end();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
}

Dialog::~Dialog()
{
	delete instance;
}
