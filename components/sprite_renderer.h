//
// Created by jaewoo on 21. 7. 25..
//

#ifndef ASD_BOX_SPRITE_RENDERER_H
#define ASD_BOX_SPRITE_RENDERER_H

#include <entt/entt.hpp>
#include <iostream>
#include "texture.h"
#include "resource_loaders/gl_texture_loader.h"
#include <glm/common.hpp>

namespace asd_box {
    struct sprite_renderer {
        sprite_renderer(std::string texture_filepath, glm::vec<4, float> color);

        std::string texture_filepath;   // Todo: hash로 바꾼 다음 settings에 매핑 추가하자. 너무 메모리 많이 먹는다.
        glm::vec<4, float> color;

        entt::resource_handle<gl_texture> texture_handle; // texture handle cache
    };
}


#endif //ASD_BOX_SPRITE_RENDERER_H
