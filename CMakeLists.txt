cmake_minimum_required(VERSION 3.10)

# project name
project(cursorControl VERSION 0.0.1)

# secify C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

configure_file(cursorControl.h.in cursorControl.h)

# include subdirectories to be built
add_subdirectory(Controller)
add_subdirectory(InputBuffer)
add_subdirectory(EventProcessor)
add_subdirectory(Detector)
add_subdirectory(Engine)

# add executables
add_executable(cursorControl cursorControl.cpp)

# include third-party packages 
set(BOOST_ROOT "G:\\Software\\boost") 
set(OpenCV_DIR "G:\\Software\\opencv\\build\\x64\\vc15\\lib")

find_package(Boost 1.76.0) 
find_package(OpenCV REQUIRED)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIR}) 
endif()
include_directories(${OpenCV_INCLUDE_DIRS})

target_link_libraries(cursorControl PUBLIC
                    Controller
                    InputBuffer
                    EventProcessor
                    Detector
                    Engine
                    ${OpenCV_LIBS}
                    )

target_include_directories(cursorControl PUBLIC
                        "${PROJECT_BINARY_DIR}"
                        "${OpenCV_INCLUDE_DIRS}"
                        )

install(TARGETS cursorControl DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/cursorControl.h" DESTINATION include)