#include "define.h"
#include <string>
#include <cstdlib>
#include <windows.h>
#include <ncurses/curses.h>

void trophi(){
    std::string judul [] = {
        "      -++++++++++++++++++++++=               ",        
        " ========---------==--------=====-           ",     
        " +.   :==--------==+=-------    :+           ",     
        "--   .==---+++===+++==-----    --            ",     
        "  +:   ==--==+++++++++++=--:   :=            ",     
        "  .=-  :=-===+++++++++==---.  -=.            ",     
        "     :=-.==--=+++++++==-----.-=:             ",     
        "       =:-=--=++++++=---:-=+                 ",     
        "       .:==--======++=----:.                 ",     
        "           -=-----====---:                   ",       
        "       .:==--======++=----:.                 ",     
        "           -=-----====---:                   ",       
        "           :===----==-:===:                  ",    
        "              ..++==..                       ",       
        "               +++=                          ",      
        "      ::::::::::+++=::::::::::               ",       
        "     :-++++++++++++++++++++-:                ",      
        "       .====================.                ",       
        "     .:+===================:.                ",      
        "      ------------------------               ",
                                                                 
    };

    for(int i = 0; i < 19; i++) {
        mvprintw(Koordinat('y', "middle") - 15 + i, Koordinat('x', "middle") - 16, "%s" ,judul[i].c_str());
        refresh();
    }
}

void winnerTeks() {
    std::string teks [] = {
"              _                               ",
"             (_)                              ",
"   __      __ _  _ __   _ __    ___  _ __     ",
"   \\ \\ /\\ / /| || '_ \\ | '_ \\  / _ \\| '__|     ",
"    \\ V  V / | || | | || | | ||  __/| |       ",
"     \\_/\\_/  |_||_| |_||_| |_| \\___||_|        ",
};

    for(int i = 0; i < 6; i++) {
        mvprintw(Koordinat('y', "middle") + 4 + i, Koordinat('x', "middle") - 21, "%s" ,teks[i].c_str());
        refresh();

    };

}
int Winner() {
    clear();
    initscr();
    start_color();
    noecho();
    init_pair(1, COLOR_WHITE, COLOR_BLUE);
    init_pair(2, COLOR_WHITE, COLOR_RED);

    trophi();
    Sleep(1000);
    winnerTeks();
    Sleep(1000);

    std::string menu [2] = {
        "Restart Game",
        "Exit",
    };

    int panjangMenu1 = sizeof(menu) / sizeof(menu[0]);
    int panjangMenu2 = sizeof(menu) / sizeof(menu[1]);
    int y = Koordinat('y', "middle") + 8;
    int x = Koordinat('x', "middle") + 2;

    int key;
    int active = 1;
    curs_set(0);
    do {
        keypad(stdscr, true);
        switch (key) {
            case KEY_UP:
                if(active == 1) active = 3;
                active--;
            break;
            case KEY_DOWN:
                active++;
                if(active == 3) active = 1;
            break;
            case 10:
                clear();
                if(active == 1) {
                    GamePlay();
                    break;
                } else if(active == 2) {
                    exit(0);
                    break;
                }
            break;
        }

        for(int i = 0; i < 2; i++) {
            std::string huruf = menu[i];
            if(active == (i + 1)) {
                attron(COLOR_PAIR(i + 1));
                mvprintw((y + 3) + i, x - (huruf.length() / 2), "%s", huruf.c_str());
                attroff(COLOR_PAIR(i + 1));
            } else {
                attron(COLOR_PAIR(3));
                mvprintw((y + 3) + i, x - (huruf.length() / 2), "%s", huruf.c_str());
                attroff(COLOR_PAIR(3));
            }
        }
    } while(key = getch());

    clear();
    getch();
    endwin();    
}