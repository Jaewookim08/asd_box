//
// Created by jaewoo on 21. 8. 1..
//

#ifndef ASD_BOX_SAVE_MANAGER_H
#define ASD_BOX_SAVE_MANAGER_H

#include <string>
#include <entt/entt.hpp>

namespace asd_box {
    class save_manager {
    public:
        void save(const entt::registry& registry, std::ostream& output_stream);
        void load(entt::registry& registry, const std::istream& input_stream);

    private:

    };
}


#endif //ASD_BOX_SAVE_MANAGER_H
