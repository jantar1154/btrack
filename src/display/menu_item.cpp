#include "menu_item.h"
#include <ncurses.h>

using namespace display;
MenuItem::MenuItem(const std::string &text, int width, int index) {
    this->text = text;
    // Height of three so the item can be boxed
    const int y = (index * 3) + 3;
    this->window = newwin(3, width, y, 1);
    refresh();
    wrefresh(window);
}
    
void MenuItem::focus()  {
    this->focused = true;
    render();
}   
   
void MenuItem::unfocus() {
    this->focused = false;
    render();
} 

void MenuItem::render() const {
    if (true == focused) {
        wattron(window, A_STANDOUT);
    }
    wclear(window);
    wprintw(window, "%s", this->text.c_str());
    wrefresh(window);
    wattroff(window, A_STANDOUT);
}
