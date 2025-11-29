cmake_minimum_required(VERSION 3.10)
project(LearnOpenGL)

set(CMAKE_CXX_STANDARD 17)

# ============================================================
# Helper function to build an OpenGL lesson
# ============================================================
function(add_lesson TARGET_NAME)
    add_executable(${TARGET_NAME}
        ${ARGN}
        ${CMAKE_SOURCE_DIR}/src/glad.c
    )

    target_include_directories(${TARGET_NAME} PRIVATE
        ${CMAKE_SOURCE_DIR}/include
    )

    target_link_libraries(${TARGET_NAME} PRIVATE
        ${CMAKE_SOURCE_DIR}/lib/libglfw3.a
        "-framework Cocoa"
        "-framework OpenGL"
        "-framework IOKit"
        "-framework CoreVideo"
    )
endfunction()


# ============================================================
# Collect shader files so we can copy them for Shaders_Tutorial
# ============================================================
file(GLOB SHADER_FILES
    "${CMAKE_SOURCE_DIR}/src/Shaders/*.vs"
    "${CMAKE_SOURCE_DIR}/src/Shaders/*.fs"
)


# ============================================================
# Lesson executables
# ============================================================

# Latest demo
add_lesson(latest src/main.cpp)

# Hello Triangle
add_lesson(hello_triangle
    src/HelloTriangle_Tutorial/main.cpp
)

# Shaders tutorial
add_lesson(shaders_tutorial
    src/Shaders_Tutorial/main.cpp
    src/Shaders_Tutorial/shader.cpp
)


# ============================================================
# Copy shaders *into the build folder of the shaders_tutorial*
# ============================================================
add_custom_command(
    TARGET shaders_tutorial POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_SOURCE_DIR}/src/Shaders"
        "$<TARGET_FILE_DIR:shaders_tutorial>"
)
