#include <iostream>

#include "glad/glad.h"
#include <GLFW/glfw3.h>

void initWindow();
void setup();
void framebuffer_size_callback(GLFWwindow*, int, int);
void processInput(GLFWwindow*);

int main() {
    std::cout << "hello world" << std::endl;
    initWindow();
    setup();
    return 0;
}

void initWindow()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0,0,width,height);
}

void processInput(GLFWwindow* window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_TRUE)
    {
        glfwSetWindowShouldClose(window, true);
    }
}

void setup()
{
    GLFWwindow* window = glfwCreateWindow(1280,720, "Vker", NULL, NULL);
    if(window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
    }
    glfwMakeContextCurrent(window);
    if(gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Init glad failed" << std::endl;
    }
    glViewport(0,0,1280,720);
    
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    
    while(!glfwWindowShouldClose(window))
    {
        processInput(window);
        
        glClearColor(0.2f,0.3f,0.3f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glfwDestroyWindow(window);
    glfwTerminate();
}
