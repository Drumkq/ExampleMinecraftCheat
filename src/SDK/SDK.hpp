#ifndef SDK_HPP
#define SDK_HPP

#include "../JNI/JNI_abstraction.hpp"
#include "Local.hpp"

class SDK
{
public:
    SDK();
    ~SDK();

    /* =============================== */

    [[nodiscard]] jobject GetMinecraft()
    {
        jclass minecraft_class = JavaNativeInterface::Get()->GetEnv()->FindClass("ave");
        jmethodID find_minecraft_id = JavaNativeInterface::Get()->GetEnv()->GetStaticMethodID(minecraft_class, "A", "()Lave;");

        return JavaNativeInterface::Get()->GetEnv()->CallStaticObjectMethod(minecraft_class, find_minecraft_id);
    }

    [[nodiscard]] jobject GetLocal()
    {
        jfieldID player_field_id = JavaNativeInterface::Get()->GetEnv()->GetFieldID(JavaNativeInterface::Get()->GetEnv()->GetObjectClass(GetMinecraft()), "h", "Lbew;");

		return JavaNativeInterface::Get()->GetEnv()->GetObjectField(GetMinecraft(), player_field_id);
    }

    /* =============================== */

    [[nodiscard]] auto GetPlayer()
    {
        return this->_player;
    }

    void UpdateMappings();

    static SDK* Get()
    {
        return _instance;
    }
private:
    static SDK* _instance;

    Local* _player = nullptr;
};

#endif