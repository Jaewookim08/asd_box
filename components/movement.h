//
// Created by jaewoo on 21. 8. 4..
//

#ifndef ASD_BOX_MOVEMENT_H
#define ASD_BOX_MOVEMENT_H

#include <glm/glm.hpp>

namespace dhoot {
    struct movement {
        glm::vec3 velocity{0.f};
        float friction{0.f};
    };
}

#endif //ASD_BOX_MOVEMENT_H
