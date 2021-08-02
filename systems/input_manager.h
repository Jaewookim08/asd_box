//
// Created by jaewoo on 21. 8. 2..
//

#ifndef ASD_BOX_INPUT_MANAGER_H
#define ASD_BOX_INPUT_MANAGER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <array>
namespace asd_box {
    // todo: key enum 직접 추가해서 glfw key로부터의 변환 map 추가.
    class input_manager {
    public:
        void key_event(int key, int action, int mode);

        void next_frame();

        bool check_key(int key);

        bool check_key_pressed(int key);

        bool check_key_released(int key);

    private:
        using key_state = std::array<bool, GLFW_KEY_LAST>;

        key_state& current_key_state();

        key_state& prev_key_state();

        std::array<key_state, 2> m_buffers{};
        int m_current_buffer_index = 0;
    };
}

#endif //ASD_BOX_INPUT_MANAGER_H
