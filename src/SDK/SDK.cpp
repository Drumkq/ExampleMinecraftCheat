#include "SDK.hpp"

SDK* SDK::_instance = nullptr;

SDK::SDK() 
{
    if (!_instance)
    {
        _instance = this;
    }

    this->_player = new Local(0);
}

SDK::~SDK() 
{
    this->_player = nullptr;
}

void SDK::UpdateMappings() 
{
    // Player
    this->_player->_player_class = GetLocal();

    this->_player->user_name = this->_player->_GetUserName();

    this->_player->x_field_id = JavaNativeInterface::Get()->GetEnv()->GetFieldID( JavaNativeInterface::Get()->GetEnv()->GetObjectClass(this->_player->_player_class), "s", "D" );
    this->_player->y_field_id = JavaNativeInterface::Get()->GetEnv()->GetFieldID( JavaNativeInterface::Get()->GetEnv()->GetObjectClass(this->_player->_player_class), "t", "D" );
    this->_player->z_field_id = JavaNativeInterface::Get()->GetEnv()->GetFieldID( JavaNativeInterface::Get()->GetEnv()->GetObjectClass(this->_player->_player_class), "u", "D" );
}
