//
// Created by jaewoo on 21. 8. 7..
//

#include "time_manager.h"

void asd_box::time_manager::update(float dt) {
    m_current_time += dt;
}

double asd_box::time_manager::current_time() const{
    return m_current_time;
}
