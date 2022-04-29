#include "Application.hpp"
#include <iostream>

// Preprocessor minecraft versions (supporting only 1.8.8 and 1.8.9)
// #define MINECRAFT_TITLE "Minecraft 1.8.8"
#define MINECRAFT_TITLE "Minecraft 1.8.9"
// #define MINECRAFT_TITLE "Minecraft 1.12.2"

Application::Application() 
{
    this->window = new Window(MINECRAFT_TITLE);
    this->renderer = new Renderer();
    this->renderer->Initialize_ImGui();
    this->hook_manager = new HookManager();
    this->jni_abstraction = new JavaNativeInterface();
    this->sdk = new SDK();
}

Application::~Application()
{
    delete this->hook_manager; // Unhook all
    delete this->renderer;
    delete this->window;
    delete this->jni_abstraction;
    delete this->sdk;
}

void Application::Start() 
{
    this->hook_manager->EnableHooks();
}

void Application::Update() 
{
    sdk->UpdateMappings();

    if (sdk->GetLocal())
    {
        std::cout << sdk->GetPlayer()->Local_GetName() << std::endl;
        std::cout << sdk->GetPlayer()->Local_GetPosition().x << " " << sdk->GetPlayer()->Local_GetPosition().y << " " << sdk->GetPlayer()->Local_GetPosition().z << std::endl;
    }
}
