#include "app.h"
#include "display/screen.h"
#include "spending_data.h"

#include <ncurses.h>

using display::Screen, display::PosSize;
size_t show_spending(CursesSubsystem &s, SpendingData &spending_data) {
    s.clear();
    int maxx, maxy;
    getmaxyx(stdscr, maxx, maxy);

    // Fullscreen
    // TODO: function for fullscreen (arg screen)
    const PosSize pos {maxx - 1, maxy - 1, 1, 1};
    const Screen scr { pos, "Spending" };
    scr.render();

    char key;
    while ((key = s.wait_for_keypress())) {
        switch (key) {
            case 'q':
                scr.clear();
                return 1; // Program will continue

            case 'l': // Next page
            case 'h': // Go up
            case 'j': // Go down
            case 'k': // Previous page
                break; // Break from switch
        }
    }
    // Shouldn't get here, but if it does, halt
    return 0;
}
