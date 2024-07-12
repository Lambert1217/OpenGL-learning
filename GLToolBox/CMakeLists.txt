cmake_minimum_required(VERSION 3.26)
project(GLToolBox)

set(CMAKE_CXX_STANDARD 17) # 设置为 C++17 标准
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUTPATH}/${CMAKE_BUILD_TYPE}/${PROJECT_NAME})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUTPATH}/${CMAKE_BUILD_TYPE}/${PROJECT_NAME})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUTPATH}/${CMAKE_BUILD_TYPE}/${PROJECT_NAME})

find_package(glfw3 REQUIRED)
find_package(spdlog REQUIRED)
find_package(glm REQUIRED)

file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp")

add_library(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE include)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME}
    PUBLIC
    spdlog::spdlog
    glfw3
    glad
    glm::glm
)