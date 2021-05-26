add_library(EventProcessor channel.cpp generator.cpp)

target_link_libraries(EventProcessor PUBLIC
                    Controller
                    InputBuffer
                    FaceDetector
                    )

install(TARGETS EventProcessor DESTINATION lib)
install(FILES EventProcessor.h DESTINATION include)