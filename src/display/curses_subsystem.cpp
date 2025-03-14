#include "curses_subsystem.h"
#include "screen.h"

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

}
