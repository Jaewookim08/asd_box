//
// Created by jaewoo on 21. 7. 12..
//

#ifndef ASD_BOX_GRAPHICS_SYSTEM_H
#define ASD_BOX_GRAPHICS_SYSTEM_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <string>

namespace asd_box {

    class graphics_system {
    public:
        graphics_system();

        void initialize_gl(int initial_screen_width, int initial_screen_height);

        void framebuffer_size_event(int width, int height);

        void update(float dt);

        void render();
    };
}


#endif //ASD_BOX_GRAPHICS_SYSTEM_H