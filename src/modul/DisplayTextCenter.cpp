#include <iostream>
#include <ncurses/ncurses.h>
#include <windows.h>

void DisplayTextCenter(std::string text[], int color, int attr = A_NORMAL) {
    start_color();
    init_pair(1, color, COLOR_BLACK);
    curs_set(0);

    int width, height;
    int size = 4;
    bool cek = true;
    getmaxyx(stdscr, height, width);


    for(int i = 0; i < size; i++) {
        std::string huruf = text[i];
        for(int j = 0; j < huruf.length(); j++) {
            attron(COLOR_PAIR(1));
            mvprintw((height / 2), (width / 2) - (huruf.length() / 2) + j,  "%c", huruf[j]);
            attroff(COLOR_PAIR(1));
            Sleep(300);
            refresh();
        }

        if(i != size - 1) {
            Sleep(2000);
            for(int k = huruf.length() - 1; k > -1; k--) {
                mvprintw((height / 2), (width / 2) - (huruf.length() / 2) + k, " ");
                Sleep(300);
                refresh();
            }  
        }
    }
}