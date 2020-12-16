#include "EndGame.h"

int startx = 0;
int starty = 0;

char *choices[] = {
	"GAME 1",
	"GAME 2",
	"GAME 3",
	"EXIT",
	NULL};

char *choices_game_1[] = {
	"EASY",
	"NORMAL",
	"HARD",
	"BACK",
	NULL};

char *choices_game_2[] = {
	"EASY",
	"NORMAL",
	"HARD",
	"BACK",
	NULL};
char *choices_game_3[] = {
	"EASY",
	"NORMAL",
	"HARD",
	"BACK",
	NULL};

int n_choices = sizeof(choices) / sizeof(char *);

void mx_game_1() {
	int highlight_game_1 = 0;

	WINDOW *game1_win = newwin(HEIGHT, WIDTH, starty, startx);
	print_menu(game1_win, highlight_game_1, choices_game_1);
	keypad(game1_win, TRUE);
	while (true) {
		int d = wgetch(game1_win);
		switch(d) {
			case KEY_UP:
				mvwprintw(game1_win, 3, 5, "%d", highlight_game_1);
				if(highlight_game_1 == 0)
					highlight_game_1 = n_choices - 2;
				else
					--highlight_game_1;
				break;
			case KEY_DOWN:
				mvwprintw(game1_win, 3, 5, "%d", highlight_game_1);
				if(highlight_game_1 == n_choices - 2)
					highlight_game_1 = 0;
				else
					++highlight_game_1;
				break;
		}
		print_menu(game1_win, highlight_game_1, choices_game_1);
		if (d == 10 && highlight_game_1 == 0) {
			clear();
			mx_ping_pong(EASY);
		}
		if (d == 10 && highlight_game_1 == 1) {
			clear();
			mx_ping_pong(NORMAL);
		}
		if (d == 10 && highlight_game_1 == 2) {
			clear();
			mx_ping_pong(HARD);
		}
		if (d == 10 && highlight_game_1 == 3) {
			clear();
			break;
		}
	}
}

void mx_game_2() {
	int highlight_game_2 = 1;

	WINDOW *game2_win = newwin(HEIGHT, WIDTH, starty, startx);
	print_menu(game2_win, highlight_game_2, choices_game_2);
	keypad(game2_win, TRUE);
	while (true) {
		int d = wgetch(game2_win);
		switch(d) {
			case KEY_UP:
				mvwprintw(game2_win, 3, 5, "%d", highlight_game_2);
				if (highlight_game_2 == 1)
					highlight_game_2 = n_choices;
				else
					--highlight_game_2;
				break;
			case KEY_DOWN:
				mvwprintw(game2_win, 3, 5, "%d", highlight_game_2);
				if(highlight_game_2 == n_choices)
					highlight_game_2 = 1;
				else
					++highlight_game_2;
				break;
		}
		print_menu(game2_win, highlight_game_2, choices_game_2);
		if (d == 10 && highlight_game_2 == 1) {
			break;
		}
		if (d == 10 && highlight_game_2 == 2) {
			break;
		}
		if (d == 10 && highlight_game_2 == 3) {
			break;
		}
		if (d == 10 && highlight_game_2 == 4) {
			break;
		}
		print_menu(game2_win, highlight_game_2, choices_game_2);
	}
}

void mx_game_3() {
	int highlight_game_3 = 1;

	WINDOW *game3_win = newwin(HEIGHT, WIDTH, starty, startx);
	print_menu(game3_win, highlight_game_3, choices_game_3);
	keypad(game3_win, TRUE);
	while (true) {
		int d = wgetch(game3_win);
		switch(d) {
			case KEY_UP:
				mvwprintw(game3_win, 3, 5, "%d", highlight_game_3);
				if(highlight_game_3 == 1)
					highlight_game_3 = n_choices;
				else
					--highlight_game_3;
				break;
			case KEY_DOWN:
				mvwprintw(game3_win, 3, 5, "%d", highlight_game_3);
				if(highlight_game_3 == n_choices)
					highlight_game_3 = 1;
				else
					++highlight_game_3;
				break;
		}
		print_menu(game3_win, highlight_game_3, choices_game_3);
		if (d == 10 && highlight_game_3 == 1) {
			break; 
		}
		if (d == 10 && highlight_game_3 == 2) {
			break; 
		}
		if (d == 10 && highlight_game_3 == 3) {
			break; 
		}
		if (d == 10 && highlight_game_3 == 4) {
			break;
		}
	}
}



void menu() {
	WINDOW *menu_win;
	int highlight = 0;
	int choice = 0;
	int c;
	char *help_phrase = "Use arrow keys to go up and down, Press enter to select a choice";

	initscr();
	clear();
	noecho();
	cbreak();	/* Line buffering disabled. pass on everything */
	startx = (getmaxx(stdscr) - WIDTH) / 2;
	starty = (getmaxy(stdscr) - HEIGHT) / 2;

	menu_win = newwin(HEIGHT, WIDTH, starty, startx);
	keypad(menu_win, TRUE);
	curs_set(FALSE);
	mvprintw(starty - 2, (getmaxx(stdscr) - strlen(help_phrase)) / 2, help_phrase);
	refresh();
	print_menu(menu_win, highlight, choices);
	while(1) {
		c = wgetch(menu_win);
		switch(c) {
			case KEY_UP:
				if(highlight == 0)
					highlight = n_choices - 2;
				else
					--highlight;
				break;
			case KEY_DOWN:
				if(highlight == n_choices - 2)
					highlight = 0;
				else
					++highlight;
				break;
		}
		print_menu(menu_win, highlight, choices);
		if (c == 10 && highlight == 0) {
			destroy_win(menu_win);
			mx_game_1();
			menu_win = newwin(HEIGHT, WIDTH, starty, startx);
		}
		if (c == 10 && highlight == 1) {
			destroy_win(menu_win);
			mx_game_2();
			menu_win = newwin(HEIGHT, WIDTH, starty, startx);
		}
		if (c == 10 && highlight == 2) {
			destroy_win(menu_win);
			mx_game_3();
			menu_win = newwin(HEIGHT, WIDTH, starty, startx);
		}
		if (c == 10 && highlight == 3)
			break;
	}
	mvprintw(23, 0, "You chose choice %d with choice string %s\n", choice, choices[choice - 1]);
	clrtoeol();
	refresh();
	endwin();
}

void print_menu(WINDOW *menu_win, int highlight, char **choices) {
	int y = 2;
	keypad(menu_win, TRUE);
	box(menu_win, 0, 0);
	for(int i = 0; choices[i]; ++i) {
		if (highlight == i) { /* High light the present choice */
			wattron(menu_win, A_REVERSE);
			mvwprintw(menu_win, y++, (getmaxx(menu_win) - strlen(choices[i])) / 2, "%s", choices[i] );
			wattroff(menu_win, A_REVERSE);
		}
		else
			mvwprintw(menu_win, y++, (getmaxx(menu_win) - strlen(choices[i])) / 2, "%s", choices[i]);
	}
	wrefresh(menu_win);
}

void destroy_win(WINDOW *local_win) {
	wclear(local_win);
	wborder(local_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	wrefresh(local_win);
	delwin(local_win);
}
