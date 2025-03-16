#include "app.h"
#include "display/screen.h"
#include "util.h"
#include <ncurses.h>

using display::Screen, display::PosSize;
void show_spending() {
    wclear(stdscr);
    int maxx, maxy;
    getmaxyx(stdscr, maxx, maxy);
    const PosSize pos {maxx, maxy, 1, 1};
    const Screen scr(pos, "Spending");
    scr.render();
}
