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

    Utils::Vector3D Local_GetPosition();

    std::string GetUserName();

private:
    jobject _player_class;

    std::string user_name;

    jfieldID x_field_id;
    jfieldID y_field_id;
    jfieldID z_field_id;
};

#endif