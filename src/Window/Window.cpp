#include "Window.hpp"
#include "iostream"

Window* Window::_instance = nullptr;

Window::Window(const char* window_title) 
    : _title(window_title)
{
    if (!_instance)
    {
        _instance = this;
    }

    this->_hwnd = FindWindow(nullptr, this->_title);
    if (this->_hwnd == NULL)
    {
        std::runtime_error("[Window] FindWindow failed");
    }
}

Window::~Window()
{}
