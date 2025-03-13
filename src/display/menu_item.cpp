#include "menu_item.h"
#include <ncurses.h>

using namespace display;
MenuItem::MenuItem(const std::string &text, int width, int index) {
    this->text = text;
    this->window = newwin(3, width, index + 2, 1);
    refresh();
    wrefresh(window);
}

void MenuItem::render() const {
    wclear(window);
    wprintw(window, "%s", this->text.c_str());
    wrefresh(window);
}
