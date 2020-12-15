#include <stdio.h>
#include <ncurses.h>

#define WIDTH 30
#define HEIGHT 10 

int startx = 0;
int starty = 0;

char *choices[] = { 
			"GAME 1",
			"GAME 2",
			"GAME 3",
			"EXIT",
		  };
		  
char *choices_game_1[] = { 
			"EASY",
			"NORMAL",
			"HARD",
			"BACK",
		  };

char *choices_game_2[] = { 
			"EASY",
			"NORMAL",
			"HARD",
			"BACK",
		  };
char *choices_game_3[] = { 
			"EASY",
			"NORMAL",
			"HARD",
			"BACK",
		  };
		  
int n_choices = sizeof(choices) / sizeof(char *);
// int n_choices_game_1 = sizeof(choices_game_1) / sizeof(char *);
// int n_choices_game_2 = sizeof(choices_game_2) / sizeof(char *);
// int n_choices_game_3 = sizeof(choices_game_3) / sizeof(char *);

void destroy_win(WINDOW *local_win);
void print_menu(WINDOW *menu_win, int highlight, char **choises);
void mx_game_1();

void mx_game_1() {
	int highlight_game_1 = 1;
	
	WINDOW *game1_win = newwin(HEIGHT, WIDTH, starty, startx);
	print_menu(game1_win, highlight_game_1, choices_game_1);
	keypad(game1_win, TRUE);
	while (true) {
		int d = wgetch(game1_win);
		switch(d) {
			case KEY_UP:
				mvwprintw(game1_win, 3, 5, "%d", highlight_game_1);
				if(highlight_game_1 == 1)
					highlight_game_1 = n_choices;
				else
					--highlight_game_1;
				break;
			case KEY_DOWN:
				mvwprintw(game1_win, 3, 5, "%d", highlight_game_1);
				if(highlight_game_1 == n_choices)
					highlight_game_1 = 1;
				else 
					++highlight_game_1;
				break;
		}
		print_menu(game1_win, highlight_game_1, choices_game_1);
		if (d == 10 && highlight_game_1 == 1) {
			break; 
		}
		if (d == 10 && highlight_game_1 == 2) {
			break; 
		}
		if (d == 10 && highlight_game_1 == 3) {
			break; 
		}
		if (d == 10 && highlight_game_1 == 4) {
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
				if(highlight_game_2 == 1)
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



int main() {	
	WINDOW *menu_win;
	int highlight = 1;
	int highlight_game_1 = 1;
	int highlight_game_2 = 1;
	int highlight_game_3 = 1;
	int choice = 0;
	int choice2 = 0;
	int c, d;
	

	initscr();
	clear();
	noecho();
	cbreak();	/* Line buffering disabled. pass on everything */
	// int max_y = 0, max_x = 0;
	// int WIDTH = 0;
	// int HEIGTH = 0;
	// getmaxyx(stdscr, max_y, max_x);
	startx = (80 - WIDTH) / 2;
	starty = (24 - HEIGHT) / 2;
	
	menu_win = newwin(HEIGHT, WIDTH, starty, startx);
	keypad(menu_win, TRUE);
	mvprintw(0, 0, "Use arrow keys to go up and down, Press enter to select a choice");
	refresh();
	print_menu(menu_win, highlight, choices);
	while(1) {
		c = wgetch(menu_win);
		switch(c) {
			case KEY_UP:
				if(highlight == 1)
					highlight = n_choices;
				else
					--highlight;
				break;
			case KEY_DOWN:
				if(highlight == n_choices)
					highlight = 1;
				else 
					++highlight;
				break;
		}
		print_menu(menu_win, highlight, choices);
		if(choice2 != 0)	/* User did a choice come out of the infinite loop */
			break;	
		if (c == 10 && highlight == 1) {
			destroy_win(menu_win);
			mx_game_1();
			menu_win = newwin(HEIGHT, WIDTH, starty, startx);
			print_menu(menu_win, highlight, choices);
		}
		if (c == 10 && highlight == 2) {
			destroy_win(menu_win);
			mx_game_2();
			menu_win = newwin(HEIGHT, WIDTH, starty, startx);
			print_menu(menu_win, highlight, choices);
		}
		if (c == 10 && highlight == 3) {
			destroy_win(menu_win);
			mx_game_3();
			menu_win = newwin(HEIGHT, WIDTH, starty, startx);
			print_menu(menu_win, highlight, choices);
		}
		if (c == 10 && highlight == 4) break;
		
	}
	mvprintw(23, 0, "You chose choice %d with choice string %s\n", choice, choices[choice - 1]);
	clrtoeol();
	refresh();
	endwin();
	return 0;
}

// void print_menu(WINDOW *menu_win, int highlight, char **choices);
void print_menu(WINDOW *menu_win, int highlight, char **choices)
{
	int x, y, i;	
	keypad(menu_win, TRUE);
	x = 2;
	y = 2;
	box(menu_win, 0, 0);
	for(i = 0; i < n_choices; ++i)
	{	if(highlight == i + 1) /* High light the present choice */
		{	wattron(menu_win, A_REVERSE); 
			mvwprintw(menu_win, y, x, "%s", choices[i]);
			wattroff(menu_win, A_REVERSE);
		}
		else
			mvwprintw(menu_win, y, x, "%s", choices[i]);
		++y;
	}
	wrefresh(menu_win);
}

void destroy_win(WINDOW *local_win)
{
	wclear(local_win);
	wborder(local_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	wrefresh(local_win);
	delwin(local_win);
}
