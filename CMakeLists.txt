cmake_minimum_required(VERSION 3.5)

set(EXECUTABLE_NAME "universe")
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

project(${EXECUTABLE_NAME})

include_directories(inc)

file(GLOB_RECURSE SOURCES src/*.cpp)
file(GLOB_RECURSE DATA resources/*)

add_executable(${EXECUTABLE_NAME} ${SOURCES})

target_compile_options(${EXECUTABLE_NAME} PUBLIC -std=c++0x -ggdb)


# finds and link SFML
find_package(SFML 1.6 REQUIRED system window graphics network audio)
target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})

# copy all resource files in the build directory
file(COPY ${DATA} DESTINATION resources)
