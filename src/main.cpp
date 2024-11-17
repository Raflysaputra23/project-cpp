#include <string>
#include "modul/DisplayTextCenter.cpp"
#include "modul/BackgroundRandom.cpp"

int main() {
    std::string text[4] = {"Hallo","Rafly","Tisya","Abdul"};
    initscr();

    DisplayTextCenter(text, COLOR_GREEN, A_NORMAL);

    getch();
    endwin();
    return 0;
}