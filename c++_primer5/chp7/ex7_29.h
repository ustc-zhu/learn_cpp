#include <iostream>
#include <string>
using namespace std;
class Screen {
   public:
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

inline void Screen::do_display(ostream &os)const{
    os<<contents;
}