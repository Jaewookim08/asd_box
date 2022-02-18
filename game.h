//
// Created by jaewoo on 21. 7. 12..
//

#ifndef ASD_BOX_GAME_H
#define ASD_BOX_GAME_H


#include <string>
#include "systems/graphic_system/graphics_system.h"
#include "systems/box2d_system.h"
#include <entt/entt.hpp>
#include <systems/input_manager.h>
#include <systems/player_actions_system.h>
#include <systems/physics_system.h>
#include <systems/time_system.h>
#include <systems/log_system.h>
#include <systems/bound_system.h>

namespace dhoot {
    class game {
    private:
        // Todo: Settings import. setting 클래스 만든 다음 cereal로 불러 오지 뭐.
        static constexpr auto texture_vshader_name = "shaders/sprite.vsh";
        static constexpr auto texture_fshader_name = "shaders/sprite.fsh";
        static constexpr auto bullet_vshader_name = "shaders/bullet.vsh";
        static constexpr auto bullet_fshader_name = "shaders/bullet.fsh";

    public:
        game(int screen_width, int screen_height);

        game(const game& other) = delete;

        game(game&& other) = delete;

        game& operator=(const game& other) = delete;

        game& operator=(game&& other) = delete;

        void initialize_screen();

        void generate_test_entities();

        void key_event(int key, int scancode, int action, int mode);

        void framebuffer_size_event(int width, int height);

        void update(float dt);

        void render();

    private:
        const int m_screen_width;
        const int m_screen_height;

        asd_box::input_manager m_input_manager{};
        asd_box::graphics_system m_graphics_system;
        dhoot::player_actions_system m_player_actions_system{m_registry, m_input_manager};
        dhoot::physics_system m_physics_system{m_registry};
        entt::registry m_registry{};
        asd_box::time_system m_time_system{};
        asd_box::log_system m_log_system{m_registry, m_time_system};
        asd_box::box2d::box2d_system m_box2d_system{m_registry};
        dhoot::bound_system m_bound_system;

        bool m_paused = false;
    };
}

#endif //ASD_BOX_GAME_H
