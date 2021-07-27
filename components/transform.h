//
// Created by jaewoo on 21. 7. 21..
//

#ifndef ASD_BOX_TRANSFORM_H
#define ASD_BOX_TRANSFORM_H

#include <glm/glm.hpp>
#include <glm/detail/type_quat.hpp>

namespace asd_box {
    class transform {
    public:
        explicit transform(glm::vec3 translation = {}, glm::quat rotation = {}, glm::vec3 scale = {1.f, 1.f, 1.f});

        glm::vec3 translation;
        glm::quat rotation;
        glm::vec3 scale;

        [[nodiscard]] glm::mat4 get_transform_matrix();

        [[nodiscard]] glm::mat4 get_world_transform_matrix();

    private:
        glm::mat4 world_transform_matrix_cache = {};
        bool dirty_flag = false;
    };
}


#endif //ASD_BOX_TRANSFORM_H
