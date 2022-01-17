//
// Created by jaewoo on 22. 1. 7..
//

#ifndef ASD_BOX_BOX2D_SYSTEM_H
#define ASD_BOX_BOX2D_SYSTEM_H

#include <box2d/box2d.h>

namespace asd_box {
    class box2d_system {
    public:
        box2d_system() = default;

    private:
        b2World world{b2Vec2_zero};
    };
}


#endif //ASD_BOX_BOX2D_SYSTEM_H
