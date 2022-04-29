#include "Local.hpp"

Local::Local(jobject player_class)
    : _player_class(player_class)
{}

Local::~Local() = default;

std::string Local::_GetUserName() 
{
    jmethodID getname_method = JavaNativeInterface::Get()->GetEnv()->GetMethodID(JavaNativeInterface::Get()->GetEnv()->GetObjectClass(this->_player_class), "e_", "()Ljava/lang/String;");
	jstring name_string = (jstring)JavaNativeInterface::Get()->GetEnv()->CallObjectMethod(this->_player_class, getname_method);
	return std::string(JavaNativeInterface::Get()->GetEnv()->GetStringUTFChars(name_string, false));    
}

Utils::Vector3D Local::Local_GetPosition() 
{
	float x = (float)JavaNativeInterface::Get()->GetEnv()->GetDoubleField(this->_player_class, x_field_id);
	float y = (float)JavaNativeInterface::Get()->GetEnv()->GetDoubleField(this->_player_class, y_field_id);
	float z = (float)JavaNativeInterface::Get()->GetEnv()->GetDoubleField(this->_player_class, z_field_id);

    return Utils::Vector3D(x, y, z);    
}

float Local::Local_GetYaw() 
{
    jfieldID yaw_field_id = JavaNativeInterface::Get()->GetEnv()->GetFieldID(JavaNativeInterface::Get()->GetEnv()->GetObjectClass(this->_player_class), "y", "F");
	return JavaNativeInterface::Get()->GetEnv()->GetFloatField(this->_player_class, yaw_field_id);
}

float Local::Local_GetPitch() 
{
    jfieldID pitch_field_id = JavaNativeInterface::Get()->GetEnv()->GetFieldID(JavaNativeInterface::Get()->GetEnv()->GetObjectClass(this->_player_class), "z", "F");
	return JavaNativeInterface::Get()->GetEnv()->GetFloatField(this->_player_class, pitch_field_id);
}

bool Local::Local_IsAlive() 
{
    jmethodID alive_method = JavaNativeInterface::Get()->GetEnv()->GetMethodID(JavaNativeInterface::Get()->GetEnv()->GetObjectClass(this->_player_class), "ai", "()Z");
	return JavaNativeInterface::Get()->GetEnv()->CallBooleanMethod(this->_player_class, alive_method);
}

void Local::Local_SetSprint(jboolean bSprint) 
{
    jmethodID setsprint_method_id = JavaNativeInterface::Get()->GetEnv()->GetMethodID(JavaNativeInterface::Get()->Get()->GetEnv()->GetObjectClass(this->_player_class), "d", "(Z)V");
    JavaNativeInterface::Get()->GetEnv()->CallVoidMethod(this->_player_class, setsprint_method_id, bSprint);
}

void Local::Local_SetPosition(float x, float y, float z) 
{
    jmethodID set_position_method = JavaNativeInterface::Get()->GetEnv()->GetMethodID(JavaNativeInterface::Get()->GetEnv()->GetObjectClass(this->_player_class), "b", "(DDD)V");
	return JavaNativeInterface::Get()->GetEnv()->CallVoidMethod(this->_player_class, set_position_method, x, y, z);
}

void Local::Local_SetFlight(jboolean bFlight) 
{
    
}

void Local::Local_SetPitch(jfloat fPitch) 
{
    jfieldID pitch_field_id = JavaNativeInterface::Get()->GetEnv()->GetFieldID(JavaNativeInterface::Get()->GetEnv()->GetObjectClass(this->_player_class), "z", "F");
	JavaNativeInterface::Get()->GetEnv()->SetFloatField(this->_player_class, pitch_field_id, fPitch);
}

void Local::Local_SetYaw(jfloat fYaw) 
{
    jfieldID yaw_field_id = JavaNativeInterface::Get()->GetEnv()->GetFieldID( JavaNativeInterface::Get()->GetEnv()->GetObjectClass(this->_player_class), "y", "F");

    JavaNativeInterface::Get()->GetEnv()->SetFloatField(this->_player_class, yaw_field_id, fYaw);
}

void Local::Local_Respawn() 
{
    jmethodID respawn_method_id = JavaNativeInterface::Get()->GetEnv()->GetMethodID(JavaNativeInterface::Get()->Get()->GetEnv()->GetObjectClass(this->_player_class), "cb", "()V");
    JavaNativeInterface::Get()->GetEnv()->CallVoidMethod(this->_player_class, respawn_method_id);
}

void Local::Local_SendMessage(std::string message) 
{
    jmethodID sendmessage_method_id = JavaNativeInterface::Get()->GetEnv()->GetMethodID(JavaNativeInterface::Get()->Get()->GetEnv()->GetObjectClass(this->_player_class), "e", "(Ljava/lang/String;)V");
    jstring java_message = JavaNativeInterface::Get()->GetEnv()->NewStringUTF(message.c_str());
    JavaNativeInterface::Get()->GetEnv()->CallVoidMethod(this->_player_class, sendmessage_method_id, java_message);
}

void Local::Local_VelocityToZero() 
{
    jmethodID setvelocity_method_id = JavaNativeInterface::Get()->GetEnv()->GetMethodID(JavaNativeInterface::Get()->Get()->GetEnv()->GetObjectClass(this->_player_class), "i", "(DDD)V");
    JavaNativeInterface::Get()->GetEnv()->CallVoidMethod(this->_player_class, setvelocity_method_id, 0, 0, 0);
}

