//
// Created by jaewoo on 21. 7. 25..
//

#ifndef ASD_BOX_TEXTURE_H
#define ASD_BOX_TEXTURE_H

#include <string>
#include <memory>
#include "stb_image.h"

namespace asd_box {
    class texture_stb_image {
    public:
        explicit texture_stb_image(const std::string& filename);

        const int width;
        const int height;
        const int nr_channels;

        [[nodiscard]] unsigned char* get_data();

    private:
        struct data_deleter {
            void operator()(void* ptr) {
                stbi_image_free(ptr);
            }
        };

        const std::unique_ptr<unsigned char, data_deleter> m_data;

        template<class T>
        explicit texture_stb_image(const T& as); // 나도 이게 맞는지 모르겠다 근데 다른 방법도 너무 맘에 안 듬
    };

    template<class T>
    texture_stb_image::texture_stb_image(const T& as): width{as.width}, height{as.height}, nr_channels{as.height},
                                                       m_data{as.m_data} {}


    using texture = texture_stb_image;
}


#endif //ASD_BOX_TEXTURE_H
