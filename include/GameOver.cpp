#include <ncurses/curses.h>
#include <string>
#include <windows.h>
#include "define.h"
using namespace std;

int size(char xy){
    initscr();

    int sizeX;
    int sizeY;
    getmaxyx(stdscr, sizeY, sizeX);

    if(xy == 'x'||xy == 'X') return sizeX;
    if(xy == 'y'||xy == 'X') return sizeY;

    endwin();
}


void GameOver(){
    string skull [] = {

        "                             .:==++++=-.            ",                            
        "                          :=*############+-         ",                           
        "                        .:##################:.      ",                             
        "                       .+####################*-     ",                        
        "                       -#####################+      ",                    
        "                      -#######################+     ",                  
        "                      #######*#########**######:    ",             
        "                     .######= *########: *#####=    ",              
        "                      .######-.+########..+#####-   ",              
        "                      *########################.    ",            
        "                       .*######################-    ",           
        "                        +####################-      ",        
        "                          :###*=*#+.-##++###=       ",             
        "                          *##. :#= .#*  *##.        ",       
        "                           *##. :#= .#*  *##.       ",      
        "                          .::   :.  ::  :::         ",
        

    };

    string over [] = {
        " __ _  __ _  _ __   ___   ___ __ __ ___  _ _ ",
        "/ _` |/ _` || '  \\ / -_) / _ \\ V // -_)| '_|",
        "\\__, |\\__,_||_|_|_|\\___| \\___/ \\_/ \\___||_|  ",
        "|___/                                       ",
        
                                                                 
    };

    string penghapus = " ";

    int panjangJudul = sizeof(over) / sizeof(over[0]);
    int panjangAlien = sizeof(skull) / sizeof(skull[0]);
    int y = Middle('y') - 4;
    int x = Middle('x') - 33;
    initscr();

    curs_set(0);
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);

    // for (int i = 0; i < 9; i++){
    //     mvprintw (y + i - 6, x + 7, "%s", skull[i].c_str());
    //     Sleep(50);
    //     refresh();
    // }

    for (int i = 0; i < 16; i++){
        mvprintw (y + i - 8, x + 2, "%s", skull[i].c_str());
        Sleep(50);
        refresh();
    }

    // for (int i = 0; i < 9; i++){
    //     mvprintw (y + i - 6, x + 47, "%s", skull[i].c_str());
    //     Sleep(50);
    //     refresh();
    // }

    for (int i = 0; i < 4; i++){
        mvprintw (y + i + 13, x + 15, "%s", over[i].c_str());
        Sleep(200);
        refresh();
    }

    Sleep(2000);

    for(int i = 0; i < 70; i++){
        mvprintw (y - 9, x + i, "%s", penghapus.c_str());
        mvprintw (y - 8, x + i, "%s", penghapus.c_str());
        mvprintw (y - 7, x + i, "%s", penghapus.c_str());
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
        mvprintw (y + 9, x + i, "%s", penghapus.c_str());
        mvprintw (y + 10, x + i, "%s", penghapus.c_str());
        mvprintw (y + 11, x + i, "%s", penghapus.c_str());
        mvprintw (y + 12, x + i, "%s", penghapus.c_str());
        mvprintw (y + 13, x + i, "%s", penghapus.c_str());
        mvprintw (y + 14, x + i, "%s", penghapus.c_str());
        mvprintw (y + 15, x + i, "%s", penghapus.c_str());
        mvprintw (y + 16, x + i, "%s", penghapus.c_str());
        mvprintw (y + 17, x + i, "%s", penghapus.c_str());
        Sleep(10);
        refresh();
    }



    getch();
    endwin();
}