void Local::Local_PlaySound(std::string sound_name, float sound_volume) 
{
    jmethodID playsound_method_id = JavaNativeInterface::Get()->GetEnv()->GetMethodID(JavaNativeInterface::Get()->Get()->GetEnv()->GetObjectClass(this->_player_class), "a", "(Ljava/lang/String;FF)V");
    jstring java_sound_name = JavaNativeInterface::Get()->GetEnv()->NewStringUTF(sound_name.c_str());
    JavaNativeInterface::Get()->GetEnv()->CallVoidMethod(this->_player_class, playsound_method_id, java_sound_name, 0, sound_volume);
}

void Local::Local_Hitbox(float height, float width) 
{
    jmethodID sethitbox_method_id = JavaNativeInterface::Get()->GetEnv()->GetMethodID(JavaNativeInterface::Get()->Get()->GetEnv()->GetObjectClass(this->_player_class), "a", "(FF)V");
    JavaNativeInterface::Get()->GetEnv()->CallVoidMethod(this->_player_class, sethitbox_method_id, height, width);
}

bool Local::Local_IsBurning() 
{
    jmethodID method_id = JavaNativeInterface::Get()->GetEnv()->GetMethodID(JavaNativeInterface::Get()->Get()->GetEnv()->GetObjectClass(this->_player_class), "at", "()Z");
    return JavaNativeInterface::Get()->GetEnv()->CallBooleanMethod(this->_player_class, method_id);
}

bool Local::Local_IsEating() 
{
    jmethodID method_id = JavaNativeInterface::Get()->GetEnv()->GetMethodID(JavaNativeInterface::Get()->Get()->GetEnv()->GetObjectClass(this->_player_class), "ay", "()Z");
    return JavaNativeInterface::Get()->GetEnv()->CallBooleanMethod(this->_player_class, method_id);
}

bool Local::Local_IsInLava() 
{
    jmethodID method_id = JavaNativeInterface::Get()->GetEnv()->GetMethodID(JavaNativeInterface::Get()->Get()->GetEnv()->GetObjectClass(this->_player_class), "ab", "()Z");
    return JavaNativeInterface::Get()->GetEnv()->CallBooleanMethod(this->_player_class, method_id);
}

bool Local::Local_IsInvisible() 
{
    jmethodID method_id = JavaNativeInterface::Get()->GetEnv()->GetMethodID(JavaNativeInterface::Get()->Get()->GetEnv()->GetObjectClass(this->_player_class), "ax", "()Z");
    return JavaNativeInterface::Get()->GetEnv()->CallBooleanMethod(this->_player_class, method_id);
}

bool Local::Local_IsInWater() 
{
    jmethodID method_id = JavaNativeInterface::Get()->GetEnv()->GetMethodID(JavaNativeInterface::Get()->Get()->GetEnv()->GetObjectClass(this->_player_class), "V", "()Z");
    return JavaNativeInterface::Get()->GetEnv()->CallBooleanMethod(this->_player_class, method_id);
}

bool Local::Local_IsSprinting() 
{
    jmethodID method_id = JavaNativeInterface::Get()->GetEnv()->GetMethodID(JavaNativeInterface::Get()->Get()->GetEnv()->GetObjectClass(this->_player_class), "aw", "()Z");
    return JavaNativeInterface::Get()->GetEnv()->CallBooleanMethod(this->_player_class, method_id);
}

bool Local::Local_IsSneaking() 
{
    jmethodID method_id = JavaNativeInterface::Get()->GetEnv()->GetMethodID(JavaNativeInterface::Get()->Get()->GetEnv()->GetObjectClass(this->_player_class), "av", "()Z");
    return JavaNativeInterface::Get()->GetEnv()->CallBooleanMethod(this->_player_class, method_id);
}

bool Local::Local_IsRiding() 
{
    jmethodID method_id = JavaNativeInterface::Get()->GetEnv()->GetMethodID(JavaNativeInterface::Get()->Get()->GetEnv()->GetObjectClass(this->_player_class), "au", "()Z");
    return JavaNativeInterface::Get()->GetEnv()->CallBooleanMethod(this->_player_class, method_id);
}

bool Local::Local_IsVelocityChanged() 
{
    jfieldID vel_x_id = JavaNativeInterface::Get()->GetEnv()->GetFieldID(JavaNativeInterface::Get()->Get()->GetEnv()->GetObjectClass(this->_player_class), "P", "D");
    jfieldID vel_y_id = JavaNativeInterface::Get()->GetEnv()->GetFieldID(JavaNativeInterface::Get()->Get()->GetEnv()->GetObjectClass(this->_player_class), "Q", "D");
    jfieldID vel_z_id = JavaNativeInterface::Get()->GetEnv()->GetFieldID(JavaNativeInterface::Get()->Get()->GetEnv()->GetObjectClass(this->_player_class), "R", "D");
    
    jdouble vel_x = JavaNativeInterface::Get()->GetEnv()->GetDoubleField(JavaNativeInterface::Get()->Get()->GetEnv()->GetObjectClass(this->_player_class), vel_x_id);
    jdouble vel_y = JavaNativeInterface::Get()->GetEnv()->GetDoubleField(JavaNativeInterface::Get()->Get()->GetEnv()->GetObjectClass(this->_player_class), vel_y_id);
    jdouble vel_z = JavaNativeInterface::Get()->GetEnv()->GetDoubleField(JavaNativeInterface::Get()->Get()->GetEnv()->GetObjectClass(this->_player_class), vel_z_id);

    auto current_pos = Local_GetPosition();
    if (vel_x == current_pos.x && vel_y == current_pos.y && vel_z == current_pos.z)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Local::Local_Mute(jboolean bSilent) 
{
    jmethodID method_id = JavaNativeInterface::Get()->GetEnv()->GetMethodID(JavaNativeInterface::Get()->Get()->GetEnv()->GetObjectClass(this->_player_class), "b", "(Z)V");
    JavaNativeInterface::Get()->GetEnv()->CallVoidMethod(this->_player_class, method_id, bSilent);
}
