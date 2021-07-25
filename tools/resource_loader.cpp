//
// Created by jaewoo on 21. 7. 25..
//

#include "resource_loader.h"
#include "stb_image.h"
#include <memory>


namespace asd_box {
    template<>
    texture resource_loader::load<texture>(const std::string& path) {
        return texture{path};
    }
}