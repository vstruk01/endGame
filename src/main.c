#include "EndGame.h"

#define DELAY 30000

int main() {
    // char c;

    // int fd = open(5, "rb");
    // read(5, &c, 1);
    // printf("%d\n", c);
    // read(0, &c, 1);
    // printf("%d\n", c);
    // read(0, &c, 1);
    // printf("%d\n", c);

    clock_t start = clock();
    clock_t end_time = 0;

    // char *buf1 = mx_strnew(20);
    // char *buf2 = mx_strnew(20);

    unsigned long speed = 10000;
    char ***numbers = mx_init_numbers();
    enum e_direction direction_h = RIGHT;
    enum e_direction direction_v = CENTER;
    enum e_direction direction_r1 = NOT_MOVE;
    enum e_direction direction_r2 = NOT_MOVE;
    int limit_left = 100, limit_right;
    int xr1 = limit_left, yr1 = 0;          // создаем начальные коородинаты ракетки 1
    int xr2 = 0, yr2 = 0;          // создаем начальные коородинаты ракетки 2
    int ball_x = limit_left + 10, ball_y = 0;
    int sizer = 10;                  // создаем переменную размер ракетки
    int score1 = 0, score2 = 0;

    initscr();

    // keypad(stdscr, TRUE);
    srand(time(0));
    ball_y = (rand() % getmaxy(stdscr));
    xr2 = getmaxx(stdscr) - 100;
    limit_right = xr2;


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
    mx_print_ascii_int(score1, numbers, 30, 5, stdscr);
    mx_print_ascii_int(score2, numbers, getmaxx(stdscr) - 30, 5, stdscr);
    // attron(A_STANDOUT);
    // mvwprintw(stdscr, 10, 20, "Hello");
    // attroff(A_STANDOUT);

    int jj = 10;
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
            mvwprintw(stdscr, 20, jj, "%d", ch);
            jj += 5;
            if (ch == 27) {
                // getch();
                ch = getch();
                mvwprintw(stdscr, 20, jj, "%d", ch);
                jj += 5;
                ch = getch();
                mvwprintw(stdscr, 20, jj, "%d", ch);
                jj += 5;
            }
            // int ch1 = 0;
            // for (int j = 10; (ch1 = getch()) != EOF; ++j) {
            //     mvwprintw(stdscr, 20, j, "%d ",ch1);
            // };
            // sleep(3);
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
        end_time = clock();

        if ((end_time - start > speed / 2 && direction_h == CENTER) 
             || (end_time - start > speed && direction_h != CENTER)) {
            start = end_time;
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
                printf("\a");
                --ball_x;
            } else if (ball_y >= yr1 && ball_y <= yr1 + sizer - 1
                       && ball_x == xr1 && direction_h == LEFT) {
                direction_h = RIGHT;
                direction_r1 == UP ? (direction_v = UP) : (direction_v = DOWN);
                printf("\a");
                ++ball_x;
            }

            if (ball_y < 0 || ball_y >= getmaxy(stdscr)) {
                direction_v == DOWN ? (direction_v = UP) : (direction_v = DOWN);
            }

            if (ball_x > limit_right + 50) {
                mx_clear_int(score1, numbers, 30, 5, stdscr);
                ball_x = limit_left + 10;
                ball_y = (rand() % getmaxy(stdscr));
                direction_h = RIGHT;
                direction_v = CENTER;
                ++score1;
                mx_print_ascii_int(score1, numbers, 30, 5, stdscr);
            } else if (ball_x < limit_left - 50) {
                mx_clear_int(score2, numbers, getmaxx(stdscr) - 30, 5, stdscr);
                ball_x = limit_left + 10;
                ball_y = (rand() % getmaxy(stdscr));
                direction_h = RIGHT;
                direction_v = CENTER;
                ++score2;
                mx_print_ascii_int(score2, numbers, getmaxx(stdscr) - 30, 5, stdscr);
            }
            mvprintw(ball_y, ball_x, "o");
        }
        refresh();
        // usleep(80000);
    }
    endwin();
}
