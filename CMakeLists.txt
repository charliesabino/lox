cmake_minimum_required(VERSION 3.15...3.31)

project(
  lox_interpreter
  VERSION 1.0
  LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 23)

add_executable(interpreter main.cpp)
