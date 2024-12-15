cmake_minimum_required(VERSION 3.13)

project(standard_vector_gtest)

add_subdirectory(google_test)
add_executable(standard_vector_gtest standard_vector_gtest.cpp)
target_include_directories(standard_vector_gtest PUBLIC ${CMAKE_SOURCE_DIR} gtest_main)
target_link_libraries(standard_vector_gtest gtest_main)
