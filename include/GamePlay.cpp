#include <ncurses/curses.h>
#include <cstdlib>
#include <string>
#include <ctime>
#include "define.h"
#include <windows.h>
#include <unistd.h>

void Pesawat(int pesawatx, int pesawaty) {
	std::string pesawat[3] = {	 "  _</|\\>_ ",
							 " /_(_|_)_\\ ",
							 "   /_^_\\  "};

	for(int i = 0; i < 3; i++){
		mvprintw(pesawaty + i, pesawatx, "%s", pesawat[i].c_str());
		refresh();
	}
}

void TembakkanPeluru(int maxPeluru, int pesawatx, int pesawaty, bool peluruAktif[], int peluruX[], int peluruY[]) {
    for (int i = 0; i < maxPeluru; i++) {
        if (!peluruAktif[i]) {
            peluruX[i] = pesawatx + 5;
            peluruY[i] = pesawaty - 1;
            peluruAktif[i] = true;
            break;
        }
    }
}


void GerakMusuh(int jumlahMusuh, bool musuhAktif[], int musuhX[], int musuhY[], int musuhTersisa) {
    for (int i = 0; i < jumlahMusuh; i++) {
        if (musuhAktif[i]) {
            if (musuhY[i] >= Koordinat('y', "none")) {
                musuhY[i] = 0;
                musuhX[i] = rand() % Koordinat('x', "none") - 10;
            }
			if(musuhX[i] < 0) musuhX[i] *= -1;
            	mvprintw(musuhY[i] + 2, musuhX[i], "\\_/");
        } else if(musuhTersisa >= jumlahMusuh) {
			musuhX[i] = rand() % Koordinat('x', "none") - 10;
			musuhY[i] = 0;
			musuhAktif[i] = true;
		}
    }
}

void MusuhMenembak(int jumlahMusuh, bool musuhAktif[], int musuhX[], int musuhY[], int peluruMusuhMax, bool peluruMusuhAktif[], int peluruMusuhX[], int peluruMusuhY[]) {
    for (int i = 0; i < jumlahMusuh; i++) {
        if (musuhAktif[i] && rand() % 10 == 0) {
            for (int j = 0; j < peluruMusuhMax; j++) {
                if (!peluruMusuhAktif[j]) {
                    peluruMusuhX[j] = musuhX[i];
                    peluruMusuhY[j] = musuhY[i];
                    peluruMusuhAktif[j] = true;
                    break;
                }
            }
        }
    }
}

void GerakPeluruMusuh(int peluruMusuhMax, bool peluruMusuhAktif[], int peluruMusuhX[], int peluruMusuhY[]) {
    for (int i = 0; i < peluruMusuhMax; i++) {
        if (peluruMusuhAktif[i] <= 10) {
			peluruMusuhY[i]++;
            if (peluruMusuhY[i] >= Koordinat('y', "none")) {
                peluruMusuhAktif[i] = false;
            } else {
                mvprintw(peluruMusuhY[i] + 2, peluruMusuhX[i] + 1, "|");
            }
        }
    }
}

