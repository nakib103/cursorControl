cmake_minimum_required(VERSION 3.10)

# project name
project(cursorControl VERSION 0.0.1)

# secify C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
# set(OpenCV_DIR "G:\\Software\\opencv\\build\\x64\\vc15\\lib")

# find packages
# find_package(OpenCV REQUIRED)

configure_file(cursorControl.h.in cursorControl.h)

# include_directories(${OpenCV_INCLUDE_DIRS})
add_subdirectory(Controller)
add_subdirectory(InputBuffer)

# add executables
add_executable(cursorControl cursorControl.cpp)

target_link_libraries(cursorControl PUBLIC
                    Controller
                    InputBuffer
                    # ${OpenCV_LIBS}
                    )

target_include_directories(cursorControl PUBLIC
                        "${PROJECT_BINARY_DIR}"
                        )

install(TARGETS cursorControl DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/cursorControl.h" DESTINATION include)