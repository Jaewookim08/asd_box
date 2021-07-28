//
// Created by jaewoo on 21. 7. 27..
//

#include "camera.h"
#include <glm/ext.hpp>


// camera
glm::mat4 asd_box::camera::get_projection_matrix() const {
    return std::visit([](auto&& var_cam) {
        return var_cam.get_projection_matrix();
    }, inner_camera);
}

asd_box::camera::camera(asd_box::camera::variant_camera_t inner_camera) : inner_camera{inner_camera} {
}


// perspective camera
asd_box::perspective_camera::perspective_camera(float fovy, float aspect, float z_near, float z_far) :
        fovy{fovy}, aspect{aspect}, z_near{z_near}, z_far{z_far} {

}

glm::mat4 asd_box::perspective_camera::get_projection_matrix() const {
    return glm::perspective(fovy, aspect, z_near, z_far);
}


// orthographic camera
glm::mat4 asd_box::orthographic_camera::get_projection_matrix() const {
    return glm::ortho(left, right, bottom, top, z_near, z_far);
}

asd_box::orthographic_camera::orthographic_camera(float left, float right, float bottom, float top, float z_near,
                                                  float z_far)
        : left{left}, right{right}, bottom{bottom}, top{top}, z_near{z_near}, z_far{z_far} {

}
