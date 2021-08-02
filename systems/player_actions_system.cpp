//
// Created by jaewoo on 21. 8. 2..
//

#include <entt/entity/registry.hpp>
#include "player_actions_system.h"
#include "components/main_character.h"
#include "components/transform/transform.h"
#include "components/transform/transform_handler.h"
#include <glm/glm.hpp>
#include <glm/gtc/epsilon.hpp>
#include <glm/gtx/norm.hpp>

dhoot::player_actions_system::player_actions_system(entt::registry& registry,
                                                    const asd_box::input_manager& input_manager) :
        m_registry{registry}, m_input_manager{input_manager} {
}

void dhoot::player_actions_system::update(float dt) {
    auto move_vec = glm::vec2{0.f};
    auto key = [this](int key) {
        return m_input_manager.check_key(key);
    };

    if (key(GLFW_KEY_LEFT)) {
        move_vec.x -= 1.f;
    }
    if (key(GLFW_KEY_RIGHT)) {
        move_vec.x += 1.f;
    }
    if (key(GLFW_KEY_UP)) {
        move_vec.y += 1.f;
    }
    if (key(GLFW_KEY_DOWN)) {
        move_vec.y -= 1.f;
    }
    move_vec = glm::length2(move_vec) < 0.0001 ?
               move_vec :
               glm::normalize(move_vec);

    for (auto&&[entity, main, transform] : m_registry.view<dhoot::main_character, asd_box::transform>().each()) {
        auto transform_handler = asd_box::transform_handler{m_registry, entity, transform};
        transform_handler.translation_property += glm::vec3{move_vec, 0.f} * main.speed * dt;
    }
}
