//
// Created by jaewoo on 21. 8. 4..
//

#ifndef ASD_BOX_PHYSICS_SYSTEM_H
#define ASD_BOX_PHYSICS_SYSTEM_H

#include <entt/entt.hpp>

namespace dhoot {
    class physics_system {
    public:
        explicit physics_system(entt::registry& registry);
        void update(float dt);

    private:
        entt::registry& m_registry;
    };
}

#endif //ASD_BOX_PHYSICS_SYSTEM_H
