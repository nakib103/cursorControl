add_library(Controller mousectl.cpp)

install(TARGETS Controller DESTINATION lib)
install(FILES Controller.h DESTINATION include)