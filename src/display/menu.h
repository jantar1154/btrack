#pragma once
#include "menu_item.h"
#include "screen.h"
#include "menu_item.h"
#include <vector>
#include <ncurses.h>

namespace display {

enum MENU_MOVE_DIRECTION {
    UP,
    DOWN,
};

class Menu : protected Screen {
protected:
    // Vector of items in the menu
    std::vector<MenuItem> items;

    // Whether the entire menu is focused
    bool focused = false;

    // Index of focused item in menu
    size_t focused_item = 0;

    // Renders menu items only
    void render_items() const;

public:
    Menu(const PosSize &pos, const std::string &name, const std::string &text_content);
    Menu(const PosSize &pos, const std::string &name);
    ~Menu();
    
    // Renders itself and all it's items
    void render() const;

    // Focuses this screen
    void focus();
    // Unfocuses this screen
    void unfocus();

    // Moves cursor to select a different item
    void move_cursor(MENU_MOVE_DIRECTION dir);

    // Adds a new item into the menu
    void add_item(const std::string &item);
};

}
