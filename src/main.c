#include "EndGame.h"

#define DELAY 30000

int main() {
    int direction = false;
    int xr1 = 10, yr1 = 0;      // создаем начальные коородинаты ракетки 1
    int xr2 = 40, yr2 = 0;      // создаем начальные коородинаты ракетки 2
    int ball_x = 20, ball_y = 5;    // создаем начальные коородинаты мяча
    int sizer = 3;                // создаем переменную размер ракетки

    initscr();
    xr2 = getmaxx(stdscr) - 20;
    init_pair(1, COLOR_GREEN, COLOR_RED);
    // attron(COLOR_PAIR(1));
    cbreak();
    timeout(5);
    noecho();
    curs_set(FALSE);

    for (int i = 0; i < sizer; ++i) {
        mvprintw(yr1 + i, xr1, "|");
        mvprintw(yr2 + i, xr2, "|");
    }

    while (true) {
        switch (getch()) {
            case 'w':
                if (yr1 - 1 >= 0) {
                    // mvprintw(yr1 + sizer - 1, xr1, " ");
                    mvaddch(yr1, xr1, ' ' | COLOR_PAIR(0));
                    yr1--;
                    // mvprintw(yr1, xr1, "|");
                    mvaddch(yr1, xr1, COLOR_PAIR(1));
                }
                break;
            case 's':
                if (getmaxy(stdscr) >= yr1 + sizer + 1) {
                    mvprintw(yr1, xr1, " ");
                    yr1++;
                    mvprintw(yr1 + sizer - 1, xr1, "|");
                }
                break;
            case 65:
                if (yr2 - 1 >= 0) {
                    mvprintw(yr2 + sizer - 1, xr2, " ");
                    yr2--;
                    mvprintw(yr2, xr2, "|");
                }
                break;
            case 66:
                if (getmaxy(stdscr) >= yr2 + sizer + 1) {
                    mvprintw(yr2, xr2, " ");
                    yr2++;
                    mvprintw(yr2 + sizer - 1, xr2, "|");
                }
                break;
        }

        if (ball_y >= yr2 && ball_y <= yr2 + sizer && ball_x + 1 == xr2 && !direction) {
            direction = true;
        } else if (ball_y >= yr1 && ball_y <= yr1 + sizer && ball_x - 1 == xr1 && direction) {
            direction = false;
        }

        if (direction) {
            mvprintw(ball_y, ball_x--, " ");
            mvprintw(ball_y, ball_x, "o");
        } else {
            mvprintw(ball_y, ball_x++, " ");
            mvprintw(ball_y, ball_x, "o");    
        }
        refresh();
    }
    endwin();
}
