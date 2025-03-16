#include "display/curses_subsystem.h"
#include "display/menu.h"
#include "display/screen.h"
#include "app.h"

using display::CursesSubsystem, display::Menu;
using display::MenuMoveDirection;

int main() {
    CursesSubsystem s;

    // Go to menu
    constexpr display::PosSize pos {30, 30, 0, 0};
    Menu main_menu(pos, "Main menu");

    main_menu.add_item("Show spending", []() -> size_t { show_spending(); return 1; });
    main_menu.add_item("Add a record", []() -> size_t {return 1;});
    main_menu.add_item("Edit records", []() -> size_t { return 1; });
    main_menu.add_item("Visualise spending", []() -> size_t { return 1; });
    main_menu.add_item("Weekly report", []() -> size_t { return 1; });
    main_menu.add_item("Save changes and exit", []() { return 0; });

    main_menu.render();

    // Handle keys
    char key;
    bool exit = false;
    while ((key = s.wait_for_keypress())) {
        switch (key) {
            case 'j':
                main_menu.move_cursor(MenuMoveDirection::DOWN);
                break;
            case 'k':
                main_menu.move_cursor(MenuMoveDirection::UP);
                break;
            case 'l':
            // TODO: figure out how
            // case 'enter':
                const size_t result = main_menu.enter()();
                if (result == 0) exit = true;
                break;
        }
        if (exit) break;
    }

    return 0;
}
