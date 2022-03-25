cmake_minimum_required(VERSION "3.2.1")

project("RPG_Game_SDL_C")

link_directories( "C:/SDL2_image-2.0.1/lib/x64" "C:/SDL2/lib/x64")
include_directories("C:/SDL2/include" "C:/SDL2_image-2.0.1/include")

file(GLOB SOURCES
    *.h
    *.cpp
)

set(CMAKE_SUPPRESS_REGENERATION true)
add_executable("${PROJECT_NAME}" ${SOURCES})
target_link_libraries("${PROJECT_NAME}" SDL2 SDL2main SDL2_image)



