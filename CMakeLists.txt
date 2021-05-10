cmake_minimum_required(VERSION 3.10)

# project name
project(cursorControl VERSION 0.0.1)

configure_file(cursorControl.h.in cursorControl.h)

add_subdirectory(Controller)
add_subdirectory(InputBuffer)

# secify C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add executables
add_executable(cursorControl cursorControl.cpp)

target_link_libraries(cursorControl PUBLIC
                    Controller
                    InputBuffer
                    )

target_include_directories(cursorControl PUBLIC
                        "${PROJECT_BINARY_DIR}"
                        )