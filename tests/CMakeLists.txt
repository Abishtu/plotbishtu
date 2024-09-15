
cmake_minimum_required(VERSION 3.10)

project(plotbishtu_test)

find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR}/include)  

file(GLOB_RECURSE SRC_FILES "${CMAKE_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE HDR_FILES "${CMAKE_SOURCE_DIR}/include/*.h")

add_executable(plotbishtu_test plotbishtu_test.cpp)

target_include_directories(plotbishtu_test PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(plotbishtu_test ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)

enable_testing()
add_test(NAME plotbishtu_test COMMAND plotbishtu_test)
target_compile_options(plotbishtu_test PRIVATE -Wall)
        