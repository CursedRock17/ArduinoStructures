cmake_minimum_required(VERSION 3.13.4)

project(ArduinoVisualizer)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(src/Debug)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC Debug)
target_include_directories(${PROJECT_NAME} PUBLIC
"${PROJECT_BINARY_DIR}"
"${PROJECT_SOURCE_DIR}/src/Debug"
)
