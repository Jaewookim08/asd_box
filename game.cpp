//
// Created by jaewoo on 21. 7. 12..
//

#include "game.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <vector>
#include <stdexcept>

using asd_box::game;


void asd_box::game::key_event(int key, int scancode, int action, int mode) {
    // when a user presses the escape key, we set the WindowShouldClose property to true, closing the application

//    if (key >= 0 && key < 1024)
//    {
//        if (action == GLFW_PRESS)
//            Breakout.Keys[key] = true;
//        else if (action == GLFW_RELEASE)
//        {
//            Breakout.Keys[key] = false;
//            Breakout.KeysProcessed[key] = false;
//        }
//    }
}

void asd_box::game::framebuffer_size_event(int width, int height) {

}

void asd_box::game::update(float delta_time) {

}

void asd_box::game::initialize(int initial_screen_width, int initial_screen_height) {
    using namespace std::string_literals;
    auto result = m_graphics_system.initialize(initial_screen_width, initial_screen_height);
    if (!result.succeeded) {
        throw std::runtime_error("Initializing graphic system failed during game initialization: "s + result.error_msg);
    }
}

void asd_box::game::render() {
    m_graphics_system.render();
}

