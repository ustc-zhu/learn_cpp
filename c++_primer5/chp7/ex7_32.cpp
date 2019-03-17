#include "ex7_32.h"

int main(){
    Screen s(4,5,'#');
    Window_mgr mgr;
    mgr.setscreens(s);
    mgr.display(0);
    mgr.clear(0);
    mgr.display(0);
    return 0;
}