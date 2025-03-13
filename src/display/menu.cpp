#include "menu.h"
#include "menu_item.h"
#include <ncurses.h>

using namespace display;

Menu::Menu(const PosSize& pos, const std::string &name, const std::string &text_content):
    Screen(pos, name, text_content) {
}

Menu::Menu(const PosSize& pos, const std::string &name):
    Menu(pos, name, "") { }

Menu::~Menu() {
    delwin(window);
}

void Menu::add_item(const std::string &item) {
    const int index = items.size();
    items.emplace_back(MenuItem(item, getmaxx(window) - 2, index));
}

void Menu::render() const {
    // render name
    render_name();

    // render items
    for (const MenuItem &item : items) {
        item.render();
    }
    box(window, 0, 0);
}
