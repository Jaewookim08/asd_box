//
// Created by jaewoo on 21. 8. 7..
//

#ifndef ASD_BOX_LOG_SYSTEM_H
#define ASD_BOX_LOG_SYSTEM_H

#include "systems/time_system.h"
#include <entt/entt.hpp>

namespace asd_box {
    class log_system {
        static constexpr auto log_delay = 0.3f;
    public:
        log_system(const entt::registry& registry, const asd_box::time_system& time_manager);
        void update();

    private:
        const asd_box::time_system& m_time_manager;
        const entt::registry& m_registry;
        double last_log_time = 0;
    };
}


#endif //ASD_BOX_LOG_SYSTEM_H
