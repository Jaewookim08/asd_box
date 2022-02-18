//
// Created by jaewoo on 22. 1. 7..
//

#include "box2d_system.h"

using asd_box::box2d::box2d_system;
using asd_box::box2d::body;

box2d_system::box2d_system(entt::registry& registry) : m_registry{registry} {

}

void box2d_system::update(float dt) {
    m_world.Step(dt, velocity_iterations, position_iterations);
}

body& box2d_system::add_body(entt::entity entity, const asd_box::box2d::box2d_system::body_def_t* body_def) {
    throw std::runtime_error{"Todo"};
}
