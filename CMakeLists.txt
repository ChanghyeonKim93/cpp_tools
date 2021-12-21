cmake_minimum_required(VERSION 2.8.3)
project(tools_test)
find_package(Boost REQUIRED COMPONENTS thread)

set(includeDirs ${includeDirs} include)
include_directories( ${includeDirs} )

set(DCMAKE_build_type RELEASE)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread -pg -O2 -m64 -Ofast -flto -msse3 -march=native -mfpmath=sse")

add_executable (test_objectpool src/main_objectpool.cpp)
