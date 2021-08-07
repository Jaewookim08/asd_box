//
// Created by jaewoo on 21. 7. 12..
//

#include "graphics_system.h"

#include <iostream>
#include <stdexcept>
#include <components/sprite_renderer.h>
#include "components/transform/transform.h"
#include "components/camera.h"
#include <glm/ext.hpp>
#include <components/transform/transform_handler.h>

using asd_box::graphics_system;

namespace {
    unsigned int gl_generate_vertex_arrays() {
        unsigned int vao;
        glGenVertexArrays(1, &vao);
        return vao;
    }

    std::ostream& operator<<(std::ostream& stream, const glm::vec4& vec) {
        return stream << vec.x << " " << vec.y << " " << vec.z << " " << vec.w;
    }

}

asd_box::graphics_system::graphics_system(entt::registry& registry, Shader texture_shader) :
        m_registry{registry},
        m_texture_shader{std::move(texture_shader)}, // NOLINT(performance-move-const-arg)
        m_draw_texture_vao{gl_generate_vertex_arrays()} {


    stbi_set_flip_vertically_on_load(true);

    {
        // make texture draw vbo
        float vertices[] = {
                // positions      // texture coords
                0.5f, 0.5f, 0.0f, 1.0f, 1.0f,   // top right
                0.5f, -0.5f, 0.0f, 1.0f, 0.0f,   // bottom right
                -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,   // bottom left
                -0.5f, 0.5f, 0.0f, 0.0f, 1.0f    // top left
        };
        unsigned int indices[] = {
                0, 1, 3, // first triangle
                1, 2, 3  // second triangle
        };
        unsigned int VBO, EBO;
        glGenBuffers(1, &VBO);
        glGenBuffers(1, &EBO);

        glBindVertexArray(m_draw_texture_vao);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

        // position attribute
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*) 0);
        glEnableVertexAttribArray(0);
        // texture coord attribute
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*) (3 * sizeof(float)));
        glEnableVertexAttribArray(1);


        m_texture_shader.use(); // don't forget to activate/use the shader before setting uniforms!
        m_texture_shader.setInt("texture", 0);      // Todo: 0 대신 constant로
    }
}

void graphics_system::initialize_gl_settings(int initial_screen_width,
                                             int initial_screen_height) { // NOLINT(readability-convert-member-functions-to-static)
    // OpenGL configuration
    // --------------------
    glViewport(0, 0, initial_screen_width, initial_screen_height);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_MULTISAMPLE);
}

//void asd_box::graphics_system::framebuffer_size_event(int width,
//                                                      int height) { // NOLINT(readability-convert-member-functions-to-static)
//    glViewport(0, 0, width, height);
//}


static void draw_sprites(entt::registry& registry, asd_box::gl_texture_cache& texture_cache, const Shader& shader,
                         unsigned int vao, const glm::mat4& view_matrix, const glm::mat4& projection_matrix) {

    for (auto&&[entity, transform, sprite_renderer]: registry.view<asd_box::transform, asd_box::sprite_renderer>().each()) {
        // load texture
        const auto& filepath = sprite_renderer.texture_filepath;
        auto& texture_handle = sprite_renderer.texture_handle;
        texture_handle = texture_handle ? texture_handle :
                         texture_cache.load<asd_box::gl_texture_loader>(entt::hashed_string{filepath.c_str()},
                                                                        filepath);

        if (!texture_handle) {
            throw std::runtime_error("Failed to get texture texture_handle");
        }

        // render texture

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture_handle->texture_id);

        shader.use();
        shader.setVec4("color", sprite_renderer.color);

        auto transform_handler = asd_box::transform_handler{registry, entity, transform};
        shader.setMat4("uModelViewMatrix", view_matrix * transform_handler.get_world_transform_matrix());
        shader.setMat4("uProjectionMatrix", projection_matrix);
        shader.setVec2("uSpriteSize", sprite_renderer.size);
        glBindVertexArray(vao);

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    }
}

void asd_box::graphics_system::render() {
    glClearColor(background_color.r, background_color.g, background_color.b, background_color.a);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    for (auto&&[camera_entity, camera_transform, camera]: m_registry.view<asd_box::transform, asd_box::camera>().each()) {
        auto transform_handler = asd_box::transform_handler{m_registry, camera_entity, camera_transform};
        auto view_matrix = glm::inverse(transform_handler.get_world_transform_matrix());
        auto projection_matrix = camera.get_projection_matrix();

        draw_sprites(m_registry, m_texture_cache, m_texture_shader, m_draw_texture_vao, view_matrix, projection_matrix);
    }
}

void asd_box::graphics_system::update(float dt) {
}


