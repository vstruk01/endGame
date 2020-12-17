#include "EndGame.h"

WINDOW *mx_init_menu_win(t_menu *menu) {
    WINDOW *win = newwin(HEIGHT, WIDTH, menu->starty, menu->startx);
    keypad(win, TRUE);
	mvprintw(menu->starty - 2,
			 (getmaxx(stdscr) - strlen(menu->help_phrase)) / 2,
			 menu->help_phrase);
	wtimeout(win, 0);
	return win;
}

