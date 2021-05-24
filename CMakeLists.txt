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

# add executables
add_executable(cursorControl cursorControl.cpp)

# include third-party packages 
set(BOOST_ROOT "G:\\Software\\boost") 
find_package(Boost 1.76.0) 
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIR}) 
endif()

target_link_libraries(cursorControl PUBLIC
                    Controller
                    InputBuffer
                    EventProcessor
                    )

target_include_directories(cursorControl PUBLIC
                        "${PROJECT_BINARY_DIR}"
                        )

install(TARGETS cursorControl DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/cursorControl.h" DESTINATION include)