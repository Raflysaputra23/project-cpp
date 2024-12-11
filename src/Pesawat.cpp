#include <ncurses/curses.h>
#include <windows.h>
#include <string>

using namespace std;

#define KEY_ESCAPE 27

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

void Pesawat(int x, int y){
	string pesawat[3] = {	 "  _</|\\>_ ",
							 " /_(_|_)_\\ ",
							 "   /_^_\\  "};

	for(int i = 0; i < 3; i++){
		mvprintw(y + i, x, "%s", pesawat[i].c_str());
		refresh();
	}
}

int main(){
	
	initscr();

	cbreak();
	
	noecho();
	
	start_color();
	init_pair(1, COLOR_BLACK, COLOR_RED);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	
	curs_set(0);
	
	attron(COLOR_PAIR(2));
	const char penghapus[] = "            ";
	
	clear();

	keypad(stdscr, TRUE);

	nodelay(stdscr, TRUE);

	int pesawatx = middle('x') - 6;
	int pesawaty = size('y') - 3;

	int peluruMax = 10;
	int peluruKe = 0;

	int peluruX[peluruMax];
	int peluruY[peluruMax];

	for(int i = 0; i < peluruMax; i++){
		peluruX[i] = -1;
		peluruY[i] = -1;
	}

	Pesawat(pesawatx, pesawaty);

	int tombol;
	int a = 1;
	while((tombol = getch()) != KEY_ESCAPE){
		clear();
		
		if(tombol == 'w'){
			if(pesawaty != size('y') - 6) pesawaty -= 1;
		}
		else if(tombol == 's'){
			if(pesawaty != size('y') - 3) pesawaty += 1;
		}
		else if(tombol == 'a'){
			if(pesawatx != 0) pesawatx -= 1;
		}
		else if(tombol == 'd'){
			if(pesawatx != size('x') - 10) pesawatx += 1;
		}
		else if(tombol == ' '){
			if(peluruKe < peluruMax){
				peluruX[peluruKe] = pesawatx + 5;
				peluruY[peluruKe] = pesawaty - 1;
				peluruKe++;
			}
		}

		for(int i = 0; i < peluruKe; i++){
			if(peluruY[i] > 0){
				peluruY[i]--;
			} else {
				for(int j = i; j < peluruKe - 1; j++){
					peluruX[j] = peluruX[j + 1];
					peluruY[j] = peluruY[j + 1];
				}
				peluruKe--;
				i--;
			}
		}

		for(int i = 0; i < peluruKe; i++){
			mvprintw(peluruY[i], peluruX[i], "|");
		}
        
		Pesawat(pesawatx, pesawaty);
		
		refresh();
		Sleep(50);
	}
	
	refresh();
	
	getch();
	
	endwin();

}