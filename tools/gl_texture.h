//
// Created by jaewoo on 21. 7. 26..
//

#ifndef ASD_BOX_GL_TEXTURE_H
#define ASD_BOX_GL_TEXTURE_H

#include <string>

namespace asd_box {
    class gl_texture {
    public:
        explicit gl_texture(const std::string& path);

        gl_texture(const gl_texture& other) = delete;

        gl_texture(gl_texture&& other) = delete;

        void operator=(const gl_texture& other) = delete;

        void operator=(gl_texture&& other) = delete;

        ~gl_texture();

        const unsigned int texture_id;

    private:
    };
}


#endif //ASD_BOX_GL_TEXTURE_H
