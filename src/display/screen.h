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
    std::string name;
    std::string text_content;
    void render_name() const;
    void render_text(const Vec2D<int> &xy, const std::string &text) const;

public:
    Screen(const PosSize &pos, const std::string &name, const std::string &text_content);
    Screen(const PosSize &pos, const std::string &name);
    ~Screen();

    virtual void render() const;
    virtual void render_center() const;
    void set_text_content(const std::string &content);

    void hide() const;

    static PosSize get_win_center(WINDOW *win, int height, int width);
    static PosSize get_win_center(int height, int width);
};

}
