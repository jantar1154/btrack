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

    // Focus the item (when is focused in it's menu)
    void focus();
    // Unfocus the item
    void unfocus();

    // Renders item text content
    void render() const;
};

}
