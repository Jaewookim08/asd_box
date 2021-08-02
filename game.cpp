//
// Created by jaewoo on 21. 7. 12..
//

#include "game.h"
#include "components/transform/transform.h"
#include "components/sprite_renderer.h"
#include "components/camera.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <vector>
#include <stdexcept>
#include <systems/save_manager.h>
#include <components/transform/transform_handler.h>

using asd_box::game;


void asd_box::game::key_event(int key, int scancode, int action, int mode) {
    m_input_manager.key_event(key, action, mode);
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

    auto objects = std::array<entt::entity, 3>{};
    m_registry.create(objects.begin(), objects.end());

    for (int i = 0; i < 2; i++) {
        m_registry.emplace<transform>(objects[i],
                                      transform{glm::vec3{-0.2f, 0.f, 0.f},
                                                glm::identity<glm::quat>(),
                                                glm::vec3{1.0, 1.0, 1.0}});

        m_registry.emplace<sprite_renderer>(objects[i],
                                            sprite_renderer{"assets/awesomeface.png",
                                                            glm::vec<4, float>{1.0f * i, 1.f, 0.f, 0.2f}});
    }
    transform_handler{m_registry, objects[0]}.set_parent(objects[1]);

    auto cam = m_registry.create();
    m_registry.emplace<transform>(cam,
                                  transform{glm::vec3{0.f, 0.f, 3.0f},
                                            glm::identity<glm::quat>(),
                                            glm::vec3{1.0, 1.0, 1.0}});

//        m_registry.emplace<camera>(cam, camera{perspective_camera{glm::radians(60.f), 800.f / 600.f, 0.1f, 100.f}});
    m_registry.emplace<camera>(cam, camera{orthographic_camera{-4.0f, 4.0f, -3.0f, 3.0f, 0.1f, 100.f}});

    {
        auto sm = asd_box::save_manager{};
        auto output = std::ofstream{"test.json"};
        sm.save(m_registry, output);
    }
}

asd_box::game::game()
        : m_registry{},
          m_graphics_system{m_registry, Shader{texture_vshader_name, texture_fshader_name}} {
}


