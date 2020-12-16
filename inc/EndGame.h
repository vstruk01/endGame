#pragma once

#include "minilibmx.h"

enum s_direction {
    LEFT,
    RIGHT
};

#include <ncurses.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <fcntl.h>
#include <curses.h>

void mx_print_picture(void);

