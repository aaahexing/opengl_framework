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

# Add a compiler flag
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

### OpenGL

find_package(OpenGL REQUIRED)

### QT 4.8

find_package(Qt4 REQUIRED QtCore QtGui QtOpenGL)
include(${QT_USE_FILE})

include_directories(${QT_INCLUDES})

add_definitions(${QT_DEFINITIONS})

set(QT_USE_QTOPENGL TRUE)

set(ALL_LIBS
    ${OPENGL_LIBRARY}
    ${QT_QTCORE_LIBRARIES}
    ${QT_QTGUI_LIBRARIES}
    ${QT_QTOPENGL_LIBRARIES}
    glfw
    GLEW_1130
)

# Compile the third_party dependencies.
add_subdirectory(third_party)
add_subdirectory(src)

# Create the launcher file for the main entry-point.
create_target_launcher(main WORKING_DIRECTORY "${CMAKE_BINARY_DIR}")

