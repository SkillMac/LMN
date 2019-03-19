#include "window.h"
#include "draw.h"

Dialog *Dialog::instance = new Dialog();

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
    
#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
}

void framebuffer_size_callback(GLFWwindow * window, int width, int height)
{
	Draw::get_instance()->change_frame(width,height);
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

	Draw::get_instance()->set_glad_gl_loader();

	Draw::get_instance()->change_frame(width,height);

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    
    Draw* draw = Draw::get_instance();

	while (!glfwWindowShouldClose(window))
	{
		processInput();
        
        draw->run_start();
		draw->run();
		draw->run_end();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	draw->end();
    glfwDestroyWindow(window);
	glfwTerminate();
}

Dialog::~Dialog()
{
	delete instance;
}
