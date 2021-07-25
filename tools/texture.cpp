//
// Created by jaewoo on 21. 7. 25..
//

#include "texture.h"
#include <stdexcept>

namespace {
    struct stb_load_result {
        int width;
        int height;
        int nr_channels;
        unsigned char* m_data;
    };
    stb_load_result load_texture(const std::string& filename) {
        auto result = stb_load_result{};
        unsigned char* data = stbi_load(filename.c_str(), &result.width, &result.height, &result.nr_channels, 0);
        if (!data){
            throw std::runtime_error("Failed to load texture from '" + filename + "': \n" + stbi_failure_reason());
        }
        result.m_data = data;
        return result;
    }
}

asd_box::texture_stb_image::texture_stb_image(const std::string& filename): texture_stb_image{load_texture(filename)} {

}
