cmake_minimum_required(VERSION 3.6.0)

FILE (GLOB JNI_srcs
    *.cpp
    *.hpp
)

target_sources(Wercilius PRIVATE
    ${JNI_srcs}
)
