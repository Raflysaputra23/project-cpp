#include "define.h"
#include <ncurses/curses.h>
#include <windows.h>
#include <string>

#define darah 100

void GamePlay(){
    initscr();
    curs_set(0);

    std::string judul [] = {
        " _______ _______           _____   _______     _____            __  __  ______", 
        "/ ____| |__   __|   /\\    |  __ \\ |__   __|   / ____|    /\\    |  \\/  ||  ____|",
        "| (___     | |     /  \\   | |__) |   | |     | |  __    /  \\   | \\  / || |__",   
        "\\___ \\     | |    / /\\ \\  |  _  /    | |     | | |_ |  / /\\ \\  | |\\/| ||  __|",  
        "____) |    | |   / ____ \\ | | \\ \\    | |     | |__| | / ____ \\ | |  | || |____", 
        "|_____/    |_|  /_/    \\_\\|_|  \\_\\   |_|      \\_____|/_/    \\_\\|_|  |_||______|"
                                                                                                                                        
    };

    int panjangJudul = sizeof(judul) / sizeof(judul[0]);
    int y = Middle('y');
    int x = Middle('x');

    for(int i = 0; i < panjangJudul; i++) {
        mvprintw((y / 2) + i, (x / panjangJudul) + 15, "%s" ,judul[i].c_str());
        refresh();
        Sleep(200);
    }

    mvprintw(0, 0, "Darah : %d", darah);

    getch();
    endwin();
}
