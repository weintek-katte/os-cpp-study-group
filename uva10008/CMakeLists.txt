cmake_minimum_required(VERSION 3.0.0)
project(uva10008)

find_package(GTest CONFIG REQUIRED)

add_executable(uva10008 main.cpp)
target_link_libraries(uva10008 GTest::gtest)
