#ifndef LOCAL_HPP
#define LOCAL_HPP

#include "../JNI/JNI_abstraction.hpp"

#include <string>
#include "../Utils.hpp"

class Local
{
    friend class SDK;
public:
    Local(jobject player_class);
    ~Local();

    [[nodiscard]] auto Local_GetName()
    {
        return this->user_name;
    }

    void Local_SetPosition(float x, float y, float z);
    void Local_SetSprint(jboolean bSprint);
    void Local_SetFlight(jboolean bFlight);
    void Local_SetPitch(jfloat fPitch);
    void Local_SetYaw(jfloat fYaw);
    void Local_Mute(jboolean bSilent); // Player will not play sounds

    void Local_Respawn();
    void Local_SendMessage(std::string message);
    void Local_VelocityToZero();
    void Local_PlaySound(std::string sound_name, float sound_volume);
    void Local_Hitbox(float height, float width);

    float Local_GetYaw();
    float Local_GetPitch();

    bool Local_IsAlive();
    bool Local_IsSneaking();
    bool Local_IsSprinting();
    bool Local_IsInWater();
    bool Local_IsInvisible();
    bool Local_IsInLava();
    bool Local_IsBurning();
    bool Local_IsEating();
    bool Local_IsRiding();
    bool Local_IsVelocityChanged();

    Utils::Vector3D Local_GetPosition();

    std::string _GetUserName();

private:
    jobject _player_class;

    std::string user_name;

    jfieldID x_field_id;
    jfieldID y_field_id;
    jfieldID z_field_id;
};

#endif