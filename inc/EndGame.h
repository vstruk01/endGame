#pragma once

#include "minilibmx.h"

enum e_direction {
    LEFT,
    RIGHT,
    UP,
    DOWN,
    CENTER,
    NOT_MOVE
};

#include <ncurses.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <fcntl.h>
#include <curses.h>
#include <time.h>

char ***mx_init_numbers();
void mx_print_ascii_int(int n, char ***numbers, int x, int y, WINDOW *win);
void mx_clear_int(int n, char ***numbers, int x, int y, WINDOW *win);
