//
// Created by jaewoo on 21. 12. 31..
//

#ifndef ASD_BOX_BOUNDED_H
#define ASD_BOX_BOUNDED_H

#include <glm/glm.hpp>
#include <variant>

namespace dhoot {
    // 엔티티가 존재할 수 있는 범위를 나타냄
    struct bounded_screen{
        float padding = 0.f;    // Todo:
    };

    using bounded = std::variant<bounded_screen>;
}


#endif //ASD_BOX_BOUNDED_H
