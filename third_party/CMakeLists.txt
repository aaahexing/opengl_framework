add_definitions(
    -DTW_STATIC
    -DTW_NO_LIB_PRAGMA
    -DTW_NO_DIRECT3D
    -DGLEW_STATIC
    -D_CRT_SECURE_NO_WARNINGS
)

### GLFW ###

add_subdirectory(glfw-3.1.2)

include_directories(
	glfw-3.1.2/include/GLFW/
	glew-1.13.0/include/
)

if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    set(OPENGL_LIBRARY
        ${OPENGL_LIBRARY}
        -lGL -lGLU -lXrandr -lXext -lX11 -lrt
        ${CMAKE_DL_LIBS}
        ${GLFW_LIBRARIES}
    )
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set(OPENGL_LIBRARY
        ${OPENGL_LIBRARY}
        ${CMAKE_DL_LIBS}
        ${GLFW_LIBRARIES}
    )
endif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")

### GLEW ###

set(GLEW_SOURCE
    glew-1.13.0/src/glew.c
)

set(GLEW_HEADERS
)


add_library(GLEW_1130 STATIC
    ${GLEW_SOURCE}
    ${GLEW_INCLUDE}
)

target_link_libraries(GLEW_1130
    ${OPENGL_LIBRARY}
    ${EXTRA_LIBS}
)

### ANTTWEAKBAR ###

set(ANTTWEAKBAR_SOURCE
    AntTweakBar-1.16/src/LoadOGL.cpp
    AntTweakBar-1.16/src/LoadOGLCore.cpp
    AntTweakBar-1.16/src/TwColors.cpp
    AntTweakBar-1.16/src/TwBar.cpp
    AntTweakBar-1.16/src/TwEventGLFW.c
    AntTweakBar-1.16/src/TwFonts.cpp
    AntTweakBar-1.16/src/TwMgr.cpp
    AntTweakBar-1.16/src/TwOpenGL.cpp
    AntTweakBar-1.16/src/TwOpenGLCore.cpp
    AntTweakBar-1.16/src/TwPrecomp.cpp
)

include_directories(
    ${CMAKE_SOURCE_DIR}/external/AntTweakBar-1.16/src/
)
add_definitions(
    -D_MACOSX
)
if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    add_definitions(
        -D_UNIX
    )
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    add_definitions(
        -D_WINDOWS
    )
endif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")

set(ANTTWEAKBAR_HEADERS
    AntTweakBar-1.16/src/AntPerfTimer.h
    AntTweakBar-1.16/src/LoadOGL.h
    AntTweakBar-1.16/src/LoadOGLCore.h
    AntTweakBar-1.16/src/MiniGLFW.h
    AntTweakBar-1.16/src/resource.h
    AntTweakBar-1.16/src/TwBar.h
    AntTweakBar-1.16/src/TwColors.h
    AntTweakBar-1.16/src/TwFonts.h
    AntTweakBar-1.16/src/TwGraph.h
    AntTweakBar-1.16/src/TwMgr.h
    AntTweakBar-1.16/src/TwOpenGL.h
    AntTweakBar-1.16/src/TwOpenGLCore.h
    AntTweakBar-1.16/src/TwPrecomp.h
)

include_directories(
    AntTweakBar-1.16/include/
)

add_library(ANTTWEAKBAR_116_OGLCORE_GLFW STATIC
    ${ANTTWEAKBAR_SOURCE}
    ${ANTTWEAKBAR_HEADERS}
)

target_link_libraries(ANTTWEAKBAR_116_OGLCORE_GLFW
    ${OPENGL_LIBRARY}
    ${EXTRA_LIBS}
)
