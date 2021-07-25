//
// Created by jaewoo on 21. 7. 12..
//

#include "graphics_system.h"

#include <stdexcept>
#include "components/triangle_renderer.h"
#include "components/transform.h"

using asd_box::graphics_system;

static unsigned int gl_generate_vertex_arrays(){
    unsigned int vao;
    glGenVertexArrays(1, &vao);
    return vao;
}

asd_box::graphics_system::graphics_system(entt::registry& registry, Shader simple_triangle_shader) :
        m_registry{registry},
        m_simple_triangle_shader{std::move(simple_triangle_shader)},
        m_test_triangle_vao{gl_generate_vertex_arrays()} { // NOLINT(performance-move-const-arg)

    {
        // make test triangle
        glBindVertexArray(m_test_triangle_vao);

        unsigned int VBO;
        glGenBuffers(1, &VBO);

        static constexpr float vertices[] = {
                -0.5f, -0.5f, 0.0f, // left
                0.5f, -0.5f, 0.0f, // right
                0.0f,  0.5f, 0.0f  // top
        };

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
        glBindBuffer(GL_ARRAY_BUFFER, 0);


        // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
        // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
//        glBindVertexArray(0);
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
    using namespace asd_box;

    glClearColor(0.f, 1.f, 1.f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    {
        // draw triangles
        m_simple_triangle_shader.use();

        glBindVertexArray(m_test_triangle_vao);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        for (auto&&[entity, transform, triangle_render]:  m_registry.view<transform, triangle_renderer>().each()) {

        }
    }
}

void asd_box::graphics_system::update(float dt) {

}

