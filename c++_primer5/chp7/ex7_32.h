#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Screen;

class Window_mgr {
   private:
    vector<Screen> screens;

   public:
    using ScreenIndex = vector<Screen>::size_type;
    void clear(ScreenIndex);
    void display(ScreenIndex);
    void setscreens(Screen);
};

class Screen {
   public:
    friend void Window_mgr::clear(ScreenIndex);
    using pos = std::string::size_type;

    Screen() = default;
    Screen(pos ht, pos wd, char c)
        : height(ht), width(wd), contents(ht * wd, c) {}

    char get() const { return contents[cursor]; }
    char get(pos r, pos c) const { return contents[r * width + c]; }
    Screen move(pos r, pos c);
    Screen set(char c);
    Screen set(pos r, pos col, char c);
    const Screen display(ostream &os) const;
    Screen display(ostream &os);

   private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
    void do_display(ostream &os) const;
};

inline Screen Screen::move(pos r, pos c) {
    cursor = r * width + c;
    return *this;
}

inline Screen Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}

inline Screen Screen::set(pos r, pos col, char c) {
    contents[r * width + col] = c;
    return *this;
}

inline const Screen Screen::display(ostream &os) const {
    do_display(os);
    return *this;
}

inline Screen Screen::display(ostream &os) {
    do_display(os);
    return *this;
}

inline void Screen::do_display(ostream &os) const { os << contents << endl; }

void Window_mgr::clear(ScreenIndex i) {
    Screen &s = screens[i];
    s.contents.clear();
}

void Window_mgr::display(ScreenIndex i) {
    Screen &s = screens[i];
    s.display(cout);
}

void Window_mgr::setscreens(Screen s) { screens.push_back(s); }