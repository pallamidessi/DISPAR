cmake_minimum_required(VERSION 2.8)
project( DISPAR )
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wextra -Wall -g")

OPTION(DEBUG_PRINT "DEBUG_PRINT" OFF) # Enabled by default

IF(DEBUG_PRINT)
    ADD_DEFINITIONS(-DDEBUG_PRINT)
ENDIF(DEBUG_PRINT)

find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()

add_executable( DISPAR main.cpp)
target_link_libraries( DISPAR )
