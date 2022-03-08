cmake_minimum_required(VERSION 3.0.0)
project(uva263)

find_package(GTest CONFIG REQUIRED)

add_executable(uva263 main.cpp)
target_link_libraries(uva263 GTest::gtest)
