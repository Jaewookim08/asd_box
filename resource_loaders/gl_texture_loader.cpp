//
// Created by jaewoo on 21. 7. 25..
//

#include <iostream>
#include "gl_texture_loader.h"

namespace asd_box {
    std::shared_ptr<gl_texture> asd_box::gl_texture_loader::load(const std::string& filepath) const{
        std::cout << "texture loaded : " << filepath << '\n';
        return std::make_shared<gl_texture>(filepath);
    }
}
