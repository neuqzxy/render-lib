include_directories(include)

add_library(utils_lib Matrix.cpp test/Matrix.cpp Output.cpp Tools.cpp)

add_executable(TestMatrix test/Matrix.cpp)
target_link_libraries(TestMatrix utils_lib)
add_test(TEST_MATRIX TestMatrix COMMAND TestMatrix)
