#include "JNI_abstraction.hpp"

#include "../Utils.hpp"

#include <iostream>

JavaNativeInterface* JavaNativeInterface::_instance = nullptr;

JavaNativeInterface::JavaNativeInterface()
{
    if (!_instance)
    {
        _instance = this;
    }

    if (!initalize_jni())
    {
        std::runtime_error("[JNI] \"initialize jni\" failed");
    }
}

JavaNativeInterface::~JavaNativeInterface()
{
    this->j_vm->DetachCurrentThread();
    
    this->j_env = nullptr;
    this->j_vm = nullptr;
}

bool JavaNativeInterface::initalize_jni() 
{
    auto jvm_module = Utils::get_module_handle("jvm.dll");
    jsize all_jvms = 0;
    if (JNI_GetCreatedJavaVMs( &this->j_vm, 1, &all_jvms ) != JNI_OK || all_jvms == 0) {
		std::runtime_error("[JNI] JNI_GetCreatedJavaVMs");
	}
    
    jint res = this->j_vm->GetEnv((void**)&this->j_env, JNI_VERSION_1_6 );
	if ( res == JNI_EDETACHED ) {
		res = this->j_vm->AttachCurrentThread((void**) &this->j_env, nullptr );
	}

    if ( res != JNI_OK ) {
		std::runtime_error("[JNI] GetEnv or AttachCurrentThread");
	}

    return true;
}
