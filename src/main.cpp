#include "display/curses_subsystem.h"
#include "display/menu.h"
#include "display/screen.h"

using display::CursesSubsystem, display::Menu;

int main() {
    CursesSubsystem s;

    // Go to menu
    const display::PosSize pos {30, 30, 0, 0};
    Menu main_menu(pos, "main menu");
    main_menu.add_item("abc 1");
    main_menu.add_item("acb 2");
    main_menu.render();

    s.wait_for_keypress();

    return 0;
}
