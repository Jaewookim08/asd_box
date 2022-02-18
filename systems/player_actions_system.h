//
// Created by jaewoo on 21. 8. 2..
//

#ifndef ASD_BOX_PLAYER_ACTIONS_SYSTEM_H
#define ASD_BOX_PLAYER_ACTIONS_SYSTEM_H

#include <entt/entt.hpp>
#include <glm/glm.hpp>
#include "systems/input_manager.h"
#include "tools/time_type.h"

namespace dhoot {
    class player_actions_system {
        static constexpr auto bullet_velocity = glm::vec3{0.f, 1000.f, 0.f};
        static constexpr auto bullet_texture_path = "white.png";
        static constexpr auto bullet_color = glm::vec4{1.f, 1.f, 1.f, 1.f};
        static constexpr auto bullet_size = glm::vec2{6.f, 15.f};
        static constexpr auto shoot_delay = asd_box::time{0.08};

    public:
        player_actions_system(entt::registry& registry,
                              const asd_box::input_manager& input_manager);

        void update(asd_box::time dt, asd_box::time current_time);

    private:
        void shoot_update(asd_box::time dt, asd_box::time current_time);

        entt::entity shoot_bullet(glm::vec3 initial_pos);

        const asd_box::input_manager& m_input_manager;
        entt::registry& m_registry;

        asd_box::time m_last_shot_time{0};
    };
}


#endif //ASD_BOX_PLAYER_ACTIONS_SYSTEM_H
