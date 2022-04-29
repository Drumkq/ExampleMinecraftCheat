cmake_minimum_required(VERSION 3.6.0)

FILE (GLOB ImGui_srcs
    *.cpp
    *.h
)

target_sources(Wercilius PRIVATE
    ${ImGui_srcs}
)
