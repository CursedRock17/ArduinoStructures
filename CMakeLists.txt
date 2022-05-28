cmake_minimum_required(VERSION 3.13.4)

project(ArduinoVisualizer)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(src/Debug)
add_subdirectory(src/Vector)
add_subdirectory(src/Queue)
add_subdirectory(src/Stack)
add_subdirectory(src/LinkedList)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC Debug)
target_link_libraries(${PROJECT_NAME} PUBLIC Vector)
target_link_libraries(${PROJECT_NAME} PUBLIC Queue)
target_link_libraries(${PROJECT_NAME} PUBLIC Stack)
target_link_libraries(${PROJECT_NAME} PUBLIC LinkedList)

target_include_directories(${PROJECT_NAME} PUBLIC
"${PROJECT_BINARY_DIR}"
"${PROJECT_SOURCE_DIR}/src/Debug"
"${PROJECT_SOURCE_DIR}/src/Vector"
"${PROJECT_SOURCE_DIR}/src/Queue"
"${PROJECT_SOURCE_DIR}/src/Stack"
"${PROJECT_SOURCE_DIR}/src/LinkedList"
)
