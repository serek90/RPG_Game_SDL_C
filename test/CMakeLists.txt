set(BINARY ${CMAKE_PROJECT_NAME}_tst)

link_directories( "C:/SDL2_image-2.0.1/lib/x64" "C:/SDL2/lib/x64")
include_directories("C:/SDL2/include" "C:/SDL2_image-2.0.1/include")
#link_directories( "packages/gtest.1.7.0/build/native/lib/Release")
#include_directories("packages/gtest.1.7.0/build/native/include")

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cpp)

set(SOURCES ${TEST_SOURCES})

add_executable(${BINARY} ${TEST_SOURCES})

add_test(NAME ${BINARY} COMMAND ${BINARY})

target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib SDL2 SDL2main SDL2_image)




