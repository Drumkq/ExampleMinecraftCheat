#ifndef JNIABSTRACTION_HPP
#define JNIABSTRACTION_HPP

#include <jni.h>

class JavaNativeInterface
{
public:
    JavaNativeInterface();
    ~JavaNativeInterface();

    [[nodiscard]] auto GetMinecraft() const
    {
        return this->_minecraft;
    }

    [[nodiscard]] auto GetEnv() const
    {
        return this->j_env;
    }

    [[nodiscard]] auto GetVM() const
    {
        return this->j_vm;
    }

    static JavaNativeInterface* Get()
    {
        return _instance;
    }

private:
    bool initalize_jni();

    static JavaNativeInterface* _instance;

    jclass _minecraft;
    JNIEnv* j_env;
    JavaVM* j_vm;
};

#endif