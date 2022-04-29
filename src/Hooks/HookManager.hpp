#ifndef HOOKSMANAGER_HPP
#define HOOKSMANAGER_HPP

class HookManager
{
public:
    HookManager();
    ~HookManager();

    void EnableHooks();

private:
    static HookManager* _instance;
};

#endif