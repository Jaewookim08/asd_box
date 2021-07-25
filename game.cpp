//
// Created by jaewoo on 21. 7. 12..
//

#include "game.h"
#include "components/transform.h"
#include "components/triangle_renderer.h"

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
    auto entity1 = m_registry.create();
    m_registry.emplace<transform>(entity1, transform{.translation = {0, 0, 0}});
    m_registry.emplace<triangle_renderer>(entity1, triangle_renderer{.triangle={glm::vec<3, float>{1.f, 0.f, 0.f},
                                                                                {0.f, 1.f, 0.f},
                                                                                {0.f, 0.f, 0.f}}, .color={1.f, 0.f,
                                                                                                          0.f}});
}

asd_box::game::game()
        : m_registry{},
          m_graphics_system{m_registry, Shader{simple_triangle_vshader_name, simple_triangle_fshader_name}} {
}


