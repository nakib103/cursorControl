add_library(EventProcessor channel.cpp)

install(TARGET EventProcessor DESTINATION lib)
install(FILES EventProcessor.h DESTINATION include)