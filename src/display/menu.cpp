#include "menu.h"
#include "menu_item.h"
#include <ncurses.h>
#include <string>

using namespace display;

Menu::Menu(const PosSize& pos, const std::string &name, const std::string &text_content):
    Screen(pos, name, text_content) {
}

Menu::Menu(const PosSize& pos, const std::string &name):
    Menu(pos, name, "") { }

Menu::~Menu() {
    delwin(window);
}
void Menu::focus() {
    this->focused = true;
    render_items();
}

void Menu::unfocus() {
    this->focused = false;
    render_items();
}

void Menu::move_cursor(MenuMoveDirection dir) {
    if (!focused) return;
    // Good lord
    // TODO: make readable
    if ((dir == MenuMoveDirection::UP? focused_item : items.size() - 1) <= (dir == MenuMoveDirection::UP? 0 : focused_item)) return;
    // unfocus old item
    items.at(focused_item).unfocus();
    this->focused_item += (dir == MenuMoveDirection::UP ? -1 : 1);
    // Focus new item
    items.at(focused_item).focus();
    // Update the A_STANDOUT
    render_items();
}

void Menu::add_item(const std::string &item) {
    // Index decides which `y` coord will the item be at
    const int index = items.size();
    items.emplace_back(MenuItem(item, getmaxx(window) - 2, index));
    if (index == 0) items[0].focus();
}

void Menu::render_items() const {
    for (const MenuItem &item : items) {
        item.render();
    }
}

void Menu::render() const {
    // render name
    render_name();

    // render items
    render_items();
    box(window, 0, 0);
}
