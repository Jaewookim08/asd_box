//
// Created by jaewoo on 21. 8. 12..
//

#include "bullet_renderer.h"

dhoot::bullet_renderer::bullet_renderer(asd_box::sprite_renderer sprite_renderer, glm::vec3 start_position,
                                        glm::vec3 shoot_direction)
        : sprite_renderer{std::move(sprite_renderer)}, start_local_position{start_position}, shoot_direction{shoot_direction} {}
