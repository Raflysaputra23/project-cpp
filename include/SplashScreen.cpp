#include <ncurses/curses.h>
#include <string>
#include <windows.h>
#include "define.h"
using namespace std;




void SplashScreen(){
    initscr();
    noecho();
    curs_set(0);
    
    string alien [] = {
        "'^^^......`^^^",
        "'^```^^^^`'`^^",
        "'^.  `^^^'..^^",
        "'^^^^^^^^^^`''`^""`",
        "^^  '^' .....'`",
        "^^..`^'",
        "^^^^^^'",
        "``.'`.'`.",
        "^' '` .^.",

    };

    string judul [] = {
        " _   _    _    ___   ___  _  _ __   __   _    ___   ___  ___  ___",
        "| | | |  /_\\  | _ \\ |_ _|| \\| |\\ \\ / /  /_\\  |   \\ | __|| _ \\/ __|",
        "| |_| | / _ \\ |  _/  | | | .` | \\ V /  / _ \\ | |) || _| |   /\\__ \\ " ,
        " \\___/ /_/ \\_\\|_|   |___||_|\\_|  \\_/  /_/ \\_\\|___/ |___||_|_\\|___/",
                                                                 
    };

    string penghapus = " ";

    int panjangJudul = sizeof(judul) / sizeof(judul[0]);
    int panjangAlien = sizeof(alien) / sizeof(alien[0]);
    int y = Koordinat('y', "middle") - 4;
    int x = Koordinat('x', "middle") - 33;
    initscr();

    curs_set(0);
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);

    for (int i = 0; i < 9; i++){
        mvprintw (y + i - 6, x + 7, "%s", alien[i].c_str());
        Sleep(50);
        refresh();
    }

    for (int i = 0; i < 9; i++){
        mvprintw (y + i - 6, x + 27, "%s", alien[i].c_str());
        Sleep(50);
        refresh();
    }

    for (int i = 0; i < 9; i++){
        mvprintw (y + i - 6, x + 47, "%s", alien[i].c_str());
        Sleep(50);
        refresh();
    }

    for (int i = 0; i < 4; i++){
        mvprintw (y + i + 4, x, "%s", judul[i].c_str());
        Sleep(200);
        refresh();
    }

    Sleep(2000);

    for(int i = 0; i < 70; i++){
        mvprintw (y - 6, x + i, "%s", penghapus.c_str());
        mvprintw (y - 5, x + i, "%s", penghapus.c_str());
        mvprintw (y - 4, x + i, "%s", penghapus.c_str());
        mvprintw (y - 4, x + i, "%s", penghapus.c_str());
        mvprintw (y - 3, x + i, "%s", penghapus.c_str());
        mvprintw (y - 2, x + i, "%s", penghapus.c_str());
        mvprintw (y - 1, x + i, "%s", penghapus.c_str());
        mvprintw (y, x + i, "%s", penghapus.c_str());
        mvprintw (y + 1, x + i, "%s", penghapus.c_str());
        mvprintw (y + 2, x + i, "%s", penghapus.c_str());
        mvprintw (y + 3, x + i, "%s", penghapus.c_str());
        mvprintw (y + 4, x + i, "%s", penghapus.c_str());
        mvprintw (y + 5, x + i, "%s", penghapus.c_str());
        mvprintw (y + 6, x + i, "%s", penghapus.c_str());
        mvprintw (y + 7, x + i, "%s", penghapus.c_str());
        mvprintw (y + 8, x + i, "%s", penghapus.c_str());

        Sleep(10);
        refresh();
    }



    getch();
    endwin();
}


