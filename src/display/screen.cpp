#include "screen.h"

using namespace display;
/*     PRIVATE     */
void Screen::render_text(const Vec2D<int> &xy) const {
    wclear(window);
    wmove(window, xy.y, xy.x);
    wprintw(window, "%s\n", text_content.c_str());
    box(window, 0, 0);
    wrefresh(window);
}


/*     PUBLIC     */

Screen::Screen(const PosSize& pos, const std::string &name, const std::string &text_content):
    window(newwin(pos.height, pos.width, pos.row, pos.col)),
    name(name),
    text_content(text_content) {
    refresh();
}

Screen::Screen(const PosSize& pos, const std::string &name):
    Screen(pos, name, "") { }


Screen::~Screen() {
    delwin(window);
}

void Screen::render_text() const {
    render_text({1, 1});
}

void Screen::render_text_center() const {
    const int c_x = getmaxx(window) / 2 - (text_content.length() / 2);
    render_text({c_x, 1});
}

void Screen::set_text_content(const std::string &content) {
    text_content = content;
}

PosSize Screen::get_win_center(WINDOW *win, int height, int width) {
    const int row = (getmaxy(win) / 2) - (height / 2);
    const int col = (getmaxx(win) / 2) - (width / 2);
    return {
        height,
        width,
        row,
        col
    };
}

PosSize Screen::get_win_center(int height, int width) {
    return get_win_center(stdscr, height, width);
}
