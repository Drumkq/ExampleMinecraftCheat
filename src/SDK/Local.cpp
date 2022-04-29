#include "Local.hpp"

Local::Local(jobject player_class)
    : _player_class(player_class)
{
    this->user_name = GetUserName();

    x_field_id = JavaNativeInterface::Get()->GetEnv()->GetFieldID( JavaNativeInterface::Get()->GetEnv()->GetObjectClass(_player_class), "s", "D" );
    y_field_id = JavaNativeInterface::Get()->GetEnv()->GetFieldID( JavaNativeInterface::Get()->GetEnv()->GetObjectClass(_player_class), "t", "D" );
    z_field_id = JavaNativeInterface::Get()->GetEnv()->GetFieldID( JavaNativeInterface::Get()->GetEnv()->GetObjectClass(_player_class), "u", "D" );
}

Local::~Local() = default;

std::string Local::GetUserName() 
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
