add_library(InputBuffer videobuf.cpp)

set(OpenCV_DIR "G:\\Software\\opencv\\build\\x64\\vc15\\lib")

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

target_link_libraries(InputBuffer PUBLIC
                    ${OpenCV_LIBS}
                    )

install(TARGETS InputBuffer DESTINATION lib)
install(FILES InputBuffer.h DESTINATION include)