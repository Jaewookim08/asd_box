//
// Created by jaewoo on 21. 8. 2..
//

#ifndef ASD_BOX_TRANSFORM_HANDLER_H
#define ASD_BOX_TRANSFORM_HANDLER_H

#include <entt/entt.hpp>
#include "transform.h"

namespace asd_box {
    class transform_handler {
    public:
        transform_handler(entt::registry& registry, entt::entity entity, transform& transform);
        transform_handler(entt::registry& registry, entt::entity entity);

        [[nodiscard]]glm::vec3 get_translation() const;

        [[nodiscard]]glm::quat get_rotation() const;

        [[nodiscard]]glm::vec3 get_scale() const;

        void set_translation(glm::vec3 translation);

        void set_rotation(glm::quat rotation);

        void set_scale(glm::vec3 scale);


        [[nodiscard]] glm::mat4 get_transform_matrix();

        [[nodiscard]] glm::mat4 get_world_transform_matrix();

        void set_parent(entt::entity new_parent);

    private:
        void set_dirty();

        entt::registry& m_registry;
        entt::entity m_entity;
        asd_box::transform& m_transform;
    };
}

#endif //ASD_BOX_TRANSFORM_HANDLER_H
