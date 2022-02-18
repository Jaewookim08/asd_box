//
// Created by jaewoo on 21. 8. 7..
//

#include "log_system.h"
#include <iostream>

void asd_box::log_system::update(double current_time, float fps) {
    if (last_log_time + log_delay <= current_time) {
        std::cout << "Fps: " << fps << " Entities: " << m_registry.alive() << '\n';
        last_log_time = current_time;
    }
}

asd_box::log_system::log_system(const entt::registry& registry) : m_registry{registry} {
}
