//
// Created by jaewoo on 21. 8. 7..
//

#ifndef ASD_BOX_TIME_SYSTEM_H
#define ASD_BOX_TIME_SYSTEM_H

#include <queue>
#include "tools/time_type.h"

namespace asd_box {
    class time_system {
        static constexpr auto recent_frames_save_count = 10;
    public:
        void update(time dt);

        [[nodiscard]] time current_time() const;

        [[nodiscard]] float get_fps() const;

    private:
        time m_current_time{0};
        std::queue<time> m_recent_frames_time_queue;
    };
}


#endif //ASD_BOX_TIME_SYSTEM_H
