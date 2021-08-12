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
        m_time_system.update(dt);
        m_graphics_system.update(dt);
        m_player_actions_system.update(dt, m_time_system.current_time());
        m_physics_system.update(dt);
        m_log_system.update();
    }

    m_input_manager.next_frame();
}

void dhoot::game::initialize_screen() {
    m_graphics_system.initialize_gl_settings(m_screen_width, m_screen_height);
}

void dhoot::game::render() {
    m_graphics_system.render();
}

void dhoot::game::generate_test_entities() {

    auto main_character = m_registry.create();
    {
        m_registry.emplace<asd_box::transform>(main_character,
                                               asd_box::transform{glm::vec3{0.f, 0.f, 0.f},
                                                                  glm::vec3{0.f, 0.f, glm::radians(45.f)}});
        m_registry.emplace<asd_box::sprite_renderer>(main_character,
                                                     asd_box::sprite_renderer{"main_character_inner_square.png",
                                                                              glm::vec2{50.f, 50.f}});
        m_registry.emplace<dhoot::main_character>(main_character, dhoot::main_character{.speed = 500.f});
    }


    auto main_character_outer_ring = m_registry.create();
    {
        m_registry.emplace<asd_box::transform>(main_character_outer_ring,
                                               glm::vec3{0.f, 0.f, 0.f});
        m_registry.emplace<asd_box::sprite_renderer>(main_character_outer_ring,
                                                     asd_box::sprite_renderer{"main_character_outer_ring.png",
                                                                              glm::vec2{50.f, 50.f}});
        m_registry.emplace<dhoot::movement>(main_character_outer_ring,
                                            dhoot::movement{.angular_velocity=glm::vec3{0.f, 0.f, 10000}});

        asd_box::transform_handler{m_registry, main_character_outer_ring}.set_parent(main_character);
    }

    auto cam = m_registry.create();
    {
        m_registry.emplace<asd_box::transform>(cam,
                                               asd_box::transform{glm::vec3{0.f, 0.f, 300.0f},
                                                                  glm::identity<glm::quat>(),
                                                                  glm::vec3{1.0, 1.0, 1.0}});

//        m_registry.emplace<camera>(cam, camera{perspective_camera{glm::radians(60.f), 800.f / 600.f, 0.1f, 100.f}});

        auto camera_half_width = static_cast<float>(m_screen_width) / 2;
        auto camera_half_heigth = static_cast<float>(m_screen_height) / 2;

        m_registry.emplace<asd_box::camera>(cam, asd_box::camera{
                asd_box::orthographic_camera{-camera_half_width, camera_half_width,
                                             -camera_half_heigth, camera_half_heigth, 1.f, 1000.f}});
    }

    {
        auto sm = asd_box::save_manager{};
        auto output = std::ofstream{"test.json"};
        sm.save(m_registry, output);
    }
}

dhoot::game::game(int screen_width, int screen_height) :
        m_registry{},
        m_graphics_system{
                m_registry,
                Shader{texture_vshader_name, texture_fshader_name},
                Shader{bullet_vshader_name, bullet_fshader_name}},
        m_screen_width{screen_width},
        m_screen_height{screen_height} {
}



