#include "EndGame.h"

#define DELAY 30000

int main() {
    mx_print_picture();

    int direction = false;
    int xr1 = 10, yr1 = 0;      // создаем начальные коородинаты ракетки 1
    int xr2 = 40, yr2 = 0;      // создаем начальные коородинаты ракетки 2
    int ball_x = 20, ball_y = 5;    // создаем начальные коородинаты мяча
    int sizer = 3;                // создаем переменную размер ракетки

    initscr();
    xr2 = getmaxx(stdscr) - 20;
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_WHITE);
    init_pair(2, COLOR_WHITE, COLOR_BLACK);
    cbreak();
    timeout(10);
    wbkgd(stdscr, COLOR_PAIR(2));
    noecho();
    curs_set(FALSE);

    for (int i = 0; i < sizer; ++i) {
        attron(COLOR_PAIR(1));
        mvprintw(yr1 + i, xr1, "|");
        mvprintw(yr2 + i, xr2, "|");
        attroff(COLOR_PAIR(1));
    }

    while (true) {
        switch (getch()) {
            case 'w':
                if (yr1 - 1 >= 0) {
                    mvprintw(yr1 + sizer - 1, xr1, " ");
                    yr1--;
                    attron(COLOR_PAIR(1));
                    mvprintw(yr1, xr1, " ");
                    attroff(COLOR_PAIR(1));
                }
                break;
            case 's':
                if (getmaxy(stdscr) >= yr1 + sizer + 1) {
                    mvprintw(yr1, xr1, " ");
                    yr1++;
                    attron(COLOR_PAIR(1));
                    mvprintw(yr1 + sizer - 1, xr1, " ");
                    attroff(COLOR_PAIR(1));
                }
                break;
            case 65:
                if (yr2 - 1 >= 0) {
                    mvprintw(yr2 + sizer - 1, xr2, " ");
                    yr2--;
                    attron(COLOR_PAIR(1));
                    mvprintw(yr2, xr2, " ");
                    attroff(COLOR_PAIR(1));
                }
                break;
            case 66:
                if (getmaxy(stdscr) >= yr2 + sizer + 1) {
                    mvprintw(yr2, xr2, " ");
                    yr2++;
                    attron(COLOR_PAIR(1));
                    mvprintw(yr2 + sizer - 1, xr2, " ");
                    attroff(COLOR_PAIR(1));
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
            // attron(COLOR_PAIR(1));
            mvprintw(ball_y, ball_x, "o");
            // attroff(COLOR_PAIR(1));
        } else {
            mvprintw(ball_y, ball_x++, " ");
            // attron(COLOR_PAIR(1));
            mvprintw(ball_y, ball_x, "o");
            // attroff(COLOR_PAIR(1));
        }
        refresh();
    }
    endwin();
}
