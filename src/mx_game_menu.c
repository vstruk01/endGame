#include "EndGame.h"

void mx_game_menu(t_menu *menu) {
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