//
// Created by jaewoo on 21. 12. 31..
//

#include "bound_system.h"
#include "components/transform//transform.h"
#include "components/transform//transform_handler.h"
#include "components/bounded.h"


dhoot::bound_system::bound_system(entt::registry& registry, glm::vec2 screen_bottom_left, glm::vec2 screen_top_right) :
        m_registry{registry}, m_screen_bottom_left{screen_bottom_left}, m_screen_top_right{screen_top_right} {
}

namespace {
    template<class... Ts>
    struct overloaded : Ts ... {
        using Ts::operator()...;
    };
    template<class... Ts> overloaded(Ts...) -> overloaded<Ts...>;
}

void dhoot::bound_system::update(float dt) {
    m_registry.view<asd_box::transform, dhoot::bounded>().each(
            [&](entt::entity entity, const asd_box::transform& transform, const dhoot::bounded& bounded) {
                auto transform_handler = asd_box::transform_handler{m_registry, entity};
                auto current_position = static_cast<glm::vec2>(transform_handler.get_world_translation());

                std::visit(overloaded{
                        [&](const dhoot::bounded_screen& bounded_screen) {
                            auto is_inside = bool{glm::all(glm::greaterThan(current_position, m_screen_bottom_left))
                                                  && glm::all(glm::lessThan(current_position, m_screen_top_right))};
                            if (!is_inside) {
                                m_registry.destroy(entity);
                            }
                        }
                }, bounded);
            });
}

