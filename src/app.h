#pragma once

#include "display/curses_subsystem.h"
#include "spending_data.h"

using display::CursesSubsystem;

// Shows data from database
size_t show_spending(CursesSubsystem&, SpendingData&);
