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
add_executable(unique_ptr_test smartPointers/unique_ptr_test.cpp)

add_executable(shellmad_15_1 smartPointers/shellmad_15_1.cpp)
add_executable(shellmad_15_2 smartPointers/shellmad_15_2.cpp)
add_executable(shellmad_15_3 smartPointers/shellmad_15_3.cpp)
add_executable(shellmad_16_1 smartPointers/shellmad_16_1.cpp)
add_executable(shellmad_17_1 smartPointers/shellmad_17_1.cpp)
add_executable(shellmad_18_1 smartPointers/shellmad_18_1.cpp)
add_executable(shellmad_20_1 smartPointers/shellmad_20_1.cpp)
add_executable(shellmad_21_1 smartPointers/shellmad_21_1.cpp)

add_executable(shellmad_06_1 shellmad_cast/shellmad_06_1.cpp)
add_executable(shellmad_07_1 shellmad_cast/shellmad_07_1.cpp)
add_executable(shellmad_08_1 shellmad_cast/shellmad_08_1.cpp)
add_executable(shellmad_09_1 shellmad_cast/shellmad_09_1.cpp)
add_executable(shellmad_10_1 shellmad_lambda/shellmad_10_1.cpp)
add_executable(shellmad_27_1 shellmad_thread/shellmad_27_1.cpp)
target_link_libraries(shellmad_27_1 pthread)
add_executable(shellmad_28_1 shellmad_thread/shellmad_28_1.cpp)
target_link_libraries(shellmad_28_1 pthread)

add_executable(shellmad_32_1 shellmad_thread/shellmad_32_1.cpp)
target_link_libraries(shellmad_32_1 pthread)

add_executable(shellmad_33_1 shellmad_thread/shellmad_33_1.cpp)
target_link_libraries(shellmad_33_1 pthread)

add_executable(shellmad_34_1 shellmad_thread/shellmad_34_1.cpp)
target_link_libraries(shellmad_34_1 pthread)
add_executable(shellmad_34_2 shellmad_thread/shellmad_34_2.cpp)
target_link_libraries(shellmad_34_2 pthread)

add_executable(shellmad_42_1 shellmad_static/shellmad_42_1.cpp)
add_executable(shellmad_43_1 shellmad_static/shellmad_43_1.cpp)
add_executable(shellmad_44_1 shellmad_static/shellmad_44_1.cpp)

add_executable(factory design_factory/Factor.cpp)
add_executable(factory_simple_1 design_factory/factory_simple_1.cpp)
add_executable(factory_simple_2 design_factory/factory_simple_2.cpp)
add_executable(factory_abstract_1 design_factory/factory_abstract_1.cpp)
add_executable(factory_advanced design_factory/factory_advanced/main.cpp 
design_factory/factory_advanced/Document1Factory.cpp
design_factory/factory_advanced/DocumentFactory.cpp
design_factory/factory_advanced/HtmlDocument.cpp
design_factory/factory_advanced/PDFDocument.cpp
design_factory/factory_advanced/TxtDocument.cpp)
add_executable(state design_state/state.cpp)






