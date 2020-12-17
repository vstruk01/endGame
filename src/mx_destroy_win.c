#include "EndGame.h"

void mx_destroy_win(WINDOW *local_win) {
	wclear(local_win);
	wborder(local_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	wrefresh(local_win);
	delwin(local_win);
}

