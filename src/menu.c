#include "EndGame.h"

void menu() {
    t_menu *menu = NULL;
	WINDOW *menu_win;
	int highlight = 0;

	initscr();
	noecho();
	timeout(0);
	start_color();
	cbreak();
	curs_set(FALSE);

	menu = mx_init_menu();
	menu_win = mx_init_menu_win(menu);
	mx_print_menu(menu_win, highlight, menu->main_m);

	while(true) {
		switch(wgetch(menu_win)) {
			case KEY_UP:
                !highlight ? (highlight = menu->s_main_m - 2) : --highlight;
                mx_print_menu(menu_win, highlight, menu->main_m);
                break;
			case KEY_DOWN:
				highlight == menu->s_main_m - 2 ? (highlight = 0) : ++highlight;
                mx_print_menu(menu_win, highlight, menu->main_m);
                break;
            case 10:
                clear();
				refresh();
                if (highlight == 0) {
                    menu->game = mx_ping_pong;
                } else if (highlight == 1) {
                    menu->game = mx_breakout;
                } else if (highlight == 2) {
                    menu->game = NULL;
                } else {
                    mx_clear_menu(&menu);
                    mx_destroy_win(menu_win);
                    refresh();
                    endwin();
                    return;
                }
				mx_game_menu(menu);
                mvprintw(menu->starty - 2,
                         (getmaxx(stdscr) - strlen(menu->help_phrase)) / 2,
                         menu->help_phrase);
                mx_print_menu(menu_win, highlight, menu->main_m);
                break;
		}
	}
	mx_clear_menu(&menu);
	mx_destroy_win(menu_win);
	refresh();
	endwin();
}
