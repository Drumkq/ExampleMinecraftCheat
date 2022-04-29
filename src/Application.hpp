#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "Window/Window.hpp"
#include "JNI/JNI_abstraction.hpp"
#include "Hooks/Renderer.hpp"
#include "Hooks/HookManager.hpp" // Minhook implementation only
#include "SDK/SDK.hpp"

class Application
{
public:
    Application();
    ~Application();

    void Update();
    void Start();
    void OnClose();

private:
    Window* window = nullptr;
    HookManager* hook_manager = nullptr;
    JavaNativeInterface* jni_abstraction = nullptr;
    Renderer* renderer = nullptr;
    SDK* sdk = nullptr;
};

#endif