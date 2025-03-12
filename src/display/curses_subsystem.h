#pragma once
#include <ncurses.h>
#include "screen.h"

namespace display {

class CursesSubsystem {
private:
    Screen loading_screen;

public:
    CursesSubsystem();
    ~CursesSubsystem();

    void hide_loading() const;

    // Not static because we have to make sure everything is set up
    char wait_for_keypress() const;
};

}
