#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <Windows.h>

class Window
{
public:
    Window(const char* window_title);
    ~Window();

    [[nodiscard]] auto GetHWND() const 
    {
        return this->_hwnd;
    }

    [[nodiscard]] auto GetWindowTitle() const 
    {
        return this->_title;
    }

    static Window* Get()
    {
        return _instance;
    }
private:
    static Window* _instance;

    const char* _title;

    HWND _hwnd;
};

#endif