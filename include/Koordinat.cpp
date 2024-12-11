#include <ncurses/ncurses.h>
#include <string>
#include "define.h"


int Koordinat(char xy, std::string tipe){
    int sizeX;
    int sizeY;
    getmaxyx(stdscr, sizeY, sizeX);

    if (tipe == "none") {
        return (xy == 'x') ? sizeX : sizeY;   
    } else if(tipe == "middle") {
        return (xy == 'x') ? sizeX / 2 : sizeY / 2;
    }
    
}