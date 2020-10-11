cmake_minimum_required(VERSION 3.3)

# Project name and version
project(RBT VERSION 1.0)

# Add headers
include_directories(include)
set(CMAKE_BUILD_TYPE Release)

############# SOURCES FOR EXECUTABLE ##########
# Add sources for executable
# set(SOURCES test/main.cpp src/hello_world.cpp)
file(GLOB SOURCES_EXE "src/*.cpp" "test/*.cpp")

add_compile_options("-W" "-Wall" "-pedantic")

# Add executable
add_executable(exe ${SOURCES_EXE})

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
