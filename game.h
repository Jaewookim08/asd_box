//
// Created by jaewoo on 21. 7. 12..
//

#ifndef ASD_BOX_GAME_H
#define ASD_BOX_GAME_H


#include <string>
#include "systems/graphic_system/graphics_system.h"
#include <entt/entt.hpp>
#include <systems/input_manager.h>

namespace asd_box {
    class game {
    private:
        // Todo: Settings import. setting 클래스 만든 다음 cereal로 불러 오지 뭐.
        static constexpr auto texture_vshader_name = "shaders/texture.vsh";
        static constexpr auto texture_fshader_name = "shaders/texture.fsh";

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

        void update(float delta_time);

        void render();

    private:

        input_manager m_input_manager{};
        graphics_system m_graphics_system;
        entt::registry m_registry{};
    };
}

#endif //ASD_BOX_GAME_H
