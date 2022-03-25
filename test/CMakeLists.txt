cmake_minimum_required(VERSION "3.2.1")

project("test")

link_directories( "C:/SDL2_image-2.0.1/lib/x64" "C:/SDL2/lib/x64")
include_directories("C:/SDL2/include" "C:/SDL2_image-2.0.1/include")

#link_directories( "packages/gtest.1.7.0/build/native/lib/Release")
#include_directories("packages/gtest.1.7.0/build/native/include")

file(GLOB SOURCES
    *.h
    *.cpp
)

set(CMAKE_SUPPRESS_REGENERATION true)
add_executable("${PROJECT_NAME}" ${SOURCES})
target_link_libraries("${PROJECT_NAME}" SDL2 SDL2main SDL2_image gtest)



