cmake_minimum_required(VERSION 3.19)
project(asd_box VERSION 1.0
        DESCRIPTION "Toy project to make game engine with opengl and entt"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

add_executable(asd_box main.cpp systems/graphic_system/graphics_system.cpp systems/graphic_system/graphics_system.h
        game.cpp game.h components/transform.cpp components/transform.h
        tools/texture.cpp tools/texture.h tools/stb_image.cpp resource_loaders/gl_texture_loader.cpp resource_loaders/gl_texture_loader.h components/sprite_renderer.cpp components/sprite_renderer.h tools/gl_texture.cpp tools/gl_texture.h components/camera.cpp components/camera.h)

find_package(OpenGL REQUIRED)

add_subdirectory(submodules/glfw)
add_subdirectory(submodules/glad)
add_subdirectory(submodules/glm)
add_subdirectory(submodules/entt)

target_include_directories(asd_box PRIVATE ./ ./tools ${OPENGL_INCLUDE_DIRS} ./external)
target_link_libraries(asd_box PRIVATE glfw glad glm EnTT::EnTT)