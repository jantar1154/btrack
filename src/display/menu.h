#pragma once
#include "menu_item.h"
#include "screen.h"
#include "menu_item.h"
#include <functional>
#include <vector>
#include <ncurses.h>

namespace display {

enum class MenuMoveDirection {
    UP,
    DOWN,
};

class Menu : public Screen {
protected:
    // Vector of items in the menu
    std::vector<MenuItem> items;

    // Whether the entire menu is focused
    // bool focused = true;

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
    void move_cursor(MenuMoveDirection dir);

    // Enters currently selected item (runs its function)
    std::function<size_t ()> enter() const;

    // Adds a new item into the menu
    void add_item(const std::string &text, std::function<size_t ()> function);
};

}
