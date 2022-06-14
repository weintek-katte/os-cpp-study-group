cmake_minimum_required(VERSION 3.0.0)
project(uva608)

find_package(GTest CONFIG REQUIRED)

add_executable(uva608 main.cpp)
target_link_libraries(uva608 GTest::gtest)
