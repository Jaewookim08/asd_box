//
// Created by jaewoo on 21. 7. 12..
//

#ifndef ASD_BOX_GAME_H
#define ASD_BOX_GAME_H


#include <string>
#include "systems/graphics_system.h"

class GLFWwindow;
namespace asd_box {
    class game {
    public:
        game() = default;

        game(const game& other) = delete;

        game(game&& other) = delete;

        game& operator=(const game& other) = delete;

        game& operator=(game&& other) = delete;

        void initialize(int initial_screen_width, int initial_screen_height);

        void key_event(int key, int scancode, int action, int mode);

        void framebuffer_size_event(int width, int height);

        void update(float delta_time);

        void render();

    private:

        graphics_system m_graphics_system;
    };
}

#endif //ASD_BOX_GAME_H
