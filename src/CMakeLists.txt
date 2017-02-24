### OpenGL

include_directories(
    ../third_party/AntTweakBar-1.16/include/
    ../third_party/glfw-3.1.2/include/GLFW/
    ../third_party/glm-0.9.7.1/
    ../third_party/glew-1.13.0/include/
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

add_definitions(${QT_DEFINITIONS})
include_directories(${QT_INCLUDES})

set(QT_USE_QTOPENGL TRUE)

### Build the project.
add_compile_options(--std=c++11)

set(ALL_LIBS
    ${OPENGL_LIBRARY}
    ${QT_QTCORE_LIBRARIES}
    ${QT_QTGUI_LIBRARIES}
    ${QT_QTOPENGL_LIBRARIES}
    glfw
    GLEW_1130
)

file(GLOB QT_FORMS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} gui/*.ui)
file(GLOB QT_RESOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} gui/resources/*.qrc)
file(GLOB_RECURSE QT_MOC RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} FOLLOW_SYMLINKS gui/*.h)
file(GLOB_RECURSE QT_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} FOLLOW_SYMLINKS gui/*.cpp)

QT4_ADD_RESOURCES(QT_RESOURCES_CPP ${QT_RESOURCES})
QT4_WRAP_UI(QT_FORMS_HPP ${QT_FORMS})
QT4_WRAP_CPP(QT_MOC_HPP ${QT_MOC})

# @TODO(xinghe): For debugging purpose.
# message("SSSSS : ${QT_QTGUI_LIBRARIES}, ${QT_QTOPENGL_LIBRARIES}, ${QT_MOC_HPP}")

# The main entry.
add_executable(main
    main.cpp
    ${QT_MOC_HPP}
    ${QT_SOURCES}
)
target_link_libraries(main
    ${ALL_LIBS}
)
# message("YYY: ${CMAKE_CURRENT_SOURCE_DIR}")
# message("YYY: ${CMAKE_SOURCE_DIR}")
# message("YYY: ${WORKING_DIRECTORY}")
# message("YYY: ${PROJECT_BINARY_DIR}")

# SOURCE_GROUP(common REGULAR_EXPRESSION ".*/common/.*" )
# SOURCE_GROUP(shaders REGULAR_EXPRESSION ".*/.*shader$" )
