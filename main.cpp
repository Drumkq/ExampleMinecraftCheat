#include "Windows.h"
#include <thread>
#include <iostream>

#include "src/Application.hpp"

DWORD WINAPI Main(HMODULE hMod)
{
#ifdef _DEBUG // Pre-build version
    FILE *pFile = nullptr;
    AllocConsole();
    freopen_s(&pFile, "CONOUT$", "w", stdout);
    std::cout << "Current build - DEBUG!\n";


    Application* app = new Application();

    app->Start(); // Initialize all

    while(true)
    {
        if (GetAsyncKeyState(VK_END) & 1)
            break;

        app->Update(); // Update modules and scripts
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }

    delete app;

    fclose(pFile);
    FreeConsole();
#else // Release build with new features

#endif

    FreeLibraryAndExitThread(hMod, 0); // Ejecting...
}

BOOL WINAPI DllMain(
    HMODULE     hMod,
    DWORD       fdwReason,
    LPVOID      lpReserved )
{
    switch( fdwReason ) 
    { 
        case DLL_PROCESS_ATTACH:
            CloseHandle(CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)Main, hMod, 0, nullptr));
            break;

        case DLL_PROCESS_DETACH:

            break;
    }
    return TRUE;
}