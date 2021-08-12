//
// Created by jaewoo on 21. 7. 25..
//

#include "sprite_renderer.h"

asd_box::sprite_renderer::sprite_renderer(std::string texture_filepath, glm::vec2 size, glm::vec4 color)
        : texture_filepath{
        std::move(texture_filepath)}, color{color}, size{size} {

}

entt::resource_handle<asd_box::gl_texture>
asd_box::sprite_renderer::get_texture_handle(asd_box::gl_texture_cache& texture_cache) {
    return m_texture_handle = m_texture_handle ? m_texture_handle :
                              texture_cache.load<asd_box::gl_texture_loader>(
                                      entt::hashed_string{texture_filepath.c_str()},
                                      texture_filepath);
}
