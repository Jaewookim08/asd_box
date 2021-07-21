//
// Created by jaewoo on 21. 7. 22..
//

#ifndef ASD_BOX_TRIANGLE_RENDERER_H
#define ASD_BOX_TRIANGLE_RENDERER_H

#include <glm/common.hpp>
#include <glm/glm.hpp>


namespace asd_box{
    struct triangle_renderer{
        using triangle_t = std::array<glm::vec<3, float>, 3>;

        triangle_t triangle;
        glm::vec<3, float> color;
    };
}

#endif //ASD_BOX_TRIANGLE_RENDERER_H