void GamePlay() {
    srand(time(0));
    initscr();
    curs_set(0);
    keypad(stdscr, TRUE);

	bool menang = false;
	bool sleep = true;

	int maxPeluru = 1;
	int jumlahMusuh = 10;
	int totalMusuh = 12;
	int peluruMusuhMax = jumlahMusuh;

	int pesawatx, pesawaty, darah = 100, kill = 0, peluru = maxPeluru, musuh = totalMusuh;
	int peluruX[maxPeluru], peluruY[maxPeluru];
	bool peluruAktif[maxPeluru];
	int peluruKe = maxPeluru;

	int musuhX[jumlahMusuh], musuhY[jumlahMusuh];
	bool musuhAktif[jumlahMusuh];

	int peluruMusuhX[peluruMusuhMax], peluruMusuhY[peluruMusuhMax];
	bool peluruMusuhAktif[peluruMusuhMax];

    pesawatx = Koordinat('x', "none") / 2;
    pesawaty = Koordinat('y', "none") - 3;
    for (int i = 0; i < maxPeluru; i++) {
        peluruY[i] = -1;
		peluruX[i] = -1;
        peluruAktif[i] = false;
    }

    for (int i = 0; i < jumlahMusuh; i++) {
        musuhX[i] = rand() % Koordinat('x', "none");
        musuhY[i] = 0;
        musuhAktif[i] = true;
    }

    for (int i = 0; i < peluruMusuhMax; i++) {
        peluruMusuhX[i] = -1;
        peluruMusuhY[i] = -1;
        peluruMusuhAktif[i] = false;
    }

    while (darah > 0) {
		clear();
		mvprintw(3, 0, "Darah: %d", darah);
		mvprintw(4, 0, "Kill: %d", kill);
		mvprintw(5, 0, "Peluru: %d", peluru);
		mvprintw(6, 0, "Musuh: %d", musuh);

        for (int i = 0; i < maxPeluru; i++) {
			if (peluruAktif[i]) {
				peluruY[i]--;
				if (peluruY[i] < 0) {
					peluruAktif[i] = false;
				} else {
					mvprintw(peluruY[i], peluruX[i], "|");
				}
			}
		}

        Pesawat(pesawatx, pesawaty);
		if(sleep) {
			Sleep(2000);
			sleep = false;
		}
        GerakMusuh(jumlahMusuh, musuhAktif, musuhX, musuhY, musuh);
        MusuhMenembak(jumlahMusuh, musuhAktif, musuhX, musuhY, peluruMusuhMax, peluruMusuhAktif, peluruMusuhX, peluruMusuhY);
        GerakPeluruMusuh(peluruMusuhMax, peluruMusuhAktif, peluruMusuhX, peluruMusuhY);
		
        for (int i = 0; i < maxPeluru; i++) {
			if (peluruAktif[i]) {
				for (int j = 0; j < jumlahMusuh; j++) {
					if (musuhAktif[j] && peluruX[i] >= musuhX[j] - 2 && peluruX[i] <= musuhX[j] + 2 && peluruY[i] >= musuhY[j] - 2 && peluruY[i] <= musuhY[j] + 2) {
						musuhAktif[j] = false;
						peluruAktif[i] = false;
						peluruX[i] = -1;
						peluru++;
						maxPeluru++;
						kill++;
						musuh--;
						break;
					}
				}
			}
		}

		for (int i = 0; i < peluruMusuhMax; i++) {
			if (peluruMusuhAktif[i] && peluruMusuhX[i] >= pesawatx && peluruMusuhX[i] <= pesawatx + 9 && peluruMusuhY[i] >= pesawaty && peluruMusuhY[i] <= pesawaty) {
				darah -= 10;
				peluruMusuhAktif[i] = false;
				break;
			}
		}

        int ch = getch();
        switch (ch) {
            case 'a':
                if (pesawatx > 0) pesawatx--;
                break;
            case 'd':
                if (pesawatx < Koordinat('x', "none") - 10) pesawatx++;
                break;
			case 'w':
				if(pesawaty != Koordinat('y', "none") - 6) pesawaty -= 1;
				break;
			case 's':
				if (pesawaty < Koordinat('y', "none") - 3) pesawaty++;
				break;
            case ' ':
                TembakkanPeluru(maxPeluru, pesawatx, pesawaty, peluruAktif, peluruX, peluruY);
                break;
        }

        refresh();
        Sleep(100);

		for (int i = 0; i < jumlahMusuh; i++) {
			if (!musuhAktif[i]) {
				menang = true;
			} else {
				menang = false;
				break;
			}
		}

		if(menang) break;
    }

	if(menang) {
		Winner();
	} else {
		GameOver();
	}

    refresh();
    endwin();
}
