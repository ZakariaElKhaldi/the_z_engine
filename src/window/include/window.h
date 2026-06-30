#pragma once
#include <GLFW/glfw3.h>
#include <string>

class Window{
    private:
        GLFWwindow* window;
        unsigned int width;
        unsigned int height;

    public:
       Window(unsigned int width, unsigned int height, const std::string &tital);
       ~Window();
       void open();
       void close();
       auto handEvent();
};
