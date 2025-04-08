#include "display/curses_subsystem.h"
#include "display/menu.h"
#include "display/screen.h"
#include "app.h"
#include "spending_data.h"

using display::CursesSubsystem, display::Menu;
using display::MenuMoveDirection;

int main() {
    SpendingData sd {"data.sql"};

    // Shall not use ncurses without this abstraction
    CursesSubsystem s;

    // Go to main menu
    const display::PosSize pos {30, 30, 0, 0};
    Menu main_menu { pos, "Main menu" };

    // Submenus
    // return 1: program continues
    // return 0: program halts
    main_menu.add_item("Show spending", [&s, &sd]() -> size_t { return show_spending(s, sd); });
    main_menu.add_item("Add a record", [&s]() -> size_t { return 1; });
    main_menu.add_item("Edit records", [&s]() -> size_t { return 1; });
    main_menu.add_item("Visualise spending", [&s]() -> size_t { return 1; });
    main_menu.add_item("Weekly report", [&s]() -> size_t { return 1; });
    main_menu.add_item("Save changes and exit", []() { return 0; });

    // Render submenu buttons
    main_menu.render();

    // Handle keys
    char key;
    bool exit = false;
    // MAIN LOOP
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
            // maybe case '\n': (?)
                const size_t result = main_menu.enter()();
                main_menu.clear();
                main_menu.render();
                if (result == 0) exit = true;
                break;
        }
        if (exit) break;
    }

    // saves data into the database
    sd.save();

    return 0;
}
