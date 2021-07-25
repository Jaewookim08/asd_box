//
// Created by jaewoo on 21. 7. 25..
//

#include "sprite_renderer.h"

asd_box::sprite_renderer::sprite_renderer(std::string texture_filepath, glm::vec<4, float> color) : texture_filepath{
        std::move(texture_filepath)}, color{color} {

}
