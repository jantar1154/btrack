#pragma once
#include "screen.h"

namespace display {

class MenuItem {
protected:
    std::string text;
    bool focused = false;
    WINDOW *window;

public:
    MenuItem(const std::string &text, int width, int index);
    void focus();
    void unfocus();
    void render() const;
};

}
