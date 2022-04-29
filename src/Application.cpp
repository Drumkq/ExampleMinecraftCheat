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
    if (sdk->GetLocal())
    {
        sdk->UpdateMappings();
        // std::cout << sdk->GetPlayer()->Local_GetName() << std::endl;
        // std::cout << sdk->GetPlayer()->Local_GetPosition().x << " " << sdk->GetPlayer()->Local_GetPosition().y << " " << sdk->GetPlayer()->Local_GetPosition().z << std::endl;
        std::cout << "Yaw: " << sdk->GetPlayer()->Local_GetYaw() << " | " << "Pitch: " << sdk->GetPlayer()->Local_GetPitch() << std::endl;
        if (!sdk->GetPlayer()->Local_IsAlive())
        {
            sdk->GetPlayer()->Local_Respawn();
        }
        if (!sdk->GetPlayer()->Local_IsVelocityChanged() && !sdk->GetPlayer()->Local_IsSneaking())
        {
            sdk->GetPlayer()->Local_SetSprint(true);
        }

        if (sdk->IsPaused())
        {
            std::cout << "Loxf kdlasksaklfjkljflkads\n\n";
        }
    }
}
