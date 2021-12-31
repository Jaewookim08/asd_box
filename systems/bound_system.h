//
// Created by jaewoo on 21. 12. 31..
//

#ifndef ASD_BOX_BOUND_SYSTEM_H
#define ASD_BOX_BOUND_SYSTEM_H

#include <entt/entt.hpp>
#include <glm/glm.hpp>

namespace dhoot {
    class bound_system {
    public:
        explicit bound_system(entt::registry& registry, glm::vec2 screen_bottom_left, glm::vec2 screen_top_right);
        void update(float dt);
    private:
        glm::vec2 m_screen_bottom_left;
        glm::vec2 m_screen_top_right;
        entt::registry& m_registry;
    };
}


#endif //ASD_BOX_BOUND_SYSTEM_H
