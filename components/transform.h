//
// Created by jaewoo on 21. 7. 21..
//

#ifndef ASD_BOX_TRANSFORM_H
#define ASD_BOX_TRANSFORM_H

#include <glm/glm.hpp>
#include <glm/detail/type_quat.hpp>
#include <string>

namespace asd_box {
    class transform {
    public:
        explicit transform(glm::vec3 translation = glm::vec3{0.f}, glm::quat rotation = glm::identity<glm::quat>(), glm::vec3 scale = glm::vec3{1.f});

        glm::vec3 translation;
        glm::quat rotation;
        glm::vec3 scale;

        [[nodiscard]] glm::mat4 get_transform_matrix();

        [[nodiscard]] glm::mat4 get_world_transform_matrix();

        template<class Archive>
        void serialize(Archive & ar);

    private:
        glm::mat4 world_transform_matrix_cache = {};
        bool dirty_flag = false;
    };

    template<class Archive>
    void transform::serialize(Archive& ar) {
        using namespace std::string_literals;
        ar("transform_data_placeholder"s);
    }
}


#endif //ASD_BOX_TRANSFORM_H
