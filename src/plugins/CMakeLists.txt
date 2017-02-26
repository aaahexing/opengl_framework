file(GLOB_RECURSE PLUGINS_HEADERS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} FOLLOW_SYMLINKS ./*.h)

# Generate "$lib{plugin_name}.so" for each pair of source file.
foreach(plugin_h ${PLUGINS_HEADERS})
    get_filename_component (plugin_name ${plugin_h} NAME_WE)
    get_filename_component (plugin_path ${plugin_h} PATH)
    QT4_WRAP_CPP(${plugin_name}_WRAPED_HEADER ${plugin_h})
    set(plugin_cpp "${plugin_path}/${plugin_name}.cpp")
    add_library(${plugin_name}
        SHARED
        ${plugin_path}/${plugin_name}.cpp
        ${${plugin_name}_WRAPED_HEADER})
    target_link_libraries(${plugin_name} ${ALL_LIBS})
    set_target_properties(${plugin_name}
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/plugins"
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/plugins"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/plugins"
    )
    # message("${CMAKE_BINARY_DIR}: ${plugin_name}, ${plugin_h}, ${plugin_cpp}, ${${plugin_name}_WRAPED_HEADER}")
endforeach()
