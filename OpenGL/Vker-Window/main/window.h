#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "define_type.h"


void framebuffer_size_callback(GLFWwindow *window, int width, int height);


class Dialog {
	static Dialog *instance;
	GLFWwindow *window;

private:
	void processInput();
public:
	static Dialog *get_singleton();
	void init();
	void setup(const std::string title, int width, int height);
	~Dialog();
};

#endif

