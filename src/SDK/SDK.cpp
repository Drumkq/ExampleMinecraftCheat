#include "SDK.hpp"

SDK* SDK::_instance = nullptr;

SDK::SDK() 
{
    if (!_instance)
    {
        _instance = this;
    }

    this->_player = new Local(GetLocal());
}

SDK::~SDK() 
{
    this->_player = nullptr;
}

void SDK::UpdateMappings() 
{
    this->_player->_player_class = GetLocal();
}
