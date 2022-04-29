#ifndef WORLD_HPP
#define WORLD_HPP

#include "../JNI/JNI_abstraction.hpp"

class World
{
public:
    World(jobject world);
    ~World();

private:
    jobject _world_class;
};

#endif