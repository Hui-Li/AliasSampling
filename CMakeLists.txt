cmake_minimum_required(VERSION 2.8)
project(AliasSampling)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -DNDEBUG -std=c++11 -pthread -march=native -ftree-vectorize")

add_executable(AliasSampling main.cpp AliasSamplingGenerator.h)

