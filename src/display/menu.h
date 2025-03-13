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
    std::vector<MenuItem> items;
    bool focused = false;
    size_t focused_item = 0;

    void render_items() const;

public:
    Menu(const PosSize &pos, const std::string &name, const std::string &text_content);
    Menu(const PosSize &pos, const std::string &name);
    ~Menu();
    
    void render() const;

    void focus();
    void unfocus();

    void move_cursor(MENU_MOVE_DIRECTION dir);

    void add_item(const std::string &item);
};

}
