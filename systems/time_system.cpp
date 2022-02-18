//
// Created by jaewoo on 21. 8. 7..
//

#include "time_system.h"


void asd_box::time_system::update(time dt) {
    m_current_time += dt;

    m_recent_frames_time_queue.push(m_current_time);
    while (m_recent_frames_time_queue.size() > recent_frames_save_count) {
        m_recent_frames_time_queue.pop();
    }

}

asd_box::time asd_box::time_system::current_time() const {
    return m_current_time;
}

float asd_box::time_system::get_fps() const{
    if (m_recent_frames_time_queue.size() <= 1) {
        return 0.f;
    }

    auto diff = m_recent_frames_time_queue.back() - m_recent_frames_time_queue.front();
    return static_cast<float>(m_recent_frames_time_queue.size() - 1) / diff.val;
}
