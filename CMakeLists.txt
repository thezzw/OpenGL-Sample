# 设定CMAKE最低版本
cmake_minimum_required(VERSION 3.13)

# 定义项目名称、描述和语言
project(
    OpenGLDemo
    DESCRIPTION "OpenGL demo project for learning."
    LANGUAGES C CXX
)

# 添加assimp库
option(ASSIMP_BUILD_ASSIMP_TOOLS OFF)
option(ASSIMP_BUILD_SAMPLES OFF)
option(ASSIMP_BUILD_TESTS OFF)
option(BUILD_SHARED_LIBS OFF)
add_subdirectory(lib/assimp)

# 添加glfw库
add_subdirectory(lib/glfw)

# 设置编译条件
if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 /MTd")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -std=c++11")
    if(NOT WIN32)
        set(GLAD_LIBRARIES dl)
    endif()
endif()

# 包含头文件的目录
include_directories(
    include/
    lib/assimp/include/
    lib/glad/include/
    lib/glfw/include/
    lib/glm/
    lib/stb/
    lib/imgui/
    lib/imgui/backends/
)

# 收集项目文件
file(
    GLOB VENDORS_SOURCES 
    lib/glad/src/glad.c
    lib/imgui/backends/imgui_impl_glfw.cpp
    lib/imgui/backends/imgui_impl_opengl3.cpp
    lib/imgui/imgui*.cpp
)
file(
    GLOB PROJECT_HEADERS
    include/*.hpp
)
file(
    GLOB PROJECT_SOURCES
    src/*.cpp
)
file(
    GLOB PROJECT_SHADERS
    assets/shader/*.frag
    assets/shader/*.vert
)

# 添加文件分组
source_group("headers" FILES ${PROJECT_HEADERS})
source_group("shaders" FILES ${PROJECT_SHADERS})
source_group("sources" FILES ${PROJECT_SOURCES})
source_group("vendors" FILES ${VENDORS_SOURCES})

#可执行文件一-----------------------------------------------------------------------------------
set(EXE_1_NAME exe_load_model)
file(
    GLOB EXE_1_SOURCES
    src/load_model.cpp
)

# 链接可执行文件
add_executable(${EXE_1_NAME} ${EXE_1_SOURCES} ${PROJECT_HEADERS}
                             ${PROJECT_SHADERS} ${VENDORS_SOURCES})

# 链接库
target_link_libraries(${EXE_1_NAME} assimp glfw ${GLAD_LIBRARIES})

# 设置运行时项目输出目录位置
set_target_properties(${EXE_1_NAME} PROPERTIES
                      RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${EXE_1_NAME})
#----------------------------------------------------------------------------------------------
#可执行文件二-----------------------------------------------------------------------------------
set(EXE_2_NAME exe_two_boxes)
file(
    GLOB EXE_2_SOURCES
    src/two_boxes.cpp
)

# 链接可执行文件
add_executable(${EXE_2_NAME} ${EXE_2_SOURCES} ${PROJECT_HEADERS}
                             ${PROJECT_SHADERS} ${VENDORS_SOURCES})

# 链接库
target_link_libraries(${EXE_2_NAME} assimp glfw ${GLAD_LIBRARIES})

# 设置运行时项目输出目录位置
set_target_properties(${EXE_2_NAME} PROPERTIES
                      RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${EXE_2_NAME})
#----------------------------------------------------------------------------------------------
#可执行文件三-----------------------------------------------------------------------------------
set(EXE_3_NAME exe_frame_buffer)
file(
    GLOB EXE_3_SOURCES
    src/frame_buffer.cpp
)

# 链接可执行文件
add_executable(${EXE_3_NAME} ${EXE_3_SOURCES} ${PROJECT_HEADERS}
                             ${PROJECT_SHADERS} ${VENDORS_SOURCES})

# 链接库
target_link_libraries(${EXE_3_NAME} assimp glfw ${GLAD_LIBRARIES})

# 设置运行时项目输出目录位置
set_target_properties(${EXE_3_NAME} PROPERTIES
                      RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${EXE_3_NAME})
#----------------------------------------------------------------------------------------------