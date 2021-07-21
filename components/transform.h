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
        glm::vec<3, float> translation;
        glm::quat rotation;
    };
}


#endif //ASD_BOX_TRANSFORM_H
