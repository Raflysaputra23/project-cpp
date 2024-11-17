#include <iostream>
#include <ncurses/curses.h>
#include <ctime>
#include <windows.h>

int Random(int max) {
    srand(time(0));
    return (rand() * 13) % max;
}

void BackgroundRandom(std::string text,int color) {
    start_color();
    init_pair(1, color, COLOR_BLACK);

    int width, height;
    getmaxyx(stdscr, height, width);

    for(int i = 0; i < 50; i++) {
        attron(COLOR_PAIR(1));
        mvprintw(Random(height), Random(width), "%s", text.c_str());
        attroff(COLOR_PAIR(1));
        refresh();
        Sleep(100);
    }
}