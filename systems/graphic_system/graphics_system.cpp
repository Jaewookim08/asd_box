//
// Created by jaewoo on 21. 7. 12..
//

#include "graphics_system.h"

#include <stdexcept>

using asd_box::graphics_system;

asd_box::graphics_system::graphics_system() {
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        throw std::runtime_error("Failed to initialize GLAD");
    }
}

void graphics_system::initialize_gl(int initial_screen_width, int initial_screen_height) {
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
    glClear(GL_COLOR_BUFFER_BIT);
}
