add_library(core main.cpp)
add_subdirectory(utils)
target_link_libraries(core utils)
add_subdirectory(bridge)
