#pragma once
#include "screen.h"

namespace display {

class Menu : public Screen {
protected:

public:
    Menu(const PosSize &pos, const std::string &name, const std::string &text_content);
    Menu(const PosSize &pos, const std::string &name);
    ~Menu();

};

}
