//
// Created by jaewoo on 22. 2. 4..
//

#ifndef ASD_BOX_BODY_H
#define ASD_BOX_BODY_H

#include <box2d/box2d.h>
#include <memory>

namespace asd_box::box2d {
    class body {
    public:
        explicit body(b2World* world, b2BodyDef* body_def);

        [[nodiscard]] b2Body* get_raw() const;

    private:
        class body_deleter {
        public:
            explicit body_deleter(b2World* world);

            void operator()(b2Body* body);

        private:
            b2World* m_world;
        };

        std::unique_ptr<b2Body, body_deleter> m_b2Body_ptr;
    };
}

#endif //ASD_BOX_BODY_H
