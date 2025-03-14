#include "display/curses_subsystem.h"
#include "display/menu.h"
#include "display/screen.h"

using display::CursesSubsystem, display::Menu;
using display::MenuMoveDirection;

int main() {
    CursesSubsystem s;

    // Go to menu
    s.wait_for_keypress();
    const display::PosSize pos {30, 30, 0, 0};
    s.hide_loading();
    Menu main_menu(pos, "main menu");
    main_menu.add_item("abc 1");
    main_menu.add_item("acb 2");
    main_menu.render();

    // Handle keys
    char key;
    while ((key = s.wait_for_keypress())) {
        switch (key) {
            case 'q':
                return 0;
            case 'j':
                main_menu.move_cursor(MenuMoveDirection::DOWN);
                break;
            case 'k':
                main_menu.move_cursor(MenuMoveDirection::UP);
                break;
        }
    }

    return 0;
}
