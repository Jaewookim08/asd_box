//
// Created by jaewoo on 21. 7. 12..
//

#ifndef ASD_BOX_GAME_H
#define ASD_BOX_GAME_H


#include <string>
#include "systems/graphic_system/graphics_system.h"
#include <entt/entt.hpp>
#include <systems/input_manager.h>
#include <systems/player_actions_system.h>
#include <systems/physics_system.h>
#include <systems/time_manager.h>

namespace dhoot {
    class game {
    private:
        // Todo: Settings import. setting 클래스 만든 다음 cereal로 불러 오지 뭐.
        static constexpr auto texture_vshader_name = "shaders/sprite.vsh";
        static constexpr auto texture_fshader_name = "shaders/sprite.fsh";

    public:
        game();

        game(const game& other) = delete;

        game(game&& other) = delete;

        game& operator=(const game& other) = delete;

        game& operator=(game&& other) = delete;

        void initialize_screen(int initial_screen_width, int initial_screen_height);

        void generate_test_entities();

        void key_event(int key, int scancode, int action, int mode);

        void framebuffer_size_event(int width, int height);

        void update(float dt);

        void render();

    private:

        asd_box::input_manager m_input_manager{};
        asd_box::graphics_system m_graphics_system;
        dhoot::player_actions_system m_player_actions_system{m_registry, m_input_manager};
        dhoot::physics_system m_physics_system{m_registry};
        entt::registry m_registry{};
        asd_box::time_manager m_time_manager{};

        bool m_paused = false;
    };
}

#endif //ASD_BOX_GAME_H
