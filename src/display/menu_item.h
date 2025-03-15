#pragma once
#include "screen.h"
#include <functional>
#include <ncurses.h>

namespace display {

class MenuItem {
protected:
    std::string text;
    bool focused = false;
    std::function<size_t ()> function;
    WINDOW *menu_window;
    WINDOW *window;

public:
    MenuItem(std::function<size_t ()> function, const std::string &text, int width, int index);

    // Focus the item (when is focused in it's menu)
    void focus();
    // Unfocus the item
    void unfocus();

    std::function<size_t ()> on_enter() const;

    // Renders item text content
    void render() const;
};

}
