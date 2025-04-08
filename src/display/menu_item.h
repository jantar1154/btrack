#pragma once
#include "screen.h"
#include <functional>
#include <ncurses.h>

namespace display {

class MenuItem {
protected:
    std::string text;
    // If the item is focused, it will be highlighted and can be entered
    bool focused = false;

    // When user enters this submenu this function will call
    std::function<size_t ()> function;

    // Back reference to it's parent
    WINDOW *menu_window;

    // Window of this item
    WINDOW *window;

public:
    MenuItem(std::function<size_t ()> function, const std::string &text, int width, int index);

    // Focus the item (when is focused in it's menu)
    void focus();
    // Unfocus the item
    void unfocus();

    // Returns the function to call when user enters this submenu
    std::function<size_t ()> on_enter() const;

    // Renders item text content
    void render() const;
};

}
