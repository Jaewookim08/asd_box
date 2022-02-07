//
// Created by jaewoo on 22. 2. 4..
//

#include "body.h"

using asd_box::box2d::body;

body::body(b2World* world, b2BodyDef* body_def): m_b2Body_ptr{world->CreateBody(body_def), body_deleter{world}} {}

b2Body* body::get_raw() const{
    return m_b2Body_ptr.get();
}


asd_box::box2d::body::body_deleter::body_deleter(b2World* world) : m_world{world} {}

void asd_box::box2d::body::body_deleter::operator()(b2Body* body) {
    m_world->DestroyBody(body);
}
