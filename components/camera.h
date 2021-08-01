//
// Created by jaewoo on 21. 7. 27..
//

#ifndef ASD_BOX_CAMERA_H
#define ASD_BOX_CAMERA_H

#include <glm/glm.hpp>
#include <variant>
#include <cereal/cereal.hpp>

namespace asd_box {
    struct perspective_camera {
        perspective_camera(float fovy, float aspect, float z_near, float z_far);

        float fovy;
        float aspect;
        float z_near;
        float z_far;

        [[nodiscard]] glm::mat4 get_projection_matrix() const;

        template<class Archive>
        void serialize(Archive & ar){
            ar(CEREAL_NVP(fovy));
            ar(CEREAL_NVP(aspect));
            ar(CEREAL_NVP(z_near));
            ar(CEREAL_NVP(z_far));
        }
    };

    struct orthographic_camera{
        orthographic_camera(float left, float right, float bottom, float top, float z_near, float z_far);

        float left;
        float right;
        float bottom;
        float top;
        float z_near;
        float z_far;

        [[nodiscard]] glm::mat4 get_projection_matrix() const;

        template<class Archive>
        void serialize(Archive & ar){
            ar(CEREAL_NVP(left));
            ar(CEREAL_NVP(right));
            ar(CEREAL_NVP(bottom));
            ar(CEREAL_NVP(top));
            ar(CEREAL_NVP(z_near));
            ar(CEREAL_NVP(z_far));
        }
    };

    struct camera {
        using variant_camera_t = std::variant<perspective_camera, orthographic_camera>;
        explicit camera(variant_camera_t inner_camera);

        variant_camera_t inner_camera;
        [[nodiscard]] glm::mat4 get_projection_matrix() const;

        template<class Archive>
        void serialize(Archive & ar){
            ar(CEREAL_NVP(inner_camera));
        }
    };
}


#endif //ASD_BOX_CAMERA_H
