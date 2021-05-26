add_library(Detector cvfacedetect.cpp)

set(OpenCV_DIR "G:\\Software\\opencv\\build\\x64\\vc15\\lib")
find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(Detector PUBLIC
                    ${OpenCV_LIBS}
                    )

target_include_directories(Detector PUBLIC
                        ../
                        ${OpenCV_INCLUDE_DIRS}
                        )

install(TARGETS Detector DESTINATION lib)
install(FILES Detector.h DESTINATION include)