cmake_minimum_required(VERSION 3.15...3.31)

project(
  lox_interpreter
  VERSION 1.0
  LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -march=native")

file(GLOB_RECURSE SOURCE_FILES src/*.cpp src/*.hpp)
include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(interpreter ${SOURCE_FILES})
