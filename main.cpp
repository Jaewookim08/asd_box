/*******************************************************************
** This code is part of Breakout.
**
** Breakout is free software: you can redistribute it and/or modify
** it under the terms of the CC BY 4.0 license as published by
** Creative Commons, either version 4 of the License, or (at your
** option) any later version.
******************************************************************/
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "game.h"
//#include "resource_manager.h"
#include <iostream>
#include <cassert>


// GLFW function declarations
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

void init_glfw();

static constexpr unsigned int initial_screen_width = 800;
static constexpr unsigned int initial_screen_height = 600;

asd_box::game* running_game;

int main(int argc, char* argv[]) {
    // Basic glfw/glad initializations
    init_glfw();

    GLFWwindow* window = glfwCreateWindow(initial_screen_width, initial_screen_height, "Hello World!", nullptr,
                                          nullptr);
    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        throw std::runtime_error("Failed to initialize GLAD");
    }


    // create game object
    running_game = new asd_box::game{};
    running_game->generate_test_entities();
    running_game->initialize_screen(initial_screen_width, initial_screen_height);

    // bind callbacks
    glfwSetKeyCallback(window, key_callback);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


    // delta_time variables
    // -------------------
    auto delta_time = 0.0f;
    auto last_frame_time = static_cast<float>(glfwGetTime());

    while (!glfwWindowShouldClose(window)) {
        // calculate delta time
        // --------------------
        auto current_frame_time = static_cast<float>(glfwGetTime());
        delta_time = current_frame_time - last_frame_time;
        last_frame_time = current_frame_time;


        glfwPollEvents();
        running_game->update(delta_time);

        running_game->render();
        glfwSwapBuffers(window);
    }

    // delete all resources as loaded using the resource manager
    // ---------------------------------------------------------
//    ResourceManager::Clear();

    glfwTerminate();
    return 0;
}

void init_glfw() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    glfwWindowHint(GLFW_RESIZABLE, false);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {
    assert(running_game != nullptr);
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
    running_game->key_event(key, scancode, action, mode);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    assert(running_game != nullptr);
    running_game->framebuffer_size_event(width, height);
}