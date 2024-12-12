#include <ncurses/curses.h>
#include <string>
#include <windows.h>
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

int middle(char xy){
    if(xy == 'x') return size('x') / 2;
    if(xy == 'y') return size('y') / 2;
}

int main(){
    string skull [] = {

        "                             .:==++++=-.            ",                            
        "                          :=*############+-         ",                           
        "                        .:##################:.      ",                             
        "                       .+####################*-     ",                        
        "                       -######################+-      ",                    
        "                      -########################+     ",                  
        "                      #######*#########**######:    ",             
        "                     .######= *########: *#####=    ",              
        "                     .######-.+########..+#####-   ",              
        "                      *########################.    ",            
        "                      .*######################-    ",           
        "                        +####################-      ",        
        "                          :###*=*#+.-##++###=       ",             
        "                          *##. :#= .#*  *##.        ",       
        "                           *##. :#= .#*  *##.       ",      
        "                          .::   :.  ::  :::         ",
        

    };

    string over [] = {
        " __ _  __ _  _ __   ___   ___ __ __ ___  _ _ ",
        "/ _` |/ _` || '  \\ / -_) / _ \\\\ V // -_)| '_|",
        "\\__, |\\__,_||_|_|_|\\___| \\___/ \\_/ \\___||_|  ",
        "|___/                                       ",
        
                                                                 
    };


    int panjangJudul = sizeof(over) / sizeof(over[0]);
    int panjangAlien = sizeof(skull) / sizeof(skull[0]);
    int y = middle('y') - 4;
    int x = middle('x') - 33;
    initscr();

    curs_set(0);
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);

    start_color();
    init_pair(1, COLOR_CYAN, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);

        attron(COLOR_PAIR(2)); 
        mvprintw (y + 0 - 8, x + 2, "%s", skull[0].c_str());
        mvprintw (y + 1 - 8, x + 2, "%s", skull[1].c_str());
        mvprintw (y + 2 - 8, x + 2, "%s", skull[2].c_str());
        mvprintw (y + 3 - 8, x + 2, "%s", skull[3].c_str());
        mvprintw (y + 4 - 8, x + 2, "%s", skull[4].c_str());
        mvprintw (y + 5 - 8, x + 2, "%s", skull[5].c_str());
        mvprintw (y + 6 - 8, x + 2, "%s", skull[6].c_str());
        mvprintw (y + 7 - 8, x + 2, "%s", skull[7].c_str());
        mvprintw (y + 8 - 8, x + 2, "%s", skull[8].c_str());
        mvprintw (y + 9 - 8, x + 2, "%s", skull[9].c_str());
        mvprintw (y + 10 - 8, x + 2, "%s", skull[10].c_str());
        mvprintw (y + 11 - 8, x + 2, "%s", skull[11].c_str());
        mvprintw (y + 12 - 8, x + 2, "%s", skull[12].c_str());
        mvprintw (y + 13 - 8, x + 2, "%s", skull[13].c_str());
        mvprintw (y + 14 - 8, x + 2, "%s", skull[14].c_str());
        mvprintw (y + 15 - 8, x + 2, "%s", skull[15].c_str());        
        attroff(COLOR_PAIR(2));

        Sleep(50);
        refresh();

        attron(COLOR_PAIR(1));
        mvprintw (y + 0 + 13, x + 15, "%s", over[0].c_str());
        mvprintw (y + 1 + 13, x + 15, "%s", over[1].c_str());
        mvprintw (y + 2 + 13, x + 15, "%s", over[2].c_str());    
        mvprintw (y + 3 + 13, x + 15, "%s", over[3].c_str());
        attroff(COLOR_PAIR(1));
        refresh();

    Sleep(3000);

    getch();
    endwin();
}


