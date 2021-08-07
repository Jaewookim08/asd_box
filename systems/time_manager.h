//
// Created by jaewoo on 21. 8. 7..
//

#ifndef ASD_BOX_TIME_MANAGER_H
#define ASD_BOX_TIME_MANAGER_H

namespace asd_box {
    class time_manager {
    public:
        void update(float dt);
        double current_time() const;

    private:
        double m_current_time = 0;
    };
}


#endif //ASD_BOX_TIME_MANAGER_H
