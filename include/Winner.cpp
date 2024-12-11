#include "define.h"
#include <string>
#include <cstdlib>
#include <windows.h>
#include <ncurses/curses.h>




int Winner() {
    initscr();
    start_color();
    noecho();
    init_pair(1, COLOR_WHITE, COLOR_BLUE);
    init_pair(2, COLOR_WHITE, COLOR_RED);

    std::string judul [] = {
        " _   _    _    ___   ___  _  _ __   __   _    ___   ___  ___  ___",
        "| | | |  /_\\  | _ \\ |_ _|| \\| |\\ \\ / /  /_\\  |   \\ | __|| _ \\/ __|",
        "| |_| | / _ \\ |  _/  | | | .` | \\ V /  / _ \\ | |) || _| |   /\\__ \\ " ,
        " \\___/ /_/ \\_\\|_|   |___||_|\\_|  \\_/  /_/ \\_\\|___/ |___||_|_\\|___/",
                                                                 
    };

    std::string menu [2] = {
        "Restart Game",
        "Exit",
    };

    int panjangJudul = sizeof(judul) / sizeof(judul[0]);
    int panjangMenu1 = sizeof(menu) / sizeof(menu[0]);
    int panjangMenu2 = sizeof(menu) / sizeof(menu[1]);
    int y = Koordinat('y', "middle");
    int x = Koordinat('x', "middle");

    for(int i = 0; i < panjangJudul; i++) {
        mvprintw((y / 2) + i, (x / panjangJudul) + 15, "%s" ,judul[i].c_str());
        refresh();
        Sleep(200);
    }


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
                    return 1;
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