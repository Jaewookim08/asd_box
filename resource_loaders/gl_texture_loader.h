//
// Created by jaewoo on 21. 7. 25..
//

#ifndef ASD_BOX_GL_TEXTURE_LOADER_H
#define ASD_BOX_GL_TEXTURE_LOADER_H

#include <entt/entt.hpp>
#include <gl_texture.h>

namespace asd_box {
    struct gl_texture_loader final : entt::resource_loader<gl_texture_loader, gl_texture> {
        [[nodiscard]] std::shared_ptr<gl_texture> load(const std::string& filepath) const;
    };
    using gl_texture_cache = entt::resource_cache<gl_texture>;
}


#endif //ASD_BOX_GL_TEXTURE_LOADER_H
