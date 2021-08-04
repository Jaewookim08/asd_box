//
// Created by jaewoo on 21. 8. 4..
//

#include "physics_system.h"
#include <components/transform/transform.h>
#include <components/transform/transform_handler.h>
#include <components/movement.h>
//#include <glm/gtc/epsilon.hpp>
#include <glm/gtx/norm.hpp>

dhoot::physics_system::physics_system(entt::registry& registry)
        : m_registry{registry} {
}

void dhoot::physics_system::update(float dt) {
    // Apply velocity
    m_registry.view<asd_box::transform, dhoot::movement>().each([&](auto entity, auto& transform, auto& movement) {
        auto transform_handler = asd_box::transform_handler{m_registry, entity, transform};

        transform_handler.translation_property += movement.velocity * dt;
    });

    // Apply friction
    m_registry.view<dhoot::movement>().each([&](dhoot::movement& movement) {
        auto&& velocity = movement.velocity;
        auto friction = movement.friction * dt;
        if (friction < 0.0000001f) {
            return;
        }

        if (glm::length2(velocity) <= friction * friction) {
            velocity = {};
        } else {
            velocity = glm::normalize(velocity) * std::max(glm::length(movement.velocity) - friction, 0.f);
        }
    });
}
