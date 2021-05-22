add_library(Controller mousectl.cpp)

set(BOOST_ROOT "G:\\Software\\boost") 
find_package(Boost 1.76.0) 

if(Boost_FOUND)
    message(STATUS "Boost_VERSION: ${Boost_VERSION}")
    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
    include_directories(${Boost_INCLUDE_DIR}) 
    target_link_libraries(Controller PUBLIC 
                        ${Boost_LIBRARIES})
endif()

target_include_directories(Controller PUBLIC 
                        ../
                        ${Boost_INCLUDE_DIR}
                        )

install(TARGETS Controller DESTINATION lib)
install(FILES Controller.h DESTINATION include)
