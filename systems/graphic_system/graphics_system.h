//
// Created by jaewoo on 21. 7. 12..
//

#ifndef ASD_BOX_GRAPHICS_SYSTEM_H
#define ASD_BOX_GRAPHICS_SYSTEM_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <string>
#include <entt/entt.hpp>
#include <resource_loaders/gl_texture_loader.h>
#include "learnopengl/shader.h"

namespace asd_box {

    class graphics_system {
        static constexpr auto background_color = glm::vec4{0.f, 0.f, 0.f, 1.f};
    public:
        explicit graphics_system(entt::registry& registry, Shader texture_shader);

        void initialize_gl_settings(int initial_screen_width, int initial_screen_height);

//        void framebuffer_size_event(int width, int height);

        void update(float dt);

        void render();
    private:
        entt::registry& m_registry;
        const Shader m_texture_shader;
        const unsigned int m_draw_texture_vao;
        gl_texture_cache m_texture_cache{};
    };
}

// Todo: vao raii 클래스 추가.

#endif //ASD_BOX_GRAPHICS_SYSTEM_H
