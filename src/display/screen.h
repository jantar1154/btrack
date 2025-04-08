#pragma once
#include <string>
#include <ncurses.h>
#include "../util.h"

namespace display {

struct PosSize {
    int height;
    int width;
    int row;
    int col;
};

class Screen {
protected:
    WINDOW *window;
    // Title of the window
    std::string name;
    // String in the window
    std::string text_content;
    // Whether the window is focused (might not use it)
    bool focused;

    // Renders the screen title
    void render_name() const;
    // Renders the screen content
    void render_text(const Vec2D<int> &xy, const std::string &text) const;

public:
    Screen(const PosSize &pos, const std::string &name, const std::string &text_content);
    Screen(const PosSize &pos, const std::string &name);
    ~Screen();

    // Renders screen title and content
    // Title is always center aligned
    virtual void render() const;

    // Renders screen title and content aligned to center
    // Title is always center aligned
    virtual void render_center() const;

    // Changes text content
    void set_text_content(const std::string &content);

    // Clears the screen, but keeps the title and border
    void clear() const;

    virtual void focus();
    virtual void unfocus();

    static PosSize get_win_center(WINDOW *win, int height, int width);
    static PosSize get_win_center(int height, int width);
};

}
