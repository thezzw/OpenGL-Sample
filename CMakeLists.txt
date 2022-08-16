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
)

# 收集项目文件
file(GLOB VENDORS_SOURCES lib/glad/src/glad.c)

file(GLOB PROJECT_HEADERS include/*.hpp
                          include/*.h)

file(GLOB PROJECT_SOURCES src/*.cpp)

file(GLOB PROJECT_SHADERS res/*.f
                          res/*.v)

source_group("headers" FILES ${PROJECT_HEADERS})
source_group("shaders" FILES ${PROJECT_SHADERS})
source_group("sources" FILES ${PROJECT_SOURCES})
source_group("vendors" FILES ${VENDORS_SOURCES})

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES} ${PROJECT_HEADERS}
                               ${PROJECT_SHADERS} ${VENDORS_SOURCES})

target_link_libraries(${PROJECT_NAME} assimp glfw ${GLAD_LIBRARIES})

set_target_properties(${PROJECT_NAME} PROPERTIES
                      RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PROJECT_NAME})