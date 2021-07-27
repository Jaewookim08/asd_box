//
// Created by jaewoo on 21. 7. 21..
//

#include "transform.h"
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>

glm::mat4 asd_box::transform::get_transform_matrix() {
    constexpr auto identity = glm::mat4{1.f};
    return glm::translate(identity, translation) * glm::mat4x4{rotation} * glm::scale(identity, scale);
}

glm::mat4 asd_box::transform::get_world_transform_matrix() {
    return get_transform_matrix();
}

asd_box::transform::transform(glm::vec3 translation, glm::quat rotation, glm::vec3 scale) :
        translation{translation}, rotation{rotation}, scale{scale} {

}
