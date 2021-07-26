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
        glm::vec3 translation{};
        glm::quat rotation;
        glm::vec3 scale = {1.f, 1.f, 1.f};

        glm::mat4 model_matrix();
    };
}


#endif //ASD_BOX_TRANSFORM_H
