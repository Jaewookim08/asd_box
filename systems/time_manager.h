//
// Created by jaewoo on 21. 8. 7..
//

#ifndef ASD_BOX_TIME_MANAGER_H
#define ASD_BOX_TIME_MANAGER_H

#include <queue>

namespace asd_box {
    class time_manager {
        static constexpr auto recent_frames_save_count = 10;
        static constexpr auto fps_print_delay = 0.3f;
    public:
        void update(float dt);
        [[nodiscard]] double current_time() const;

    private:
        float get_fps();
        double m_current_time = 0;
        std::queue<double> m_recent_frames_time_queue;
        double last_fps_printed_time = 0;
    };
}


#endif //ASD_BOX_TIME_MANAGER_H
