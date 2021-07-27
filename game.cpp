//
// Created by jaewoo on 21. 7. 12..
//

#include "game.h"
#include "components/transform.h"
#include "components/sprite_renderer.h"
#include "components/camera.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <vector>
#include <stdexcept>

using asd_box::game;


void asd_box::game::key_event(int key, int scancode, int action, int mode) {
    // when a user presses the escape key, we set the WindowShouldClose property to true, closing the application

//    if (key >= 0 && key < 1024)
//    {
//        if (action == GLFW_PRESS)
//            Breakout.Keys[key] = true;
//        else if (action == GLFW_RELEASE)
//        {
//            Breakout.Keys[key] = false;
//            Breakout.KeysProcessed[key] = false;
//        }
//    }
}

void asd_box::game::framebuffer_size_event(int width, int height) {

}

void asd_box::game::update(float delta_time) {
    m_graphics_system.update(delta_time);
}

void asd_box::game::initialize_screen(int initial_screen_width, int initial_screen_height) {
    m_graphics_system.initialize_gl_settings(initial_screen_width, initial_screen_height);
}

void asd_box::game::render() {
    m_graphics_system.render();
}

void asd_box::game::generate_test_entities() {
    using namespace asd_box;

    for (int i = 0; i < 2; i++) {
        auto entity1 = m_registry.create();
        m_registry.emplace<transform>(entity1,
                                      transform{glm::vec3{0.1f, 0.f, 0.f},
                                                glm::quat{glm::vec3{0, 0, glm::pi<float>()}},
                                                glm::vec3{1.0,  1.0,  1.0}});

        m_registry.emplace<sprite_renderer>(entity1,
                                            sprite_renderer{"assets/awesomeface.png",
                                                            glm::vec<4, float>{0.f, 1.f, 0.f, 0.2f}});

        auto cam = m_registry.create();
        m_registry.emplace<transform>(cam,
                                      transform{glm::vec3{-0.5f, 0.f, 0.5f},
                                                glm::quat{},
                                                glm::vec3{1.0,  1.0,  1.0}});

        m_registry.emplace<camera>(cam, camera{});
    }
}

asd_box::game::game()
        : m_registry{},
          m_graphics_system{m_registry, Shader{texture_vshader_name, texture_fshader_name}} {
}


