#pragma once
#include <GLFW/glfw3.h>
#include <string>

enum class EventType{
    WINDOW_RESIZE,
    WINDOW_MOVED,
    WINDOW_FOCUS,
    WINDOW_MINIMIZED,
    KEY_PRESED
};

class WindowEvent{
    public:
        EventType getType() const;
};

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
       void swapBuffer();
       auto pollEvents();
};
