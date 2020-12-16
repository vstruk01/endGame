#pragma once

#include "minilibmx.h"

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

#include <ncurses.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <fcntl.h>
#include <curses.h>
#include <time.h>
#include <string.h>


// * picture
void mx_print_picture(void);


// * ping pong
void mx_ping_pong(enum e_lvl lvl);
char ***mx_init_numbers();
void mx_print_ascii_int(int n, char ***numbers, int x, int y, WINDOW *win);
void mx_clear_int(int n, char ***numbers, int x, int y, WINDOW *win);

// * menu
void menu();
void destroy_win(WINDOW *local_win);
void print_menu(WINDOW *menu_win, int highlight, char **choises);
void mx_game_1();
