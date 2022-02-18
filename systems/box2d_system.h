//
// Created by jaewoo on 22. 1. 7..
//

#ifndef ASD_BOX_BOX2D_SYSTEM_H
#define ASD_BOX_BOX2D_SYSTEM_H

#include <box2d/box2d.h>
#include <entt/entt.hpp>
#include <utility>
#include "components/box2d/body.h"
#include "tools/time_type.h"

namespace asd_box::box2d {
    class box2d_system {
    public:
        using body_def_t = b2BodyDef;

        explicit box2d_system(entt::registry& registry);

        void update(asd_box::time dt);

        body& add_body(entt::entity entity, const body_def_t* body_def);

    private:
        static constexpr int velocity_iterations = 8;
        static constexpr int position_iterations = 3;

        b2World m_world{b2Vec2_zero};
        entt::registry& m_registry;
    };
}


#endif //ASD_BOX_BOX2D_SYSTEM_H
