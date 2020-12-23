#pragma once

#include "minilibmx.h"

#include <ncurses.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <fcntl.h>
#include <curses.h>
#include <time.h>
#include <string.h>

#define WIDTH 30
#define HEIGHT 10

enum e_direction {
    LEFT,
    RIGHT,
    UP,
    DOWN,
    CENTER,
    NOT_MOVE
};

enum e_lvl {
    EASY,
    NORMAL,
    HARD
};

enum e_game {
    GAME_OVER,
    PAUSE
};

enum e_games {
    PING_PONG,
    BREAK_OUT,
    SPASE_INVADERS
};

typedef struct s_ping_pong {
    char ***numbers;

    unsigned long speed;
    int limit_left;
    int limit_right;

    int x_racket_1;
    int y_racket_1;
    int x_racket_2;
    int y_racket_2;

    int x_ball;
    int y_ball;

    int size_racket;
    int score_1;
    int score_2;

    enum e_direction direction_h;
    enum e_direction direction_v;
}              t_ping_pong;

typedef struct s_menu {
    char **main_m;
    char **pp_m;
    char **bo_m;
    char **si_m;
    char **game_m;
    char *help_phrase;

    int s_game_m;
    int s_help_phrase;
    int s_main_m;
    int startx;
    int starty;
    int count_choices;
    void (*game)(enum e_lvl);
}              t_menu;

// * picture
void mx_print_picture(void);


// * ping pong
void mx_ping_pong(enum e_lvl lvl);
char ***mx_init_numbers();
void mx_print_ascii_int(int n, char ***numbers, int x, int y, WINDOW *win);
void mx_clear_int(int n, char ***numbers, int x, int y, WINDOW *win);

// * menu
void mx_game_menu(t_menu *menu);
int mx_esc_menu(enum e_game game, int count1, int count2);
t_menu *mx_init_menu();
WINDOW *mx_init_menu_win(t_menu *menu);
void mx_clear_menu(t_menu **menu);
void menu();
void mx_destroy_win(WINDOW *local_win);
void mx_print_menu(WINDOW *menu_win, int highlight, char **choises);
void mx_game_1();


// * breakout
void mx_breakout(enum e_lvl lvl);
