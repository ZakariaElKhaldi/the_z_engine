cmake_minimum_required(VERSION 3.5)
project(zengine CXX)

add_library(glad STATIC vendor/glad/src/glad.c)
target_include_directories(glad PUBLIC vendor/glad/include)

add_library(stb STATIC vendor/stb/stb_image.cpp)

target_include_directories(stb PUBLIC vendor/stb)

add_library(glm INTERFACE)
target_include_directories(glm INTERFACE vendor/glm)

add_executable( zengine
  src/main.cpp
)

target_include_directories( engine
	src/window/include
	src/shader/include
	src/input/include
	src/events/include
	src/core/include
	src/camera/include
	src/ui/include
)

target_link_libraries( zengine 

  glad
  glfw
  stb
  glm

  engine

)
