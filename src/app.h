#pragma once

#include "display/curses_subsystem.h"
#include "spending_data.h"

using display::CursesSubsystem;

void show_spending(CursesSubsystem&, SpendingData&);
