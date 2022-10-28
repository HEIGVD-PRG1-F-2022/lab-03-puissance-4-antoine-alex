cmake_minimum_required(VERSION 3.23)
project(Mandelbrot)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")


add_executable(Mandelbrot main.cpp)
