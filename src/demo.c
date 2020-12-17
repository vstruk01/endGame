#include "EndGame.h"

void mx_game(t_menu *menu) {
	int pos = 0;
	WINDOW *game1_win = mx_init_menu_win(menu);

    mx_print_menu(game1_win, pos, menu->game_m);
    while (true) {
		int d = wgetch(game1_win);
		switch(d) {
			case KEY_UP:
                pos == 0 ? (pos = menu->s_game_m - 2) : --pos;
                mx_print_menu(game1_win, pos, menu->game_m);
                break;
			case KEY_DOWN:
                pos == menu->s_game_m - 2 ? (pos = 0) : ++pos;
                mx_print_menu(game1_win, pos, menu->game_m);
                break;
            case 10:
                clear();
                if (pos == 0) {
                    menu->game(EASY);
                } else if (pos == 1) {
                    menu->game(NORMAL);
                } else if (pos == 2) {
                    menu->game(HARD);
                } else if (pos == 3) {
                    return;
                } else {
					delwin(game1_win);
					refresh();
                    return;
                }
                mx_print_menu(game1_win, pos, menu->game_m);
                mvprintw(menu->starty - 2,
                         (getmaxx(stdscr) - strlen(menu->help_phrase)) / 2,
                         menu->help_phrase);
                break;
        }
		refresh();
	}
}

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
                    menu->game = NULL;
                } else if (highlight == 2) {
                    menu->game = NULL;
                } else {
                    mx_clear_menu(&menu);
                    mx_destroy_win(menu_win);
                    refresh();
                    endwin();
                    return;
                }
				mx_game(menu);
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
