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
    assets/shader/*.geom
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
#可执行文件四-----------------------------------------------------------------------------------
set(EXE_4_NAME exe_geometry_shader)
file(
    GLOB EXE_4_SOURCES
    src/geometry_shader.cpp
)

# 链接可执行文件
add_executable(${EXE_4_NAME} ${EXE_4_SOURCES} ${PROJECT_HEADERS}
                             ${PROJECT_SHADERS} ${VENDORS_SOURCES})

# 链接库
target_link_libraries(${EXE_4_NAME} assimp glfw ${GLAD_LIBRARIES})

# 设置运行时项目输出目录位置
set_target_properties(${EXE_4_NAME} PROPERTIES
                      RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${EXE_4_NAME})
#----------------------------------------------------------------------------------------------
#可执行文件五-----------------------------------------------------------------------------------
set(EXE_5_NAME exe_instanced)
file(
    GLOB EXE_5_SOURCES
    src/instanced.cpp
)

# 链接可执行文件
add_executable(${EXE_5_NAME} ${EXE_5_SOURCES} ${PROJECT_HEADERS}
                             ${PROJECT_SHADERS} ${VENDORS_SOURCES})

# 链接库
target_link_libraries(${EXE_5_NAME} assimp glfw ${GLAD_LIBRARIES})

# 设置运行时项目输出目录位置
set_target_properties(${EXE_5_NAME} PROPERTIES
                      RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${EXE_5_NAME})
#----------------------------------------------------------------------------------------------
#可执行文件六-----------------------------------------------------------------------------------
set(EXE_6_NAME exe_instanced_asteroid_belt)
file(
    GLOB EXE_6_SOURCES
    src/instanced_asteroid_belt.cpp
)

# 链接可执行文件
add_executable(${EXE_6_NAME} ${EXE_6_SOURCES} ${PROJECT_HEADERS}
                             ${PROJECT_SHADERS} ${VENDORS_SOURCES})

# 链接库
target_link_libraries(${EXE_6_NAME} assimp glfw ${GLAD_LIBRARIES})

# 设置运行时项目输出目录位置
set_target_properties(${EXE_6_NAME} PROPERTIES
                      RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${EXE_6_NAME})
#----------------------------------------------------------------------------------------------
#可执行文件七-----------------------------------------------------------------------------------
set(EXE_7_NAME exe_blinn_phong)
file(
    GLOB EXE_7_SOURCES
    src/blinn_phong.cpp
)

# 链接可执行文件
add_executable(${EXE_7_NAME} ${EXE_7_SOURCES} ${PROJECT_HEADERS}
                             ${PROJECT_SHADERS} ${VENDORS_SOURCES})

# 链接库
target_link_libraries(${EXE_7_NAME} assimp glfw ${GLAD_LIBRARIES})

# 设置运行时项目输出目录位置
set_target_properties(${EXE_7_NAME} PROPERTIES
                      RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${EXE_7_NAME})
#----------------------------------------------------------------------------------------------
#可执行文件八-----------------------------------------------------------------------------------
set(EXE_8_NAME exe_shadow_mapping)
file(
    GLOB EXE_8_SOURCES
    src/shadow_mapping.cpp
)

# 链接可执行文件
add_executable(${EXE_8_NAME} ${EXE_8_SOURCES} ${PROJECT_HEADERS}
                             ${PROJECT_SHADERS} ${VENDORS_SOURCES})

# 链接库
target_link_libraries(${EXE_8_NAME} assimp glfw ${GLAD_LIBRARIES})

# 设置运行时项目输出目录位置
set_target_properties(${EXE_8_NAME} PROPERTIES
                      RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${EXE_8_NAME})
#----------------------------------------------------------------------------------------------
#可执行文件九-----------------------------------------------------------------------------------
set(EXE_9_NAME exe_hdr)
file(
    GLOB EXE_9_SOURCES
    src/hdr.cpp
)

# 链接可执行文件
add_executable(${EXE_9_NAME} ${EXE_9_SOURCES} ${PROJECT_HEADERS}
                             ${PROJECT_SHADERS} ${VENDORS_SOURCES})

# 链接库
target_link_libraries(${EXE_9_NAME} assimp glfw ${GLAD_LIBRARIES})

# 设置运行时项目输出目录位置
set_target_properties(${EXE_9_NAME} PROPERTIES
                      RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${EXE_9_NAME})
#----------------------------------------------------------------------------------------------
#可执行文件十-----------------------------------------------------------------------------------
set(EXE_10_NAME exe_deferred)
file(
    GLOB EXE_10_SOURCES
    src/deferred.cpp
)

# 链接可执行文件
add_executable(${EXE_10_NAME} ${EXE_10_SOURCES} ${PROJECT_HEADERS}
                             ${PROJECT_SHADERS} ${VENDORS_SOURCES})

# 链接库
target_link_libraries(${EXE_10_NAME} assimp glfw ${GLAD_LIBRARIES})

# 设置运行时项目输出目录位置
set_target_properties(${EXE_10_NAME} PROPERTIES
                      RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${EXE_10_NAME})
#----------------------------------------------------------------------------------------------
#可执行文件十一-----------------------------------------------------------------------------------
set(EXE_11_NAME exe_pbr)
file(
    GLOB EXE_11_SOURCES
    src/pbr.cpp
)

# 链接可执行文件
add_executable(${EXE_11_NAME} ${EXE_11_SOURCES} ${PROJECT_HEADERS}
                             ${PROJECT_SHADERS} ${VENDORS_SOURCES})

# 链接库
target_link_libraries(${EXE_11_NAME} assimp glfw ${GLAD_LIBRARIES})

# 设置运行时项目输出目录位置
set_target_properties(${EXE_11_NAME} PROPERTIES
                      RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${EXE_11_NAME})
#----------------------------------------------------------------------------------------------