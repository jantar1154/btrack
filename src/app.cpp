#include "app.h"
#include "display/screen.h"
#include "spending_data.h"

#include <algorithm>
#include <ncurses.h>
#include <sstream>

#include <iostream>

using std::begin, std::end;

using display::Screen, display::PosSize;
size_t show_spending(CursesSubsystem &s, SpendingData &spending_data) {
    s.clear();
    int maxx, maxy;
    getmaxyx(stdscr, maxx, maxy);

    // Fullscreen
    // TODO: function for fullscreen (arg screen)
    const PosSize pos {maxx - 1, maxy - 1, 1, 1};
    Screen scr { pos, "Spending" };
    scr.render();

    // Populate menu: append to text content new line (new expense)
    std::stringstream content;
    content << scr.get_text_content();

    // height - borders top, bottom - title
    // const size_t max_items = maxy - 2 - 1;
    const std::vector<Expense> exp_vec { spending_data.get_expenses() };

    std::for_each(begin(exp_vec), end(exp_vec), [&content](const Expense& ex) {
        content << ex.get_datetime().to_iso8061()
        << ": [ " << ex.get_name() << " ] "
        << ex.get_amount() << " Kc\n ";
    });

    scr.set_text_content(content.str());
    // scr.set_text_content(std::to_string(exp_vec.size()));
    scr.render();

    char key;
    while ((key = s.wait_for_keypress())) {
        switch (key) {
            case 'q':
                scr.clear();
                return 1; // Program will continue

            case 'l': // Next page
            case 'k': // Previous page
                break; // Break from switch
        }
    }
    // Shouldn't get here, but if it does, halt
    return 0;
}
