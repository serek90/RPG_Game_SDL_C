cmake_minimum_required(VERSION "3.2.1")

project("RPG_Game_SDL_C")

set(CMAKE_CXX_STANDARD 14)

link_directories( RPG_LOR_Game)

add_subdirectory(RPG_LOR_Game)
add_subdirectory(test)
