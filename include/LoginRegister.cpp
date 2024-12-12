#include "define.h"
#include <ncurses/curses.h>
#include <string>
#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

void LoginRegister();

#define KEY_ESC 27

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

void coorxy(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void frame(){
    for(int i = 20; i <= size('x') - 25; i++){
        coorxy(i, 5);
        cout << "=";
        coorxy(i, size('y') - 5);
        cout << "=";
    }

    for(int i = 5; i <= size('y') - 5; i++ ){
        coorxy(20, i);
        cout << "#";
        coorxy(size('x') - 25, i);
        cout << "#";
    }
}

void frame1(){
    for(int i = 20; i <= COLS - 25; i++){
        mvprintw(5, i, "=");
        mvprintw(LINES - 5,i, "=");
        refresh();
    }

    for(int i = 5; i <= LINES - 5; i++ ){
        mvprintw(i, 20, "#");
        mvprintw(i, COLS - 25, "#");
        refresh();
    }
}

void loading(){
    initscr();

    clear();

    frame1();

    curs_set(0);

    string titik = " ... ";
    int aaa = 0;

    for(int i = 1; i <= 100; i++){
        int angka = i;

        if(i >= 5 && i < 20) angka = 5;
        if(i >= 20 && i < 50) angka = i;
        if(i >= 50 && i < 75) angka = 50;
        if(i >= 75 && i < 90) angka = 75;
        if(i >= 90) angka = i;

        mvprintw(middle('y') - 1, middle('x') - 9 , "------------------");
        mvprintw(middle('y') + 1, middle('x') - 9, "------------------");
        mvprintw(middle('y'), middle('x') - 6, "Loading");
        mvprintw(middle('y'), middle('x') + 3 , "  %%");
        mvprintw(middle('y'), middle('x') + 2, "%d", angka);
        mvprintw(middle('y') + 2, middle('x') - 9,  "TUNGGU SEBENTAR");
        
        if(aaa == 5) aaa = 0;
        if(aaa == 0) mvprintw(middle('y') + 2, middle('x') + 7, "    ");
        if(i % 3 == 0) mvprintw(middle('y') + 2, middle('x') + 6 + aaa, "%c", titik[aaa]), aaa++;

        refresh();
        Sleep(100);
    }
    
    clear();
    endwin();
}


void teksReg(){
    string teks[6] = {  " _____   ______   _____  _____   _____  _______  ______  _____  ",
                        "|  __ \\ |  ____| / ____||_   _| / ____||__   __||  ____||  __ \\ ",
                        "| |__) || |__   | |  __   | |  | (___     | |   | |__   | |__) |",
                        "|  _  / |  __|  | | |_ |  | |   \\___ \\    | |   |  __|  |  _  / ",
                        "| | \\ \\ | |____ | |__| | _| |_  ____) |   | |   | |____ | | \\ \\ ",
                        "|_|  \\_\\|______| \\_____||_____||_____/    |_|   |______||_|  \\_\\"};

    for(int i = 0; i < 6; i++){
        coorxy(middle('x') - 32, middle('y') - 8 + i);
        cout << "\e[34m" << teks[i] << "\e[0m";
    }
}

void teksRegError(){
    string teks[4] = {  " ___  ___   ___  ___  ___  _____  ___    _    ___  ___ ",
                        "| _ \\| __| / __||_ _|/ __||_   _|| _ \\  /_\\  / __||_ _|",
                        "|   /| _| | (_ | | | \\__ \\  | |  |   / / _ \\ \\__ \\ | |  ",
                        "|_|_\\|___| \\___||___||___/  |_|  |_|_\\/_/ \\_\\|___/|___| "};

    for(int i = 0; i < 4; i++){
        coorxy(middle('x') - 28, middle('y') - 9 + i);
        cout << "\e[31m" << teks[i];
    }

    string teks1[4] = { "  ___    _     ___    _    _    ",
                        " / __|  /_\\   / __|  /_\\  | |   ",
                        "| (_ | / _ \\ | (_ | / _ \\ | |__ ",
                        " \\___|/_/ \\_\\ \\___|/_/ \\_\\|____|"};

    for(int i = 0; i < 4; i++){
        coorxy(middle('x') - 17, middle('y') - 4 + i);
        cout << teks1[i];
    }

    coorxy(middle('x') - 12, middle('y') + 3);
    cout << "Nama Sudah Digunakan";
    coorxy(middle('x') - 11, middle('y') + 5);
    cout << "Gunakan Nama Lain\e[0m";
}

void teksRegSuccess(){
    string teks[4] = {  " ___  ___   ___  ___  ___  _____  ___    _    ___  ___ ",
                        "| _ \\| __| / __||_ _|/ __||_   _|| _ \\  /_\\  / __||_ _|",
                        "|   /| _| | (_ | | | \\__ \\  | |  |   / / _ \\ \\__ \\ | |  ",
                        "|_|_\\|___| \\___||___||___/  |_|  |_|_\\/_/ \\_\\|___/|___| "};

    for(int i = 0; i < 4; i++){
        coorxy(middle('x') - 28, middle('y') - 4 + i);
        cout << "\e[32m" << teks[i];
    }

    string teks1[4] = { " ___  ___  ___  _  _    _    ___  ___  _    ",
                        "| _ )| __|| _ \\| || |  /_\\  / __||_ _|| |   ",
                        "| _ \\| _| |   /| __ | / _ \\ \\__ \\ | | | |__ ",
                        "|___/|___||_|_\\|_||_|/_/ \\_\\|___/|___||____|"};

    for(int i = 0; i < 4; i++){
        coorxy(middle('x') - 24, middle('y') + 1 + i);
        cout << "\e[32m" << teks1[i] << "\e[0m";
    }
}

void teksLog(){
    string teks[6] = {  " _        ____    _____  _____  _   _ ",
                        "| |      / __ \\  / ____||_   _|| \\ | |",
                        "| |     | |  | || |  __   | |  |  \\| |",
                        "| |     | |  | || | |_ |  | |  | . ` |",
                        "| |____ | |__| || |__| | _| |_ | |\\  |",
                        "|______| \\____/  \\_____||_____||_| \\_|"};

    for(int i = 0; i < 6; i++){
        coorxy(middle('x') - 20, middle('y') - 8 + i);
        cout << "\e[34m" << teks[i] << "\e[0m";
    }
}

void teksLogError(){
    string teks[4] = {  " _      ___    ___  ___  _  _ ",
                        "| |    / _ \\  / __||_ _|| \\| |",
                        "| |__ | (_) || (_ | | | | .` |",
                        "|____| \\___/  \\___||___||_|\\_|"};

    for(int i = 0; i < 4; i++){
        coorxy(middle('x') - 16, middle('y') - 6 + i);
        cout << "\e[31m" << teks[i];
    }

    string teks1[4] = { "  ___    _     ___    _    _    ",
                        " / __|  /_\\   / __|  /_\\  | |   ",
                        "| (_ | / _ \\ | (_ | / _ \\ | |__ ",
                        " \\___|/_/ \\_\\ \\___|/_/ \\_\\|____|"};

    for(int i = 0; i < 4; i++){
        coorxy(middle('x') - 17, middle('y') - 1 + i);
        cout << teks1[i];
    }

    coorxy(middle('x') - 15, middle('y') + 6);
    cout << "Periksa Kembali Nama Anda!!\e[0m";
}

void teksLogSuccess(){
   string teks[4] = {   " _      ___    ___  ___  _  _ ",
                        "| |    / _ \\  / __||_ _|| \\| |",
                        "| |__ | (_) || (_ | | | | .` |",
                        "|____| \\___/  \\___||___||_|\\_|"};

    for(int i = 0; i < 4; i++){
        coorxy(middle('x') - 17, middle('y') - 4 + i);
        cout << "\e[32m" << teks[i];
    }

    string teks1[4] = { " ___  ___  ___  _  _    _    ___  ___  _    ",
                        "| _ )| __|| _ \\| || |  /_\\  / __||_ _|| |   ",
                        "| _ \\| _| |   /| __ | / _ \\ \\__ \\ | | | |__ ",
                        "|___/|___||_|_\\|_||_|/_/ \\_\\|___/|___||____|"};

    for(int i = 0; i < 4; i++){
        coorxy(middle('x') - 23, middle('y') + 1 + i);
        cout << "\e[32m" << teks1[i] << "\e[0m";
    }
}

void Register(){
    system("cls");

    frame();

    ofstream myFile;
    ifstream myfile;
    string nama;

    teksReg();
    coorxy(middle('x') - 20, middle('y'));
    cout << "Masukkan Nama Anda :";
    coorxy(middle('x') - 8, middle('y') + 5);
    cout << "\e[31m\e[3mNama Tanpa Spasi\e[23m\e[0m";
    coorxy(middle('x') + 1, middle('y'));
    cin >> nama;

    myFile.open("../include/data/" + nama + ".txt");
    myFile << 0;
    myFile.close();

    string ListNama;
    bool cek = false;

    myfile.open("../include/data/Akun.txt", ios::app);

    do{
        if(nama == ListNama){
            cek = false;
            system("cls");
            frame();
            teksRegError();
            Sleep(2000);
            Register();
            break;
        } else {
            cek = true;
        }
    } while(myfile >> ListNama);

    myfile.close();

    if(cek){
        system("cls");
        frame();
        teksRegSuccess();    
        Sleep(2000);

        myFile.open("../include/data/Akun.txt", ios::app);
        myFile << nama << endl;
        myFile.close();

        system("cls");

        LoginRegister();
    }
}

void Login(){
    system("cls");

    frame();

    ifstream myfile;
    string nama;

    teksLog();
    coorxy(middle('x') - 20, middle('y'));
    cout << "Masukkan Nama Anda :";
    coorxy(middle('x') - 8, middle('y') + 5);
    cout << "\e[31m\e[3mNama Tanpa Spasi\e[23m\e[0m";
    coorxy(middle('x') + 1, middle('y'));
    cin >> nama;
    
    string ListNama;
    bool cek = false;

    myfile.open("../include/data/Akun.txt", ios::app);
    while(myfile >> ListNama){
        if(nama == ListNama){
            cek = true;
            break;
        } else {
            cek = false;
        }
    }
    myfile.close();

    if(cek){
        system("cls");
        frame();
        teksLogSuccess();
        Sleep(2000);
        system("cls");
        loading();
    } else {
        system("cls");
        frame();
        teksLogError();
        Sleep(2000);
        Login();
    }
}

void teksWelcome(){
    string teks[4] = {  "__      __ ___  _      ___   ___   __  __  ___ ",
                        "\\ \\    / /| __|| |    / __| / _ \\ |  \\/  || __|",
                        " \\ \\/\\/ / | _| | |__ | (__ | (_) || |\\/| || _| ",
                        "  \\_/\\_/  |___||____| \\___| \\___/ |_|  |_||___|"};

    for(int i = 0; i < 4; i++){
        mvprintw(middle('y') - 6 + i, middle('x') - 24, "%s", teks[i].c_str());
    }
}

void LoginRegister(){
    string arr[2] = {"      Register      ", "       Login        "};

    initscr();

    int baris_awal = middle('y') + 3;
    int kolom = middle('x') - 10;

    noecho();

    curs_set(0);

    start_color();

    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_BLACK, COLOR_WHITE);
    init_pair(3, COLOR_BLUE, COLOR_BLACK);

    attron(COLOR_PAIR(3));

    teksWelcome();

    attron(COLOR_PAIR(1));

    frame1();

    mvprintw(middle('y'), middle('x') - 7, "Silahkan Pilih");
    mvprintw(baris_awal, kolom, "%s", arr[0].c_str());
    mvprintw(baris_awal + 2, kolom, "%s", arr[1].c_str());

    keypad(stdscr, TRUE);

    int menu = 0;
    int menu_awal = 0;
    int menu_akhir = 1;
    int baris = baris_awal;
    int baris_akhir = baris_awal + 2;

    attron(COLOR_PAIR(2));
    mvprintw(baris_awal, kolom, "%s", arr[0].c_str());
    mvprintw(baris_awal, kolom, "<{");
    mvprintw(baris_awal, kolom + 18, "}>");
    attroff(COLOR_PAIR(2));

    int tombol;
    while(tombol != KEY_ESC){
        if((tombol = getch()) == ERR);

        if(tombol == 10){
            endwin();
            if(menu == 0){
                Register();
                break;
            }
            else if(menu == 1){
                Login();
                break;
            }
        }

        if(tombol == KEY_UP){
            baris -= 2;
            menu -= 1;

            if(menu == -1){
                baris = baris_akhir;
                menu = 1;
            }

            attron(COLOR_PAIR(2));
            mvprintw(baris, kolom, "%s", arr[menu].c_str());
            mvprintw(baris, kolom, "<{");
            mvprintw(baris, kolom + 18, "}>");
            attroff(COLOR_PAIR(2));

            attron(COLOR_PAIR(1));
            if(menu == 1){
                mvprintw(baris_awal, kolom, "%s", arr[menu_awal].c_str());
            } else {
                mvprintw(baris + 2, kolom, "%s", arr[menu + 1].c_str());
            }
            attroff(COLOR_PAIR(1));

        }
        else if(tombol == KEY_DOWN){
            baris += 2;
            menu += 1;

            if(menu == 2){
                baris = baris_awal;
                menu = 0;
            }

            attron(COLOR_PAIR(2));
            mvprintw(baris, kolom, "%s", arr[menu].c_str());
            mvprintw(baris, kolom, "<{");
            mvprintw(baris, kolom + 18, "}>");
            attroff(COLOR_PAIR(2));

            attron(COLOR_PAIR(1));
            if(menu == 0){
                mvprintw(baris_akhir, kolom, "%s", arr[menu_akhir].c_str());
            } else {
                mvprintw(baris - 2, kolom, "%s", arr[menu - 1].c_str());
            }
            attroff(COLOR_PAIR(1));
        }
    }
}