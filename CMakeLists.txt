#
# Celero Benchmark Framework
#

cmake_minimum_required(VERSION 2.8)
project(CELERO)

option(CELERO_BUILD_TESTS "Build the unit tests suite." OFF)
option(CELERO_BUILD_EXAMPLES "Build the examples." OFF)

message(STATUS "Selected options:")
message(STATUS "  CELERO_BUILD_TESTS:    ${CELERO_BUILD_TESTS}  (Build the unit tests suite: ON, OFF)")
message(STATUS "  CELERO_BUILD_EXAMPLES: ${CELERO_BUILD_EXAMPLES} (Build the examples: ON, OFF)")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -std=gnu++11 -Wall" CACHE STRING "Compiler Flags for All Builds" FORCE) 
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -pedantic" CACHE STRING "Compiler Flags for Debug Builds" FORCE) 
set(CMAKE_CXX_FLAGS_RELEASE  "${CMAKE_CXX_FLAGS_RELEASE}" CACHE STRING "Compiler Flags for Release Builds" FORCE) 

if(BUILD_SHARED_LIBS)
	add_definitions(-DCELERO_EXPORTS)
else()
	add_definitions(-DCELERO_STATIC)
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB_RECURSE CELERO_LIBRARY_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/include/celero/*.h
)
set(CELERO_LIBRARY_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/celero-benchmark_info.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/src/celero.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/src/celero-executor.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/src/celero-junit.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/src/celero-print.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/src/celero-result_table.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/src/celero-test_fixture.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/src/celero-test_vector.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/src/celero-timer.cc
)
set(CELERO_MAIN_LIBRARY_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/celero_main.cc
)

add_library(celero ${CELERO_LIBRARY_HEADERS} ${CELERO_LIBRARY_SOURCES})
add_library(celero_main STATIC ${CELERO_MAIN_LIBRARY_SOURCES})
target_link_libraries(celero_main celero)

if(CELERO_BUILD_TESTS)
    include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/deps/gmock/include
        ${CMAKE_CURRENT_SOURCE_DIR}/deps/gmock/gtest/include
    )
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/deps/gmock)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/test)
endif()

if(CELERO_BUILD_EXAMPLES)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/examples)
endif(CELERO_BUILD_EXAMPLES)

