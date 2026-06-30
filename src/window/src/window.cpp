#include "../include/window.h"
#include <GL/glext.h>
#include <GLFW/glfw3.h>
#include <cstddef>

Window::Window(unsigned int width, unsigned int height, const std::string &tital){
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    this->window = glfwCreateWindow(width, height, tital.c_str(), NULL, NULL);
}

Window::~Window(){
    glfwTerminate();
}

void Window::open(){

}
