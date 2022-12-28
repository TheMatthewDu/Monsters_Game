cmake_minimum_required(VERSION 3.0.0)
project(PkMonsters)

include(CTest)
enable_testing()

# Create a sources variable with a link to all cpp files to compile
include_directories("include/")
include_directories("include/monsters")
include_directories("include/utilities")
file(GLOB SOURCES src/*.cpp src/monsters/*.cpp src/utilities/*.cpp)

add_library(core ${SOURCES})
# Add an executable with the above sources
add_executable(PkMonsters main.cpp)
add_executable(PkPlayer player.cpp)

target_link_libraries(PkMonsters core)
target_link_libraries(PkPlayer core)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
