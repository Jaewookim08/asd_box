//
// Created by jaewoo on 21. 8. 2..
//

#include "transform_handler.h"
#include <glm/gtx/quaternion.hpp>
#include <glm/gtx/matrix_decompose.hpp>


asd_box::transform_handler::transform_handler(entt::registry& registry, entt::entity entity,
                                              asd_box::transform& transform) :
        m_registry{registry}, m_entity{entity}, m_transform{transform} {
}

asd_box::transform_handler::transform_handler(entt::registry& registry, entt::entity entity) :
        m_registry{registry}, m_entity{entity}, m_transform{registry.get<transform>(entity)} {
}


glm::mat4 asd_box::transform_handler::get_transform_matrix() const{
    static constexpr auto identity = glm::mat4{1.f};
    return glm::translate(identity, m_transform.m_translation) * glm::mat4{m_transform.m_rotation} *
           glm::scale(identity, m_transform.m_scale);
    // Todo: 최적화.
}

glm::mat4 asd_box::transform_handler::get_world_transform_matrix() const{
    if (m_transform.m_dirty_flag) {
        auto parent = m_transform.m_parent;
        auto parent_transform_matrix = (m_registry.valid(parent)) ?
                                       transform_handler{m_registry, parent}.get_world_transform_matrix() :
                                       glm::identity<glm::mat4>();

        m_transform.m_world_transform_matrix_cache = parent_transform_matrix * get_transform_matrix();
        m_transform.m_dirty_flag = false;
    }

    return m_transform.m_world_transform_matrix_cache;
}


glm::vec3 asd_box::transform_handler::get_translation() const {
    return m_transform.m_translation;
}

glm::quat asd_box::transform_handler::get_rotation() const {
    return m_transform.m_rotation;
}

glm::vec3 asd_box::transform_handler::get_scale() const {
    return m_transform.m_scale;
}

void asd_box::transform_handler::set_translation(glm::vec3 translation) {
    m_transform.m_translation = translation;
    set_dirty();
}

void asd_box::transform_handler::set_rotation(glm::quat rotation) {
    m_transform.m_rotation = rotation;
    set_dirty();
}

void asd_box::transform_handler::set_scale(glm::vec3 scale) {
    m_transform.m_scale = scale;
    set_dirty();
}

void asd_box::transform_handler::set_parent(entt::entity new_parent) {
    if (auto prev_parent = m_transform.m_parent; m_registry.valid(prev_parent)) {
        m_registry.get<transform>(prev_parent).m_children.erase(m_entity);
    }

    m_transform.m_parent = new_parent;
    m_registry.get<transform>(new_parent).m_children.insert(m_entity);

    set_dirty();
}

void asd_box::transform_handler::set_dirty() {
    auto& dirty_flag = m_transform.m_dirty_flag;

    if (!dirty_flag) {
        for (auto child: m_transform.m_children) {
            transform_handler{m_registry, child}.set_dirty();
        }
    }
    m_transform.m_dirty_flag = true;
}
namespace {
    std::tuple<glm::vec3, glm::quat, glm::vec3> decompose_matrix(const glm::mat4& matrix) {
        glm::vec3 translation;
        glm::vec3 scale;
        glm::quat rotation;
        glm::vec3 skew;
        glm::vec4 perspective;
        glm::decompose(matrix, scale, rotation, translation, skew, perspective);
        rotation = glm::conjugate(rotation);
        return std::tuple{translation, rotation, scale};
    }
}
glm::vec3 asd_box::transform_handler::get_world_translation() const {
    return std::get<0>(decompose_matrix(get_world_transform_matrix()));
}

glm::quat asd_box::transform_handler::get_world_rotation() const {
    return std::get<1>(decompose_matrix(get_world_transform_matrix()));
}

glm::vec3 asd_box::transform_handler::get_world_scale() const {
    return std::get<2>(decompose_matrix(get_world_transform_matrix()));
}

