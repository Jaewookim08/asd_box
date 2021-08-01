//
// Created by jaewoo on 21. 8. 1..
//

#include "save_manager.h"
#include <components/transform.h>
#include <components/sprite_renderer.h>
#include <components/camera.h>
#include <cereal/archives/json.hpp>
#include <cereal/types/variant.hpp>
#include <cereal/types/vector.hpp>

namespace {
    using namespace std::string_literals;


    template <size_t N>
    struct string_literal {
        constexpr explicit(false) string_literal(const char (& str)[N]) { // NOLINT(google-explicit-constructor)
            std::copy_n(str, N, data);
        }

        char data[N]{};
    };

    template <string_literal componentName, class Component>
    struct component_meta {
        static constexpr string_literal name = componentName;
        using component_type = Component;
    };

    template <class ... Args>
    struct type_list {
    };

    namespace detail {
        template <typename Seq>
        struct for_each_helper;

        template <template <typename...> class Seq, typename... Ts>
        struct for_each_helper<Seq<Ts...>> {
            template <class Func>
            static void execute(Func func) {
                (func.template operator()<Ts>(), ...);
            }
        };

        template <class ComponentMetaList>
        struct _components_data;

        template <template <class ...> class ComponentMetaListTemplate,
                template <string_literal, class> class MetaTemplate, string_literal ... names, class ... Components>
        struct _components_data<ComponentMetaListTemplate<MetaTemplate<names, Components> ...>> {
            template <class T>
            using component_list_type = std::vector<T>;

            std::tuple<component_list_type<Components> ...> data;

            template <class Archive>
            void serialize(Archive& ar) {
                (  ar(cereal::make_nvp(
                        "component_list<"s + names.data + ">",
                        std::get<component_list_type<Components>>(data)))
                        , ...);
            }
        };

        template <class ComponentMetaList>
        struct registry_save {
            size_t entity_count;
            _components_data<ComponentMetaList> components_data;

            using component_meta_list = ComponentMetaList;
            template <class T>
            using component_list_type = typename decltype(components_data)::template component_list_type<T>;

            template <class Archive>
            void serialize(Archive& ar) {
                ar(CEREAL_NVP(entity_count));
                ar(CEREAL_NVP(components_data));
            }
        };
    }

    template <class Seq, class Func>
    void for_each_type(Func func) {
        detail::for_each_helper<Seq>::execute(func);
    }


    template <class T>
    std::vector<T> get_all_components_copy(
            const entt::registry& registry) { // Todo: const 빼고 T를 reference_wrapper<T>로 바꾸기...? 이득일지 잘 모르겠다.
        auto ret = std::vector<T>{};
        registry.view<T>().each([&](auto entity, const T& component) {
            ret.push_back(component);
        });
        return ret;
    }

    using component_list = type_list<
            component_meta<string_literal{"transform"}, asd_box::transform>,
            component_meta<string_literal{"sprite_renderer"}, asd_box::sprite_renderer>,
            component_meta<string_literal{"camera"}, asd_box::camera>>;

    using registry_save = detail::registry_save<component_list>;

    registry_save to_save_data(const entt::registry& registry) {
        auto ret = registry_save{};

        ret.entity_count = registry.alive();

        for_each_type<registry_save::component_meta_list>([&] <class T>() {
            using component_type = typename T::component_type;
            using list_type = typename registry_save::component_list_type<component_type>;

            std::get<list_type>(ret.components_data.data) = get_all_components_copy<component_type>(registry);
        });
        return ret;
    }
}


void asd_box::save_manager::save(const entt::registry& registry, std::ostream& output_stream) {
    auto out_archive = cereal::JSONOutputArchive{output_stream};

    auto registry_save_data = to_save_data(registry);

    out_archive(cereal::make_nvp("registry", registry_save_data));
}

void asd_box::save_manager::load(entt::registry& registry, const std::istream& input_stream) {
    return;
}
