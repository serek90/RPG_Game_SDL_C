set(BINARY ${CMAKE_PROJECT_NAME})

link_directories( "C:/SDL2_image-2.0.1/lib/x64" "C:/SDL2/lib/x64")
include_directories("C:/SDL2/include" "C:/SDL2_image-2.0.1/include")

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)

set(SOURCES ${SOURCES})

add_executable(${BINARY}_run ${SOURCES})

add_library(${BINARY}_lib STATIC ${SOURCES})
target_link_libraries(${BINARY}_run SDL2 SDL2main SDL2_image)