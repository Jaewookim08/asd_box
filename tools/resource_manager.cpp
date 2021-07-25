//
// Created by jaewoo on 21. 7. 25..
//

#include "resource_manager.h"

using asd_box::resource_manager;

resource_manager& resource_manager::ins() {
    static resource_manager instance{};
    return instance;
}