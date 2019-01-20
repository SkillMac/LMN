#include <iostream>

#include "draw.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "log.h"

Draw *Draw::_instance = nullptr;

Draw *Draw::get_instance() {
    if(_instance == nullptr) {
        _instance = new Draw();
    }
    return _instance;
}

void Draw::init() {

}

void Draw::run() {

}

void Draw::run_end() {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Draw::end() {

}

void Draw::change_frame(int width, int height) {
    glViewport(0,0,width,height);
}

void Draw::set_glad_gl_loader() {
    if(gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        Log::error<std::string>("Failed to initialize GLAD");
    }
}