//
// Created by jaewoo on 21. 8. 7..
//

#include "time_manager.h"
#include <iostream>

void asd_box::time_manager::update(float dt) {
    m_current_time += dt;

    m_recent_frames_time_queue.push(m_current_time);
    while (m_recent_frames_time_queue.size() > recent_frames_save_count) {
        m_recent_frames_time_queue.pop();
    }

    if (last_fps_printed_time + fps_print_delay <= m_current_time) {
        std::cout << "Fps: " << get_fps() << '\n';
        last_fps_printed_time = m_current_time;
    }
}

double asd_box::time_manager::current_time() const {
    return m_current_time;
}

float asd_box::time_manager::get_fps() {
    if (m_recent_frames_time_queue.size() <= 1) {
        return 0.f;
    }

    auto diff = static_cast<float>(m_recent_frames_time_queue.back() - m_recent_frames_time_queue.front());
    return static_cast<float>(m_recent_frames_time_queue.size() - 1) / diff;
}
