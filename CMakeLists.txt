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

include_directories(
    third_party/AntTweakBar-1.16/include/
    third_party/glfw-3.1.2/include/GLFW/
    third_party/glm-0.9.7.1/
    third_party/glew-1.13.0/include/
    .
)

add_definitions(
    -DTW_STATIC
    -DTW_NO_LIB_PRAGMA
    -DTW_NO_DIRECT3D
    -DGLEW_STATIC
    -D_CRT_SECURE_NO_WARNINGS
)

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

file(GLOB QT_FORMS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} src/gui/*.ui)
file(GLOB QT_RESOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} src/gui/resources/*.qrc)
file(GLOB_RECURSE QT_MOC RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} FOLLOW_SYMLINKS src/gui/*.h)
file(GLOB_RECURSE QT_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} FOLLOW_SYMLINKS src/gui/*.cpp)

QT4_ADD_RESOURCES(QT_RESOURCES_CPP ${QT_RESOURCES})
QT4_WRAP_UI(QT_FORMS_HPP ${QT_FORMS})
QT4_WRAP_CPP(QT_MOC_HPP ${QT_MOC})

# @TODO(xinghe): For debugging purpose.
# message("SSSSS : ${QT_QTGUI_LIBRARIES}, ${QT_QTOPENGL_LIBRARIES}, ${QT_MOC_HPP}")

# The main entry.
add_executable(main
    src/main.cpp
    ${QT_MOC_HPP}
    ${QT_SOURCES}
)
target_link_libraries(main
    ${ALL_LIBS}
)
create_target_launcher(main WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

SOURCE_GROUP(common REGULAR_EXPRESSION ".*/common/.*" )
SOURCE_GROUP(shaders REGULAR_EXPRESSION ".*/.*shader$" )

# Compile the third_party dependencies.
add_subdirectory(third_party)
