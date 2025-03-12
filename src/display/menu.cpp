#include "menu.h"

using namespace display;

Menu::Menu(const PosSize& pos, const std::string &name, const std::string &text_content):
    Screen(pos, name, text_content) { }

Menu::Menu(const PosSize& pos, const std::string &name):
    Menu(pos, name, "") { }

Menu::~Menu() {
    delwin(window);
}
