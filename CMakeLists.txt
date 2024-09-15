cmake_minimum_required(VERSION 3.10)

# Project name
project(intro_opengl)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 23)

# Set the policy for OpenGL
if (POLICY CMP0072)
    cmake_policy(SET CMP0072 NEW)
endif()

# Find OpenGL
find_package(OpenGL REQUIRED)

# Find GLEW
find_package(GLEW REQUIRED)

# Find GLFW
find_package(glfw3 REQUIRED)

# Add the source files
set(SOURCES src/main.cpp
        src/shaderClass.cpp
        src/VAO.cpp
        src/VBO.cpp
        src/EBO.cpp
)

# Include directories
include_directories(
        ${CMAKE_SOURCE_DIR}/Libraries/include
        ${CMAKE_SOURCE_DIR}/Resources/shaders
        ${CMAKE_SOURCE_DIR}/Headers
        ${OPENGL_INCLUDE_DIRS}
        ${GLEW_INCLUDE_DIRS}
)

# GLAD source file
set(GLAD_SOURCES ${CMAKE_SOURCE_DIR}/src/glad.c)

# Add executable
add_executable(intro_opengl ${SOURCES} ${GLAD_SOURCES})

# Link libraries
target_link_libraries(intro_opengl
        ${OPENGL_LIBRARIES}
        GLEW::GLEW
        glfw
)

file(COPY ${CMAKE_SOURCE_DIR}/Resources/shaders DESTINATION ${CMAKE_BINARY_DIR})
