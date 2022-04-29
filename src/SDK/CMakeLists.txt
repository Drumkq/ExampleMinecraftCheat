cmake_minimum_required(VERSION 3.6.0)

FILE (GLOB SDK_srcs
    *.cpp
    *.hpp
)

target_sources (Wercilius PRIVATE
    ${SDK_srcs}
)
