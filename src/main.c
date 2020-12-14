#include "EndGame.h"

#define DELAY 30000

int main() {
    enum e_direction direction_h = RIGHT;
    enum e_direction direction_v = CENTER;
    enum e_direction direction_r1 = NOT_MOVE;
    enum e_direction direction_r2 = NOT_MOVE;
    int xr1 = 100, yr1 = 0;          // создаем начальные коородинаты ракетки 1
    int xr2 = 40, yr2 = 0;          // создаем начальные коородинаты ракетки 2
    int ball_x = 30, ball_y = 0;
    int sizer = 10;                  // создаем переменную размер ракетки

    initscr();

    srand(time(0));
    ball_y = (rand() % getmaxy(stdscr));
    xr2 = getmaxx(stdscr) - 100;

    start_color();
    nonl();
    cbreak();

    timeout(0);
    noecho();
    curs_set(FALSE);

    init_pair(1, COLOR_WHITE, COLOR_WHITE);
    init_pair(2, COLOR_WHITE, COLOR_BLACK);
    wbkgd(stdscr, COLOR_PAIR(2));

    for (int i = 0; i < sizer; ++i) {
        attron(COLOR_PAIR(1));
        mvprintw(yr1 + i, xr1, " ");
        mvprintw(yr2 + i, xr2, " ");
        attroff(COLOR_PAIR(1));
    }

    while (true) {
        // int ch = getch();
        // mvprintw(10, 10, "%d", ch);
        // ch = getch();
        // mvprintw(10, 10, "%d", ch);
        // ch = getch();
        // mvprintw(10, 10, "%d", ch);
        // ch = getch();
        // mvprintw(10, 10, "%d", ch);

        int ch = getch();

        if (ch != EOF) {
            if (ch == 27) {
                getch();
                ch = getch();
            }
            while(getch() != EOF) {};
        }
        switch (ch) {
            case 'w':
                if (yr1 - 1 >= 0) {
                    mvprintw(yr1 + sizer - 1, xr1, " ");
                    yr1--;
                    attron(COLOR_PAIR(1));
                    mvprintw(yr1, xr1, " ");
                    attroff(COLOR_PAIR(1));
                    direction_r1 = UP;
                }
                break;
            case 's':
                if (getmaxy(stdscr) >= yr1 + sizer + 1) {
                    mvprintw(yr1, xr1, " ");
                    yr1++;
                    attron(COLOR_PAIR(1));
                    mvprintw(yr1 + sizer - 1, xr1, " ");
                    attroff(COLOR_PAIR(1));
                    direction_r1 = DOWN;
                }
                break;
            case 65:
                if (yr2 - 1 >= 0) {
                    mvprintw(yr2 + sizer - 1, xr2, " ");
                    yr2--;
                    attron(COLOR_PAIR(1));
                    mvprintw(yr2, xr2, " ");
                    attroff(COLOR_PAIR(1));
                    direction_r2 = UP;
                }
                break;
            case 66:
                if (getmaxy(stdscr) >= yr2 + sizer + 1) {
                    mvprintw(yr2, xr2, " ");
                    yr2++;
                    attron(COLOR_PAIR(1));
                    mvprintw(yr2 + sizer - 1, xr2, " ");
                    attroff(COLOR_PAIR(1));
                    direction_r2 = DOWN;
                }
                break;
        }

        mvprintw(ball_y, ball_x, " ");
        direction_h == RIGHT ? ++ball_x : --ball_x;
        if (direction_v == UP) {
            --ball_y;
        } else if (direction_v == DOWN) {
            ++ball_y;
        }

        if (ball_y >= yr2 && ball_y <= yr2 + sizer - 1
            && ball_x == xr2 && direction_h == RIGHT) {
            direction_h = LEFT;
            direction_r2 == UP ? (direction_v = UP) : (direction_v = DOWN);
            --ball_x;
        } else if (ball_y >= yr1 && ball_y <= yr1 + sizer - 1
                   && ball_x == xr1 && direction_h == LEFT) {
            direction_h = RIGHT;
            direction_r1 == UP ? (direction_v = UP) : (direction_v = DOWN);
            ++ball_x;
        }

        if (ball_y < 0 || ball_y >= getmaxy(stdscr)) {
            direction_v == DOWN ? (direction_v = UP) : (direction_v = DOWN);
        }

        mvprintw(ball_y, ball_x, "o");
        refresh();
        usleep(40000);
    }
    endwin();
}
