cmake_minimum_required(VERSION 3.5)
project(learnGraphics C CXX)


add_library(shader STATIC
	lib/shaders/src/shader.cpp
)

target_include_directories(shader PUBLIC
lib/shaders/include
)

add_library(glad STATIC
  lib/glad/src/glad.c
)

target_include_directories(glad PUBLIC
  lib/glad/include
)

add_library(stb STATIC
	lib/stb/stb_image.cpp
)

target_include_directories(stb PUBLIC
	lib/stb
)

add_library(glm INTERFACE)
target_include_directories(glm INTERFACE 
	lib/glm
)

add_executable(learnGraphics
  src/main.cpp
)
target_link_libraries( learnGraphics
  glad
  glfw
  shader
  stb
  glm
)
