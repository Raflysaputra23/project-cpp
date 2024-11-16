#include "modul/DisplayTextCenter.cpp"

int main() {
    initscr();

    DisplayTextCenter(60, 10,"Hallo", COLOR_RED, A_BOLD);
    DisplayTextCenter(60, 11,"Rafly", COLOR_RED);
    DisplayTextCenter(60, 12,"Abdul", COLOR_RED);
    DisplayTextCenter(60, 13,"Tisya", COLOR_RED);
    
    getch();
    endwin();
    return 0;
}