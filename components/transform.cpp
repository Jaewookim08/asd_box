//
// Created by jaewoo on 21. 7. 21..
//

#include "transform.h"
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>

glm::mat4 asd_box::transform::model_matrix() {
    constexpr auto identity = glm::mat4{1.f};
    return glm::translate(identity, translation) * glm::mat4x4{rotation} * glm::scale(identity, scale);
}
