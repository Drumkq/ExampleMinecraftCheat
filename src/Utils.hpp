#ifndef UTILS_HPP
#define UTILS_HPP

#include "Window/Window.hpp"

#include <Windows.h>

namespace Utils
{
    struct Vector3D
    {
        Vector3D(float x, float y, float z)
            : x(x), y(y), z(z)
        {}

        float x, y, z;
    };

    inline HMODULE get_module_handle(const char* dll)
    {
        return GetModuleHandle(dll);
    }

    inline FARPROC get_address(const char* dll, const char* function)
    {
        return GetProcAddress(get_module_handle(dll), function);
    }
}

#endif