add_library(Engine engine.cpp)

set(OpenCV_DIR "G:\\Software\\opencv\\build\\x64\\vc15\\lib")
find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(Engine PUBLIC
                    Controller
                    InputBuffer
                    EventProcessor
                    Detector
                    ${OpenCV_LIBS}
                    )

target_include_directories(Engine PUBLIC
                        ../
                        ${OpenCV_INCLUDE_DIRS}
                        )

install(TARGETS Engine DESTINATION lib)
install(FILES Engine.h DESTINATION include)