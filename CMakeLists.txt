cmake_minimum_required(VERSION 3.10)
project(LearnOpenGL)

set(CMAKE_CXX_STANDARD 17)

# Add your source file(s)
add_executable(hello_window 
  src/main.cpp 
  src/glad.c
)

# Tell CMake where to find headers and libs
target_include_directories(hello_window PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(hello_window PRIVATE
    ${CMAKE_SOURCE_DIR}/lib/libglfw3.a
    "-framework Cocoa"
    "-framework OpenGL"
    "-framework IOKit"
    "-framework CoreVideo"
)
