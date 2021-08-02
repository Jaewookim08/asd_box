//
// Created by jaewoo on 21. 8. 2..
//

#ifndef ASD_BOX_PLAYER_ACTIONS_SYSTEM_H
#define ASD_BOX_PLAYER_ACTIONS_SYSTEM_H

#include <entt/entt.hpp>
#include "systems/input_manager.h"

namespace dhoot {
    class player_actions_system {
    public:
        player_actions_system(entt::registry& registry,
                              const asd_box::input_manager& input_manager);

        void update(float dt);

    private:
        const asd_box::input_manager& m_input_manager;
        entt::registry & m_registry;
    };
}


#endif //ASD_BOX_PLAYER_ACTIONS_SYSTEM_H
