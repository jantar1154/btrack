#include "menu_item.h"
#include <functional>
#include <ncurses.h>

using namespace display;
MenuItem::MenuItem(std::function<size_t ()> function, const std::string &text, int width, int index) {
    this->function = function;
    this->text = text;
    // index * (rows_between + 1) + top_offset
    const int y = (index * 2) + 3;
    this->window = newwin(1, width, y, 1);
}

void MenuItem::focus()  {
    this->focused = true;
    render();
}

void MenuItem::unfocus() {
    this->focused = false;
    render();
}

std::function<size_t ()> MenuItem::on_enter() const {
    return this->function;
}

void MenuItem::render() const {
    // Highlight focused item
    if (true == focused) {
        wattron(window, A_STANDOUT);
    }
    wclear(window);
    wprintw(window, "%s", this->text.c_str());
    wattroff(window, A_STANDOUT);
    wrefresh(window);
}
