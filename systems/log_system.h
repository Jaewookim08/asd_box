//
// Created by jaewoo on 21. 8. 7..
//

#ifndef ASD_BOX_LOG_SYSTEM_H
#define ASD_BOX_LOG_SYSTEM_H

#include "systems/time_system.h"
#include <entt/entt.hpp>

namespace asd_box {
    class log_system {
        static constexpr auto log_delay = asd_box::time{0.3f};
    public:
        explicit log_system(const entt::registry& registry);

        void update(time current_time, float fps);

    private:
        const entt::registry& m_registry;
        asd_box::time last_log_time{0};
    };
}


#endif //ASD_BOX_LOG_SYSTEM_H
