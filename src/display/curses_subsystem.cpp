#include "curses_subsystem.h"
#include <ncurses.h>

namespace display {

CursesSubsystem::CursesSubsystem() {
    initscr();
    noecho();
    raw();
    curs_set(0);
}

CursesSubsystem::~CursesSubsystem() {
    endwin();
}

char CursesSubsystem::wait_for_keypress() const {
    return getch();
}

void CursesSubsystem::clear() const {
    wclear(stdscr);
}

}
