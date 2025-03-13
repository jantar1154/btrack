#pragma once
#include "screen.h"

namespace display {

class MenuItem {
protected:
    std::string text;
    WINDOW *window;

public:
    MenuItem(const std::string &text, int width, int index);
    void render() const;
};

}
