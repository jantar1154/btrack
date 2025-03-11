#include "display/curses_subsystem.h"

using display::CursesSubsystem;

int main() {
    CursesSubsystem s;

    s.wait_for_keypress();

    return 0;
}
