cmake_minimum_required(VERSION 3.30.5)
project(Students_analysis)

include_directories(include)

add_subdirectory(googletest)

set(CMAKE_CXX_FLAGS "-O3")

file(GLOB SOURCES "src/*.cpp")
add_library(Students_analysis STATIC ${SOURCES})

file(GLOB TEST_SOURCES "tests/*.cpp")

add_executable(runTests ${TEST_SOURCES})

target_link_libraries(runTests gtest gtest_main Students_analysis)

enable_testing()

add_test(NAME StudentaiTests COMMAND runTests)
