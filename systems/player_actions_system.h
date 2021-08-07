//
// Created by jaewoo on 21. 8. 2..
//

#ifndef ASD_BOX_PLAYER_ACTIONS_SYSTEM_H
#define ASD_BOX_PLAYER_ACTIONS_SYSTEM_H

#include <entt/entt.hpp>
#include <glm/glm.hpp>
#include "systems/input_manager.h"

namespace dhoot {
    class player_actions_system {
        static constexpr auto bullet_velocity = glm::vec3{0.f, 1000.f, 0.f};
        static constexpr auto bullet_texture_path = "white.png";
        static constexpr auto bullet_color = glm::vec4{0.f, 0.f, 0.f, 1.f};
        static constexpr auto bullet_size = glm::vec2{8.f, 20.f};
        static constexpr auto shoot_delay = 0.25f;

    public:
        player_actions_system(entt::registry& registry,
                              const asd_box::input_manager& input_manager);

        void update(float dt);

    private:
        void shoot_update(float dt);
        entt::entity shoot_bullet(glm::vec3 initial_pos);

        const asd_box::input_manager& m_input_manager;
        entt::registry & m_registry;
    };
}


#endif //ASD_BOX_PLAYER_ACTIONS_SYSTEM_H
