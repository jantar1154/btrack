#include "curses_subsystem.h"
#include "screen.h"

namespace display {

CursesSubsystem::CursesSubsystem():
    loading_screen(Screen::get_win_center(3, 21), "loading", "loaging program")
{
    initscr();
    noecho();
    raw();
    curs_set(0);

    loading_screen.render_center();
}

CursesSubsystem::~CursesSubsystem() {
    endwin();
}

void CursesSubsystem::hide_loading() const {
    loading_screen.hide();
}

char CursesSubsystem::wait_for_keypress() const {
    return getch();
}

}
