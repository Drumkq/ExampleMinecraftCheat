#include "Renderer.hpp"
#include "../Window/Window.hpp"

#include <gl/GL.h>

Renderer* Renderer::_instance = nullptr;

Renderer::~Renderer() 
{
	ImGui_ImplWin32_Shutdown();
    ImGui_ImplOpenGL2_Shutdown();
	ImGui::DestroyContext();
}

void Renderer::Initialize_ImGui() 
{
    ImGui::CreateContext();
    ImGui_ImplWin32_Init(Window::Get()->GetHWND());
	ImGui_ImplOpenGL2_Init();
}

void Renderer::Render_ImGui_esp() 
{
    
}

void Renderer::Render_ImGui_menu() 
{
    RECT rect;
    GetWindowRect(Window::Get()->GetHWND(), &rect);

#pragma region MenuRendering // Menu rendering
    ImGui_ImplOpenGL2_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
    ImGui::SetNextWindowSize({200, 200});
    ImGui::Begin("Hello, Wercilius!", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_AlwaysAutoResize);
    {
	    ImGui::Text("Hello, World!");
    }
	ImGui::End();
    ImGui::EndFrame();
#pragma endregion

	ImGui::Render();
    glViewport(0, 0, rect.right, rect.top);   
	ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());
}
