//
// Created by jaewoo on 21. 7. 21..
//

#ifndef ASD_BOX_TRANSFORM_H
#define ASD_BOX_TRANSFORM_H

#include <glm/glm.hpp>
#include <glm/detail/type_quat.hpp>
#include <string>
#include <entt/entt.hpp>

namespace asd_box {
    // 주의: 다른 entity로 복사 시 m_children 비워 주고 m_parent의 child로 추가해야함. 어떻게 할 지는 좀 더 생각해 봐야 할 듯.
    // Todo: 그냥 값 읽기만 하기는 여기로 옮기는 게 성능적으로 이득이 있을 듯.
    class transform {
        friend class transform_handler;
    public:
        explicit transform(glm::vec3 translation = glm::vec3{0.f}, glm::quat rotation = glm::identity<glm::quat>(),
                           glm::vec3 scale = glm::vec3{1.f});

        template <class Archive>
        void serialize(Archive& ar);

    private:
        glm::vec3 m_translation;
        glm::quat m_rotation;
        glm::vec3 m_scale;

        std::set<entt::entity> m_children;
        entt::entity m_parent = entt::null;
        // Todo: parent 및 children이 삭제 및 entity에서 transform이 지워졌을 때의 처리.
        glm::mat4 m_world_transform_matrix_cache = {};
        bool m_dirty_flag = true;
    };

    template <class Archive>
    void transform::serialize(Archive& ar) {
        using namespace std::string_literals;
        ar("transform_data_placeholder"s);
    }
}


#endif //ASD_BOX_TRANSFORM_H
