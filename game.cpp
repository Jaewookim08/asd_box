//
// Created by jaewoo on 21. 7. 12..
//

#include "game.h"
#include "components/transform/transform.h"
#include "components/sprite_renderer.h"
#include "components/movement.h"
#include "components/camera.h"

#include <string>
#include <systems/save_manager.h>
#include <components/transform/transform_handler.h>
#include <components/main_character.h>

void dhoot::game::key_event(int key, int scancode, int action, int mode) {
    m_input_manager.key_event(key, action, mode);
}


void dhoot::game::framebuffer_size_event(int width, int height) {

}

void dhoot::game::update(float dt) {
    if (m_input_manager.check_key_pressed(GLFW_KEY_P)) {
        m_paused = !m_paused;
    }

    if (!m_paused) {
        m_graphics_system.update(dt);
        m_player_actions_system.update(dt);
        m_physics_system.update(dt);
    }

    m_input_manager.next_frame();
}

void dhoot::game::initialize_screen(int initial_screen_width, int initial_screen_height) {
    m_graphics_system.initialize_gl_settings(initial_screen_width, initial_screen_height);
}

void dhoot::game::render() {
    m_graphics_system.render();
}

void dhoot::game::generate_test_entities() {
    auto objects = std::array<entt::entity, 2>{};
    m_registry.create(objects.begin(), objects.end());

    for (int i = 0; i < 2; i++) {
        m_registry.emplace<asd_box::transform>(objects[i],
                                               asd_box::transform{glm::vec3{-100.f, 0.f, 0.f},
                                                                  glm::identity<glm::quat>(),
                                                                  glm::vec3{1.0, 1.0, 1.0}});
//        m_registry.emplace<dhoot::movement>(objects[i], dhoot::movement{
//            .friction = 5000.f,
//        });

        m_registry.emplace<asd_box::sprite_renderer>(objects[i],
                                                     asd_box::sprite_renderer{"awesomeface.png",
                                                                              glm::vec<4, float>{1.0f * i, 1.f, 0.f,
                                                                                                 1.f},
                                                                              glm::vec2{50.f, 50.f}});
    }
    asd_box::transform_handler{m_registry, objects[0]}.set_parent(objects[1]);
    m_registry.emplace<dhoot::main_character>(objects[1], dhoot::main_character{.speed = 500.f});

    auto cam = m_registry.create();
    m_registry.emplace<asd_box::transform>(cam,
                                           asd_box::transform{glm::vec3{0.f, 0.f, 300.0f},
                                                              glm::identity<glm::quat>(),
                                                              glm::vec3{1.0, 1.0, 1.0}});

//        m_registry.emplace<camera>(cam, camera{perspective_camera{glm::radians(60.f), 800.f / 600.f, 0.1f, 100.f}});
    m_registry.emplace<asd_box::camera>(cam, asd_box::camera{
            asd_box::orthographic_camera{-400.0f, 400.0f, -300.0f, 300.0f, 1.f, 1000.f}});

    {
        auto sm = asd_box::save_manager{};
        auto output = std::ofstream{"test.json"};
        sm.save(m_registry, output);
    }
}

dhoot::game::game()
        : m_registry{},
          m_graphics_system{m_registry, Shader{texture_vshader_name, texture_fshader_name}} {
}


