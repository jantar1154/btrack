#include "curses_subsystem.h"
#include "screen.h"
#include <ncurses.h>

namespace display {

CursesSubsystem::CursesSubsystem() {
    initscr();
    noecho();
    raw();
    curs_set(0);

    const PosSize pos { Screen::get_win_center(3, 21) };
    const Screen loading(pos, "loading", "loading program");
    loading.render_text_center();
}

CursesSubsystem::~CursesSubsystem() {
    endwin();
}

char CursesSubsystem::wait_for_keypress() const {
    return getch();
}

}
