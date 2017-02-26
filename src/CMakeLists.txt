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

set(EXTERNAL_LIBS
    ${OPENGL_LIBRARY}
    ${QT_QTCORE_LIBRARIES}
    ${QT_QTGUI_LIBRARIES}
    ${QT_QTOPENGL_LIBRARIES}
    glfw
    GLEW_1130
)

# @TODO(xinghe): For debugging purpose.
# message("SSSSS : ${QT_QTGUI_LIBRARIES}, ${QT_QTOPENGL_LIBRARIES}, ${QT_MOC_HPP}")

add_subdirectory(core)
add_subdirectory(gui)
# Build the plugins
add_subdirectory(plugins)

# The main entry.
add_executable(main
    main.cpp
)
# @TODO(xinghe): the order below is important? It will fail to build if
# put the ${EXTERNAL_LIBS} ahead...
target_link_libraries(main
    core
    gui
    ${EXTERNAL_LIBS}
)
set_target_properties(main
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
)

# SOURCE_GROUP(common REGULAR_EXPRESSION ".*/common/.*" )
# SOURCE_GROUP(shaders REGULAR_EXPRESSION ".*/.*shader$" )
