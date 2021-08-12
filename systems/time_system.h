//
// Created by jaewoo on 21. 8. 7..
//

#ifndef ASD_BOX_TIME_SYSTEM_H
#define ASD_BOX_TIME_SYSTEM_H

#include <queue>

namespace asd_box {
    class time_system {
        static constexpr auto recent_frames_save_count = 10;
    public:
        void update(float dt);
        [[nodiscard]] double current_time() const;
        float get_fps() const;

    private:
        double m_current_time = 0;
        std::queue<double> m_recent_frames_time_queue;
    };
}


#endif //ASD_BOX_TIME_SYSTEM_H
