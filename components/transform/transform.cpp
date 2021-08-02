//
// Created by jaewoo on 21. 7. 21..
//

#include "transform.h"
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <stack>



asd_box::transform::transform(glm::vec3 translation, glm::quat rotation, glm::vec3 scale) :
        m_translation{translation}, m_rotation{rotation}, m_scale{scale} {

}


