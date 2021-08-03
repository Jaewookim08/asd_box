//
// Created by jaewoo on 21. 7. 25..
//

#include "sprite_renderer.h"

asd_box::sprite_renderer::sprite_renderer(std::string texture_filepath, glm::vec4 color, glm::vec2 size)
        : texture_filepath{
        std::move(texture_filepath)}, color{color}, size{size} {

}
