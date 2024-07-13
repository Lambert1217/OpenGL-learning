cmake_minimum_required(VERSION 3.26)
project(OpenGL-Learning)

set(CMAKE_CXX_STANDARD 17) # 设置为 C++17 标准
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(ROOTPATH ${CMAKE_CURRENT_LIST_DIR}) # 项目根路径
set(OUTPUTPATH ${ROOTPATH}/Output) # 项目输出路径

# thirdParty
add_subdirectory(${ROOTPATH}/thirdParty/glad)

# GLToolBox
add_subdirectory(${ROOTPATH}/GLToolBox)

# Demos
add_subdirectory(${ROOTPATH}/Demos/Demo1)
add_subdirectory(${ROOTPATH}/Demos/Demo2)

