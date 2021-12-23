cmake_minimum_required(VERSION 3.0)

project(JianzhiOffer)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(CMAKE_BUILD_TYPE Debug)

include_directories(${CMAKE_SOURCE_DIR}/Utilities)

add_executable(lesson1 lesson1/lesson1.cpp)
add_executable(lesson3_1 lesson3/lesson3_1.cpp)
add_executable(lesson3_2 lesson3/lesson3_2.cpp)
add_executable(lesson4 lesson4/lesson4.cpp)
add_executable(lesson5 lesson5/lesson5.cpp)
add_executable(lesson6 lesson6/lesson6.cpp Utilities/List.cpp)
add_executable(lesson7 lesson7/lesson7.cpp Utilities/BinaryTree.cpp)
add_executable(lesson8 lesson8/lesson8.cpp)
add_executable(lesson9 lesson9/lesson9.cpp)
add_executable(lesson10_1 lesson10/lesson10_1.cpp)
add_executable(lesson11 lesson11/lesson11.cpp)
add_executable(lesson24 lesson24/lesson24.cpp Utilities/List.cpp)


