#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <ImGui/imgui.h>
#include <ImGui/imgui_impl_win32.h>
#include <ImGui/imgui_impl_opengl2.h>
#include <ImGui/imgui_internal.h>

// Render class, based on ImGui
class Renderer
{
public:
    Renderer() = default;
    ~Renderer();

    static void Initialize_ImGui();

    void Render_ImGui_menu();
    void Render_ImGui_esp();
    
    static Renderer* Get()
    {
        return _instance;
    }
    
private:
    static Renderer* _instance;
};

#endif