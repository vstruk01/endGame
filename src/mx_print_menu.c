#include "EndGame.h"

void mx_print_menu(WINDOW *menu_win, int highlight, char **choices) {
	int y = 2;

	keypad(menu_win, TRUE);
	box(menu_win, 2, 0);
	for(int i = 0; choices[i]; ++i, ++y) {
		if (highlight == i) {
			wattron(menu_win, A_REVERSE);
			mvwprintw(menu_win, y, (getmaxx(menu_win) - strlen(choices[i])) / 2, "%s", choices[i] );
			wattroff(menu_win, A_REVERSE);
		}
		else
			mvwprintw(menu_win, y, (getmaxx(menu_win) - strlen(choices[i])) / 2, "%s", choices[i]);
	}
	refresh();
	wrefresh(menu_win);
}

