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

