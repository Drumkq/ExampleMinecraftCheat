#include "HookManager.hpp"
#include "../Window/Window.hpp"
#include "Hooks.hpp"
#include "../Utils.hpp"

#include <MinHook/MinHook.h>
#include <iostream>

HookManager* HookManager::_instance = nullptr;

HookManager::HookManager()
{
    if (!_instance)
    {
        _instance = this;
    }


}

HookManager::~HookManager()
{
    // Set old wndproc
    SetWindowLongPtr(Window::Get()->GetHWND(), GWLP_WNDPROC, Hooks::Functions::Original::wndproc);
    Hooks::Functions::Original::wndproc = NULL;

    // Restore all hooked functions to the originals
    MH_DisableHook(MH_ALL_HOOKS); // Swapbuffer hook
    MH_Uninitialize();
}

void HookManager::EnableHooks()
{
    // Get addresses
    Hooks::Functions::Original::p_gl_swap_buffer = Utils::get_address(Hooks::Signatures::gdi_module, "SwapBuffers"); // Get base address of swap buffer
    
    // Initialize hooks
    MH_Initialize();
    {
        MH_CreateHook(Hooks::Functions::Original::p_gl_swap_buffer, Hooks::Functions::Hooked::SwapBuffers, reinterpret_cast<void**>(&Hooks::Functions::Original::gl_swap_buffers)); // Swapbuffer hook
        if (!Hooks::Functions::Original::gl_swap_buffers)
        {
            std::runtime_error("[Hook] SwapBuffer");
        }
        if (!Hooks::Functions::Original::p_gl_swap_buffer)
        {
            std::runtime_error("[Hook] SwapBuffers ptr");
        }
    }
    MH_EnableHook(MH_ALL_HOOKS); // Enable all hooks

    // Set new wndproc and save old in "Hooks::Functions::Original::wndproc"
    Hooks::Functions::Original::wndproc = SetWindowLongPtr(Window::Get()->GetHWND(), GWLP_WNDPROC, (LONG_PTR)Hooks::Functions::Hooked::wndproc); // Replace original wndproc to hooked
    if (!Hooks::Functions::Original::wndproc)
    {
        std::runtime_error("[Hook] SetWindowLongPtr failed");
    }
}
