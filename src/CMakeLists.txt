cmake_minimum_required(VERSION 3.6.0)

FILE (GLOB srcs
    *.cpp
    *.hpp
)

target_sources(Wercilius PRIVATE
    ${srcs}
)

add_subdirectory(Hooks)
add_subdirectory(JNI)
add_subdirectory(Window)
add_subdirectory(SDK)