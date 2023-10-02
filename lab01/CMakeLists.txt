cmake_minimum_required(VERSION 3.10)
project(oc_lab_01)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(build/child source/child.cpp)
add_executable(build/main source/main.cpp)

enable_testing()
add_executable(build/tests source/tests.cpp  source/main.cpp)
target_link_libraries(tests ${GTEST_LIBRARIES})

add_test(NAME BASIC COMMAND tests)