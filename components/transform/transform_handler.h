//
// Created by jaewoo on 21. 8. 2..
//

#ifndef ASD_BOX_TRANSFORM_HANDLER_H
#define ASD_BOX_TRANSFORM_HANDLER_H

#include <entt/entt.hpp>
#include "transform.h"
#include "tools/property.h"

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

        asd_box::tools::member_property<transform_handler,
                &transform_handler::get_translation, &transform_handler::set_translation>
                translation_property{this};

        asd_box::tools::member_property<transform_handler,
                &transform_handler::get_rotation, &transform_handler::set_rotation>
                rotation_property{this};
        asd_box::tools::member_property<transform_handler,
                &transform_handler::get_scale, &transform_handler::set_scale>
                scale_property{this};

        void set_parent(entt::entity new_parent);

    private:
        void set_dirty();

        entt::registry& m_registry;
        entt::entity m_entity;
        asd_box::transform& m_transform;
    };
}

#endif //ASD_BOX_TRANSFORM_HANDLER_H
