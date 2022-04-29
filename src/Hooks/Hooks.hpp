#ifndef HOOKS_HPP
#define HOOKS_HPP

#include "Renderer.hpp"
#include "../Utils.hpp"

#include <windows.h>
#include <iostream>

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

namespace Hooks
{
    bool bOpen = true;

    namespace Signatures
    {
        constexpr auto gdi_module = "Gdi32.dll";
    }

    // Global C/C++ functions
    namespace Functions
    {
        typedef bool(__stdcall* SwapBuffer)(_In_ HDC);

        namespace Original
        {
            SwapBuffer  gl_swap_buffers     = nullptr;
            LONG_PTR    wndproc;

            void*       p_gl_swap_buffer    = nullptr;
            void*       p_wndproc           = nullptr;
        }

        namespace Hooked
        {
            bool __stdcall SwapBuffers(HDC hdc)
            {
                if (bOpen)
                    Renderer::Get()->Render_ImGui_menu();

                return Original::gl_swap_buffers(hdc);
            }

            long __stdcall wndproc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
            {
                switch (uMsg)
                {
                    case WM_KEYDOWN:
                        if (wParam == VK_DELETE)
                        {
                            bOpen = !bOpen;
                        }
                        break;
                }

                if (bOpen)
                    ImGui_ImplWin32_WndProcHandler(hwnd, uMsg, wParam, lParam);

                return CallWindowProc((WNDPROC)Original::wndproc, hwnd, uMsg, wParam, lParam);
            }
        }
    }
}

#endif