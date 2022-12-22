cmake_minimum_required(VERSION 3.23)
project(CircuitSimulator)

set(CMAKE_CXX_STANDARD 20)

set(SOURCES main.cpp Element.cpp Complex.cpp Circuit.cpp )

add_executable(CircuitSimulator ${SOURCES})

target_include_directories(CircuitSimulator PRIVATE include/CircuitSimulator)

set(CMAKE_EXE_LINKER_FLAGS "-static")
