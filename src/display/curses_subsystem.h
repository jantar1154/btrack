#pragma once
#include <ncurses.h>
#include "screen.h"

namespace display {

class CursesSubsystem {
private:

public:
    CursesSubsystem();
    ~CursesSubsystem();

    // Not static because we have to make sure everything is set up
    char wait_for_keypress() const;

    void clear() const;
};

}
