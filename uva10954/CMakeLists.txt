cmake_minimum_required(VERSION 3.0.0)
project(uva10954)

find_package(GTest CONFIG REQUIRED)

add_executable(uva10954 main.cpp)
target_link_libraries(uva10954 GTest::gtest)
