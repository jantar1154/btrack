#include "app.h"
#include "display/screen.h"
#include "spending_data.h"

#include <ncurses.h>

using display::Screen, display::PosSize;
void show_spending(CursesSubsystem &s, SpendingData &spending_data) {
    s.clear();
    int maxx, maxy;
    getmaxyx(stdscr, maxx, maxy);
    const PosSize pos {maxx - 1, maxy - 1, 1, 1};
    const Screen scr {pos, "Spending"};
    scr.render();

    char key;
    while ((key = s.wait_for_keypress())) {
        switch (key) {
            case 'q':
                scr.clear();
                return;
        }
    }
}
