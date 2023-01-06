cmake_minimum_required(VERSION 3.23)
project(CircuitSimulator)

set(CMAKE_CXX_STANDARD 20)

set(SOURCES main.cpp Element.cpp Circuit.cpp Capacitor.cpp Inductor.cpp Resistor.cpp VoltageSource.cpp CurrentSource.cpp Source.cpp tests/CircuitTests.cpp tests/CircuitTests.h)

add_executable(CircuitSimulator ${SOURCES})

target_include_directories(CircuitSimulator PRIVATE include/CircuitSimulator)

include(FetchContent)
FetchContent_Declare(
        eigen
        GIT_REPOSITORY https://gitlab.com/libeigen/eigen.git
        GIT_TAG        3.4.0
)
FetchContent_MakeAvailable(eigen)

target_link_libraries (CircuitSimulator Eigen3::Eigen)

set(CMAKE_EXE_LINKER_FLAGS "-static")
