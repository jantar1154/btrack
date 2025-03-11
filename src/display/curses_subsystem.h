#pragma once
#include <ncurses.h>

namespace display {

class CursesSubsystem {
public:
    CursesSubsystem();
    ~CursesSubsystem();

    // Not static because we have to make sure everything is set up
    char wait_for_keypress() const;
};

}
