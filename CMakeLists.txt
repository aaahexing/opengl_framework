# CMake entry point
cmake_minimum_required(VERSION 2.8)
project(OpenGL_Framework)

# CMake Pre-check.
if(CMAKE_BINARY_DIR STREQUAL CMAKE_SOURCE_DIR)
    message(FATAL_ERROR "Please select another Build Directory ! (and give it a clever name, like bin_Visual2012_64bits/)")
endif()
if(CMAKE_SOURCE_DIR MATCHES " ")
    message( "Your Source Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()
if(CMAKE_BINARY_DIR MATCHES " ")
    message( "Your Build Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()

# To use the fixed cmake-modules.
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake-modules/")
include(CreateLaunchers)

find_package(OpenGL REQUIRED)

include_directories(
    third_party/AntTweakBar-1.16/include/
    third_party/glfw-3.1.2/include/GLFW/
    third_party/glm-0.9.7.1/
    third_party/glew-1.13.0/include/
    .
)

set(ALL_LIBS
    ${OPENGL_LIBRARY}
    glfw
    GLEW_1130
)

add_definitions(
    -DTW_STATIC
    -DTW_NO_LIB_PRAGMA
    -DTW_NO_DIRECT3D
    -DGLEW_STATIC
    -D_CRT_SECURE_NO_WARNINGS
)

# The main entry.
add_executable(main
    src/main.cpp
)
target_link_libraries(main
    ${ALL_LIBS}
)
create_target_launcher(main WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

SOURCE_GROUP(common REGULAR_EXPRESSION ".*/common/.*" )
SOURCE_GROUP(shaders REGULAR_EXPRESSION ".*/.*shader$" )

# Compile the third_party dependencies.
add_subdirectory(third_party)
