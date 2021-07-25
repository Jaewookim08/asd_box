//
// Created by jaewoo on 21. 7. 25..
//

#ifndef ASD_BOX_RESOURCE_MANAGER_H
#define ASD_BOX_RESOURCE_MANAGER_H

#include <unordered_map>
#include <memory>

namespace asd_box {
    template<class T> using resource_ptr = std::shared_ptr<T>;

    class resource_manager {
    public:
        static resource_manager& ins();

        resource_manager() = default;

        resource_manager(const resource_manager& other) = delete;

        resource_manager(resource_manager&& other) = delete;

        void operator=(const resource_manager& other) = delete;

        void operator=(resource_manager&& other) = delete;


        template<class T>
        resource_ptr<T> get(const std::string& path);
    private:
//        load_texture()
    };

    template<class T>
    resource_ptr<T> resource_manager::get(const std::string& path) {
        static std::unordered_map<std::string, std::weak_ptr<T>> loaded_resources_map;

        auto& loaded = loaded_resources_map["asdf"];
        if (auto resource = loaded.lock()) {
            return std::move(resource);
        }
        else {

        }
    }
}


#endif //ASD_BOX_RESOURCE_MANAGER_H
