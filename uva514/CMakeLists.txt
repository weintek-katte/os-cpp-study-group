cmake_minimum_required(VERSION 3.0.0)
project(uva514)

find_package(GTest CONFIG REQUIRED)

add_executable(uva514 main.cpp)
target_link_libraries(uva514 GTest::gtest)
