cmake_minimum_required(VERSION 3.6.0)
project(Wercilius)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/bin)
set(CMAKE_CACHEFILE_DIR ${CMAKE_CURRENT_LIST_DIR}/out)

add_library(Wercilius MODULE main.cpp)

target_link_libraries (Wercilius opengl32.dll)
target_link_libraries (Wercilius "C:/Program Files/Java/jdk1.8.0_311/lib/jvm.lib" "C:/Program Files/Java/jdk1.8.0_311/lib/jawt.lib")
include_directories ("C:/Program Files/Java/jdk1.8.0_311/include")
include_directories ("C:/Program Files/Java/jdk1.8.0_311/include/win32")
add_subdirectory (ThirdParty)
include_directories (ThirdParty)

add_subdirectory(src)
