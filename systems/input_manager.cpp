//
// Created by jaewoo on 21. 8. 2..
//

#include "input_manager.h"
#include <cassert>

void asd_box::input_manager::key_event(int key, int action, int mode) {
    assert(0 <= key && key <= GLFW_KEY_LAST);

    if (action == GLFW_PRESS) {
        current_key_state()[key] = true;
    } else if (action == GLFW_RELEASE) {
        current_key_state()[key] = false;
    }
}

void asd_box::input_manager::next_frame() {
    m_current_buffer_index = 1 - m_current_buffer_index;
    current_key_state() = prev_key_state();
}

bool asd_box::input_manager::check_key(int key) const {
    return current_key_state()[key];
}

bool asd_box::input_manager::check_key_pressed(int key) const {
    return current_key_state()[key] && !prev_key_state()[key];
}

bool asd_box::input_manager::check_key_released(int key) const{
    return !current_key_state()[key] && prev_key_state()[key];
}


asd_box::input_manager::key_state& asd_box::input_manager::current_key_state() {
    return m_buffers[m_current_buffer_index];
}

const asd_box::input_manager::key_state& asd_box::input_manager::current_key_state() const {
    return m_buffers[m_current_buffer_index];;
}


asd_box::input_manager::key_state& asd_box::input_manager::prev_key_state() {
    return m_buffers[1 - m_current_buffer_index];
}

const asd_box::input_manager::key_state& asd_box::input_manager::prev_key_state() const {
    return m_buffers[1 - m_current_buffer_index];
}


