//
// Created by jaewoo on 21. 7. 25..
//

#ifndef ASD_BOX_SPRITE_RENDERER_H
#define ASD_BOX_SPRITE_RENDERER_H

#include <entt/entt.hpp>
#include <iostream>
#include "texture.h"
#include "resource_loaders/gl_texture_loader.h"
#include <glm/glm.hpp>

namespace asd_box {
    // Todo: depth 추가.
    struct sprite_renderer {
        sprite_renderer(std::string texture_filepath, glm::vec4 color, glm::vec2 size);

        std::string texture_filepath;   // Todo: hash로 바꾼 다음 settings에 매핑 추가하자. 너무 메모리 많이 먹는다.
        glm::vec4 color;
        glm::vec2 size;

        entt::resource_handle<gl_texture> texture_handle; // texture handle cache

        template<class Archive>
        void serialize(Archive & ar);
    };
    template<class Archive>
    void sprite_renderer::serialize(Archive& ar) {
        using namespace std::string_literals;
        ar("sprite_renderer_data_placeholder"s);
    }

}


#endif //ASD_BOX_SPRITE_RENDERER_H
