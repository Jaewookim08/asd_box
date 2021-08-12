//
// Created by jaewoo on 21. 8. 12..
//

#ifndef ASD_BOX_BULLET_RENDERER_H
#define ASD_BOX_BULLET_RENDERER_H

#include <string>
#include <glm/glm.hpp>
#include <entt/entt.hpp>
#include <gl_texture.h>
#include "sprite_renderer.h"

namespace dhoot{
    struct bullet_renderer {
        bullet_renderer(asd_box::sprite_renderer sprite_renderer, glm::vec3 start_position,
                        glm::vec3 shoot_direction);

        glm::vec3 start_local_position;
        glm::vec3 shoot_direction;
        asd_box::sprite_renderer sprite_renderer;
    };
}


#endif //ASD_BOX_BULLET_RENDERER_H
