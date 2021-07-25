//
// Created by jaewoo on 21. 7. 12..
//

#include "graphics_system.h"

#include <stdexcept>
#include <components/sprite_renderer.h>
#include "components/triangle_renderer.h"
#include "components/transform.h"

using asd_box::graphics_system;

static unsigned int gl_generate_vertex_arrays() {
    unsigned int vao;
    glGenVertexArrays(1, &vao);
    return vao;
}

asd_box::graphics_system::graphics_system(entt::registry& registry, Shader simple_triangle_shader,
                                          Shader texture_shader) :
        m_registry{registry},
        m_simple_triangle_shader{std::move(simple_triangle_shader)}, // NOLINT(performance-move-const-arg)
        m_texture_shader{std::move(texture_shader)}, // NOLINT(performance-move-const-arg)
        m_test_triangle_vao{gl_generate_vertex_arrays()},
        m_draw_texture_vao{gl_generate_vertex_arrays()} {


    stbi_set_flip_vertically_on_load(true);

    {
        // make test triangle
        glBindVertexArray(m_test_triangle_vao);

        unsigned int VBO;
        glGenBuffers(1, &VBO);

        static constexpr float vertices[] = {
                -0.5f, -0.5f, 0.0f, // left
                0.5f, -0.5f, 0.0f, // right
                0.0f, 0.5f, 0.0f  // top
        };

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*) 0);
        glEnableVertexAttribArray(0);

        // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
        glBindBuffer(GL_ARRAY_BUFFER, 0);


        // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
        // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
//        glBindVertexArray(0);
    }

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

void graphics_system::initialize_gl_settings(int initial_screen_width, int initial_screen_height) {
    // OpenGL configuration
    // --------------------
    glViewport(0, 0, initial_screen_width, initial_screen_height);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void asd_box::graphics_system::framebuffer_size_event(int width, int height) {
    glViewport(0, 0, width, height);
}

void asd_box::graphics_system::render() {
    glClearColor(0.f, 1.f, 1.f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//    {
//        // draw triangles
//        m_simple_triangle_shader.use();
//
//        glBindVertexArray(m_test_triangle_vao);
//        glDrawArrays(GL_TRIANGLES, 0, 3);
//
//        for (auto&&[entity, transform, triangle_render]:  m_registry.view<transform, triangle_renderer>().each()) {
//
//        }
//    }

    {
        // draw sprites
        for (auto&&[entity, sprite_renderer]: m_registry.view<asd_box::sprite_renderer>().each()) {
            // load texture
            const auto& filepath = sprite_renderer.texture_filepath;
            auto& texture_handle = sprite_renderer.texture_handle;
            texture_handle = texture_handle ? texture_handle :
                             m_texture_cache.load<gl_texture_loader>(entt::hashed_string{filepath.c_str()}, filepath);

            if (!texture_handle) {
                throw std::runtime_error("Failed to get texture texture_handle");
            }

            // render texture

            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, texture_handle->texture_id);

            m_texture_shader.use();
            m_texture_shader.setVec4("color", sprite_renderer.color);
            glBindVertexArray(m_draw_texture_vao);

            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        }
    }
}

void asd_box::graphics_system::update(float dt) {

}

