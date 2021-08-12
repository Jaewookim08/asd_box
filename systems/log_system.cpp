//
// Created by jaewoo on 21. 8. 7..
//

#include "log_system.h"
#include <iostream>

void asd_box::log_system::update() {
    auto current_time = m_time_manager.current_time();
    if (last_log_time + log_delay <= current_time) {
        std::cout << "Fps: " << m_time_manager.get_fps() << " Entities: "<< m_registry.alive() << '\n';
        last_log_time = current_time;
    }
}

asd_box::log_system::log_system(const entt::registry& registry,const asd_box::time_system& time_manager) :
        m_time_manager{time_manager}, m_registry{registry} {
}
