cmake_minimum_required(VERSION 3.19)
project(asd_box VERSION 1.0
        DESCRIPTION "Toy project to make game engine with opengl and entt"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

add_executable(asd_box main.cpp systems/graphic_system/graphics_system.cpp systems/graphic_system/graphics_system.h game.cpp game.h )

find_package(OpenGL REQUIRED)

add_subdirectory(submodules/glfw)
add_subdirectory(submodules/glad)
add_subdirectory(submodules/glm)

target_include_directories(asd_box PRIVATE ${OPENGL_INCLUDE_DIRS})

target_link_libraries(asd_box PRIVATE glfw glad)