cmake_minimum_required(VERSION 3.10)
project(oop_exercise_05)

set(CMAKE_CXX_STANDARD 17)

add_executable(oop_exercise_05 main.cpp Queue.h Point.h Trapeze.h)
add_executable(test test.cpp)

target_link_libraries(test gtest gtest_main)