cmake_minimum_required(VERSION 3.6.0)

FILE (GLOB hooks_srcs
    *.cpp
    *.hpp
)

target_sources(Wercilius PRIVATE
    ${hooks_srcs}
)
