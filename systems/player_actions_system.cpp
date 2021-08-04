//
// Created by jaewoo on 21. 8. 2..
//

#include <entt/entity/registry.hpp>
#include "player_actions_system.h"
#include "components/main_character.h"
#include "components/transform/transform.h"
#include "components/transform/transform_handler.h"
#include "components/movement.h"
#include <glm/glm.hpp>
#include <glm/gtx/norm.hpp>
#include <iostream>
#include <components/sprite_renderer.h>


namespace {
    void move_main_update(entt::registry& registry, auto check_key, float dt) {
        auto move_vec = glm::vec2{0.f};

        if (check_key(GLFW_KEY_LEFT)) {
            move_vec.x -= 1.f;
        }
        if (check_key(GLFW_KEY_RIGHT)) {
            move_vec.x += 1.f;
        }
        if (check_key(GLFW_KEY_UP)) {
            move_vec.y += 1.f;
        }
        if (check_key(GLFW_KEY_DOWN)) {
            move_vec.y -= 1.f;
        }
        move_vec = glm::length2(move_vec) < 0.0001 ?
                   move_vec :
                   glm::normalize(move_vec);

        for (auto&&[entity, main, transform] : registry.view<dhoot::main_character, asd_box::transform>().each()) {
            auto transform_handler = asd_box::transform_handler{registry, entity, transform};
            transform_handler.translation_property += glm::vec3{move_vec, 0.f} * main.speed * dt;
        }
    }
}

dhoot::player_actions_system::player_actions_system(entt::registry& registry,
                                                    const asd_box::input_manager& input_manager) :
        m_registry{registry}, m_input_manager{input_manager} {
}

void dhoot::player_actions_system::update(float dt) {
//    std::cout << dt << '\n';

    auto check_key = [this](int key) {
        return m_input_manager.check_key(key);
    };
    move_main_update(m_registry, check_key, dt);
    shoot_update(dt);
}

entt::entity dhoot::player_actions_system::shoot_bullet(glm::vec3 initial_pos) {
    auto made = m_registry.create();
    m_registry.emplace<asd_box::transform>(made, asd_box::transform{initial_pos});
    m_registry.emplace<dhoot::movement>(made, dhoot::movement{.velocity = bullet_velocity});
    m_registry.emplace<asd_box::sprite_renderer>(
            made, asd_box::sprite_renderer{bullet_texture_path, bullet_color, bullet_size});
}

void dhoot::player_actions_system::shoot_update(float dt) {
    if (m_input_manager.check_key_pressed(GLFW_KEY_X)) {
        for (auto&&[entity, main, transform] : m_registry.view<dhoot::main_character, asd_box::transform>().each()) {
            auto transform_handler = asd_box::transform_handler{m_registry, entity, transform};

            shoot_bullet(transform_handler.get_translation() - glm::vec3{0.f, 0.f, 2.f});
        }
    }
}
