#include <ncurses/ncurses.h>
#include "define.h"


int Middle(char xy){
    int sizeX;
    int sizeY;
    getmaxyx(stdscr, sizeY, sizeX);

    return (xy == 'x') ? sizeX / 2 : sizeY / 2;
}