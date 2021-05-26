add_library(FaceDetector cvfacedetect.cpp)

set(OpenCV_DIR "G:\\Software\\opencv\\build\\x64\\vc15\\lib")
find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(FaceDetector PUBLIC
                    ${OpenCV_LIBS}
                    )

target_include_directories(FaceDetector PUBLIC
                        ../
                        ${OpenCV_INCLUDE_DIRS}
                        )

install(TARGETS FaceDetector DESTINATION lib)
install(FILES FaceDetector.h DESTINATION include)