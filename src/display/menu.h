#pragma once
#include "menu_item.h"
#include "screen.h"
#include "menu_item.h"
#include <vector>
#include <ncurses.h>

namespace display {

class Menu : protected Screen {
protected:
    std::vector<MenuItem> items;
    bool focused = false;
    size_t focused_item = 0;

public:
    Menu(const PosSize &pos, const std::string &name, const std::string &text_content);
    Menu(const PosSize &pos, const std::string &name);
    ~Menu();
    
    void render() const;

    void add_item(const std::string &item);
};

}
