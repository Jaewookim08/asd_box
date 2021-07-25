//
// Created by jaewoo on 21. 7. 12..
//

#ifndef ASD_BOX_GRAPHICS_SYSTEM_H
#define ASD_BOX_GRAPHICS_SYSTEM_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <string>
#include <entt/entt.hpp>
#include "learnopengl/shader.h"

namespace asd_box {

    class graphics_system {
    public:
        explicit graphics_system(entt::registry& registry, Shader simple_triangle_shader);

        void initialize_gl_settings(int initial_screen_width, int initial_screen_height);

        void framebuffer_size_event(int width, int height);

        void update(float dt);

        void render();
    private:
        entt::registry& m_registry;
        const Shader m_simple_triangle_shader;
        const unsigned int m_test_triangle_vao;
    };
}


#endif //ASD_BOX_GRAPHICS_SYSTEM_H
