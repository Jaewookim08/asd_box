//
// Created by jaewoo on 22. 1. 7..
//

#include "box2d_system.h"
#include "components/transform/transform_handler.h"
#include <glm/gtx/quaternion.hpp>

using asd_box::box2d::box2d_system;

namespace {
    b2Vec2 convert_to_box2d_vec(const glm::vec3& pos) {
        return b2Vec2{pos.x, pos.y};
    }
}


box2d_system::box2d_system(entt::registry& registry) : m_registry{registry} {

}

void box2d_system::update(asd_box::time dt) {
    // transform -> box2d
    for (auto&&[entity, body, transform]: m_registry.group<body>(entt::get<asd_box::transform>).each()) {
        auto transform_handler = asd_box::transform_handler{m_registry, entity, transform};
        auto pos = transform_handler.get_world_translation();
        auto qua = transform_handler.get_world_rotation();
        auto z_angle = glm::eulerAngles(qua).z;   // box2d_system removes all rotations except for those respect to z axis

        auto raw_body = body.get_raw();
        raw_body->SetTransform(convert_to_box2d_vec(pos), z_angle);
    }

    // step
    m_world.Step(dt.val, velocity_iterations, position_iterations);

    // box2d -> transform
    for (auto&&[entity, body, transform]: m_registry.group<body>(entt::get<asd_box::transform>).each()) {
        auto transform_handler = asd_box::transform_handler{m_registry, entity, transform};
        auto pos = transform_handler.get_translation();
        auto b2_transform = body.get_raw()->GetTransform();

        auto trans = transform_handler.get_translation();
        trans.x = b2_transform.p.x;
        trans.y = b2_transform.p.y;
        transform_handler.set_translation(trans);


        auto euler_angles = glm::vec3{0, 0, b2_transform.q.GetAngle()};
        auto quat = glm::quat{euler_angles};
        transform_handler.set_rotation(quat);
    }
}

asd_box::box2d::body& box2d_system::add_body(entt::entity entity, const box2d_system::body_def_t* body_def) {
    using asd_box::box2d::body;

    if (m_registry.all_of<body>(entity)) {
        throw std::runtime_error{"Cannot add body to the entity. Entity already has a body."};
    }

    return m_registry.emplace<body>(entity, body{&m_world, body_def});
}

void asd_box::box2d::box2d_system::remove_body(entt::entity entity) {
    m_registry.remove<body>(entity);
}
