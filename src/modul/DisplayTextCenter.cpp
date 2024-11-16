#include <iostream>
#include <ncurses/ncurses.h>
#include <windows.h>
void DisplayTextCenter(int x, int y,std::string text, int color, int attr = A_NORMAL) {
    start_color();
    init_pair(1, color, COLOR_BLACK);

    for(int i = 0; i < text.length(); i++) {
        attron(COLOR_PAIR(1));
        attron(attr);
        mvprintw(y, x - (text.length() / 2) + i, "%c", text[i]);
        attroff(attr);
        attroff(COLOR_PAIR(1));
        Sleep(300);
        refresh();
    }
}