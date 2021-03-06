cmake_minimum_required(VERSION 3.19)
project(asd_box VERSION 1.0
        DESCRIPTION "Toy project to make game engine with opengl and entt"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)


add_executable(dhoot main.cpp systems/graphic_system/graphics_system.cpp systems/graphic_system/graphics_system.h
        game.cpp game.h components/transform/transform.cpp components/transform/transform.h
        tools/texture.cpp tools/texture.h tools/stb_image.cpp
        resource_loaders/gl_texture_loader.cpp resource_loaders/gl_texture_loader.h
        components/sprite_renderer.cpp components/sprite_renderer.h
        tools/gl_texture.cpp tools/gl_texture.h components/camera.cpp components/camera.h
        systems/save_manager.cpp systems/save_manager.h
        components/transform/transform_handler.cpp components/transform/transform_handler.h
        tools/property.cpp tools/property.h systems/input_manager.cpp systems/input_manager.h
        components/main_character.h systems/player_actions_system.cpp systems/player_actions_system.h
        components/movement.h systems/physics_system.cpp systems/physics_system.h
        systems/time_system.cpp systems/time_system.h systems/log_system.cpp systems/log_system.h
        components/bullet_renderer.cpp components/bullet_renderer.h components/bounded.h systems/bound_system.cpp
        systems/bound_system.h systems/box2d_system.cpp systems/box2d_system.h components/box2d/body.h
        components/box2d/body.cpp tools/time_type.h)

find_package(OpenGL REQUIRED)

add_subdirectory(submodules/glfw)
add_subdirectory(submodules/glad)
add_subdirectory(submodules/glm)
add_subdirectory(submodules/entt)

option(BOX2D_BUILD_TESTBED "Build the Box2D testbed" OFF)
add_subdirectory(submodules/box2d)

target_include_directories(dhoot PRIVATE ./  ${OPENGL_INCLUDE_DIRS} ./external)
target_link_libraries(dhoot PRIVATE glfw glad glm EnTT::EnTT box2d)