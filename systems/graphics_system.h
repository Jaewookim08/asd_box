//
// Created by jaewoo on 21. 7. 12..
//

#ifndef ASD_BOX_GRAPHICS_SYSTEM_H
#define ASD_BOX_GRAPHICS_SYSTEM_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <string>

namespace asd_box{

    class graphics_system {
    public:
        graphics_system() = default;

        struct initialization_result{
            bool succeeded;
            std::string error_msg;
        };
        [[nodiscard]] graphics_system::initialization_result
        initialize(int initial_screen_width, int initial_screen_height);

        void framebuffer_size_event(int width, int height);
        void render();
    };
}


#endif //ASD_BOX_GRAPHICS_SYSTEM_H
