//
// Created by jaewoo on 21. 7. 25..
//

#ifndef ASD_BOX_RESOURCE_LOADER_H
#define ASD_BOX_RESOURCE_LOADER_H

#include "texture.h"
#include <string>


namespace asd_box{
    [[deprecated]]
    class resource_loader {
    public:
        resource_loader() = delete;

        template<class T> static T load(const std::string& path) = delete;
    };

    template<> texture resource_loader::load<texture>(const std::string& path);
}


#endif //ASD_BOX_RESOURCE_LOADER_H
