cmake_minimum_required(VERSION 3.6.0)

FILE (GLOB window_srcs
    *.cpp
    *.hpp
)

target_sources(Wercilius PRIVATE
    ${window_srcs}
)
