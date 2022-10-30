cmake_minimum_required(VERSION 3.14)
project(render-lib)

set(CMAKE_CXX_STANDARD 20)

# 设置输出目录
if ($ENV{WASMENV})
    SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/dist)
    SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/dist)
    SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/dist)
endif()

# 设置编译参数
if ($ENV{WASMENV})
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
    SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3")
endif()

# 定义环境变量相关的宏，用于项目中环境判断

if ($ENV{WASMENV})
    add_definitions(-D__WASM__)
    add_definitions(-DWASM)
    add_definitions(-DPOSIX)
elseif(${APPLE})
    add_subdirectory(external/macOS/glfw-3.3.8)
    include_directories(${PROJECT_SOURCE_DIR}/external/macOS/glfw-3.3.8/include)
    add_definitions(-D__APPLE__)
    add_definitions(-DAPPLE)
    add_definitions(-DPOSIX)
elseif(${WIN32})
    add_definitions(-D__WIN32__)
    add_definitions(-DWIN32)
elseif(${UNIX})
    add_definitions(-D__UNIX__)
    add_definitions(-DUNIX)
    add_definitions(-DPOSIX)
elseif(${ANDROID})
    add_definitions(-D__ANDROID__)
    add_definitions(-DANDROID)
    add_definitions(-DPOSIX)
endif()

add_subdirectory(src)