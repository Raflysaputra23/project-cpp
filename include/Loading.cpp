#include <iostream>
#include <ncurses/curses.h>
#include <windows.h>
using namespace std;


void teks(){
    string tulisan[4] = {   " ___  ___  _       _    __  __    _    _____ ",
                            "/ __|| __|| |     /_\\  |  \\/  |  /_\\  |_   _|",
                            "\\__ \\| _| | |__  / _ \\ | |\\/| | / _ \\   | |   ",
                            "|___/|___||____|/_/ \\_\\|_|  |_|/_/ \\_\\  |_|   "};

    string tulisan1[4] = {  " ___     _    _____    _    _  _   ___ ",
                            "|   \\   /_\\  |_   _|  /_\\  | \\| | / __|",
                            "| |) | / _ \\   | |   / _ \\ | .` || (_ |",
                            "|___/ /_/ \\_\\  |_|  /_/ \\_\\|_|\\_| \\___|"};

    for(int i = 0; i < 4; i++){
        mvprintw(LINES / 2 - 5 + i, COLS / 2 - 23, "%s", tulisan[i].c_str());
        mvprintw(LINES / 2 + 1 + i, COLS / 2 - 20, "%s", tulisan1[i].c_str());

        refresh();
        Sleep(200);
    }
}

void teks1(){
    string tulisan[9] = {   "   _     _      _     _      _     _      _     _   ",
                            "  (c).-.(c)    (c).-.(c)    (c).-.(c)    (c).-.(c)  ",
                            "   / ._. \\      / ._. \\      / ._. \\      / ._. \\   ",
                            " __\\( Y )/__  __\\( Y )/__  __\\( Y )/__  __\\( Y )/__ ",
                            "(_.-/'-'\\-._)(_.-/'-'\\-._)(_.-/'-'\\-._)(_.-/'-'\\-._)",
                            "   || R ||      || A ||      || W ||      || R ||   ",
                            " _.' `-' '._  _.' `-' '._  _.' `-' '._  _.' `-' '._ ",
                            "(.-./`-`\\.-.)(.-./`-'\\.-.)(.-./`-'\\.-.)(.-./`-`\\.-.)",
                            " `-'     `-'  `-'     `-'  `-'     `-'  `-'     `-' "};

    for(int i = 0; i < 9; i++){
        mvprintw(LINES / 2 - 4 + i, COLS / 2 - 26, "%s", tulisan[i].c_str());

        refresh();
        Sleep(100);
    }
}

void penghapus(){
    const char p1[] = " ";

    for(int i = 30; i <= COLS - 30; i++){
        mvprintw(LINES / 2 - 5, i, p1);
        mvprintw(LINES / 2 - 4, i, p1);
        mvprintw(LINES / 2 - 3, i, p1);
        mvprintw(LINES / 2 - 2, i, p1);
        mvprintw(LINES / 2 - 1, i, p1);
        mvprintw(LINES / 2, i, p1);
        mvprintw(LINES / 2 + 1, i, p1);
        mvprintw(LINES / 2 + 2, i, p1);
        mvprintw(LINES / 2 + 3, i, p1);
        mvprintw(LINES / 2 + 3, i, p1);
        mvprintw(LINES / 2 + 4, i, p1);
        mvprintw(LINES / 2 + 5, i, p1);

        refresh();
        Sleep(10);
    }
}

void Loading(){
    initscr();
    curs_set(0);
    start_color();
    
    string titik = "....";

    int a = 0;
    int b = 0;
    int c = 0;

    init_pair(1, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(2, COLOR_BLUE, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);

    
    for(int i=20; i<= COLS - 25; i++){
        mvprintw(5,i, "=");
        mvprintw(LINES - 5,i, "=");
        refresh();
        Sleep(50);
    }
    for(int i=5; i <= LINES - 5; i++ ){
        mvprintw(i,20, "#");
        mvprintw(i, COLS - 25, "#");
        refresh();
        Sleep(50);
    }

    attron(COLOR_PAIR(1));
    teks();

    Sleep(200);

    penghapus();

    attron(COLOR_PAIR(2));
    teks1();

    Sleep(500);

    penghapus();

    for (int i = 1; i <= 100; i++){
        if(a == 4) a = 0;
        if(a == 0) mvprintw(LINES/2 + 3, COLS/2 + 7, "                   ");
        attron(COLOR_PAIR(1));
        mvprintw(LINES/2 - 2,COLS/2 - 12, "-----------------------");
        mvprintw(LINES/2 + 2,COLS/2 - 12, "-----------------------");
        attroff(COLOR_PAIR(1));
        attron(COLOR_PAIR(2));
        mvprintw(LINES/2 - 1,COLS/2 - 6, "L O A D I N G ");
        mvprintw(LINES/2 + 1, COLS/2 - 1, "   %%");
        mvprintw(LINES/2 + 1, COLS/2 - 1, "%d", i);
        mvprintw(LINES/2 + 3, COLS/2 - 11, "tunggu sebentar ya");
        mvprintw(LINES/2 + 3, COLS/2 + 8 + a, "%c", titik[a]);
        attroff(COLOR_PAIR(2));
        
        refresh();
        Sleep(50);
        a++;
    }
    
    clear();
    endwin();

    
}