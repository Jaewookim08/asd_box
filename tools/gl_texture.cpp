//
// Created by jaewoo on 21. 7. 26..
//

#include "gl_texture.h"
#include "texture.h"
#include "glad/glad.h"

namespace {
    unsigned int generate_texture(){
        unsigned int tex;
        glGenTextures(1, &tex);
        return tex;
    }
}

asd_box::gl_texture::gl_texture(const std::string& path): texture_id{generate_texture()} {
    glBindTexture(GL_TEXTURE_2D, texture_id);

    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // load image, create texture and generate mipmaps
    auto texture  = asd_box::texture{path};
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texture.width, texture.height, 0, GL_RGBA, GL_UNSIGNED_BYTE, texture.get_data());
    glGenerateMipmap(GL_TEXTURE_2D);
}

asd_box::gl_texture::~gl_texture() {
    glDeleteTextures(1, &texture_id);
}
