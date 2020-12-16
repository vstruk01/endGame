#include "EndGame.h"

int mx_small_menu(enum e_game game, int count1, int count2) {
    int max_y = 0, max_x = 0, c = 0;

    // initscr();
    noecho();
    curs_set(FALSE);
    // keypad(stdscr, TRUE);
    getmaxyx(stdscr, max_y, max_x);

    while (1) {
        mvprintw(max_y - 2, 2, "Press 'e' to exit");
        if (count1 > count2 && game == GAME_OVER) {
            mvprintw(max_y / 2, (max_x / 2) - (mx_strlen("Player 1 wins!") / 2), "Player 1 wins!");
            mvprintw(max_y - 2, max_x - mx_strlen("Press 'r' to restart") - 2, "Press 'r' to restart");
        } else if (count1 < count2 && game == GAME_OVER) {
            mvprintw(max_y / 2, (max_x - mx_strlen("Player 2 wins!")) / 2, "Player 2 wins!");
            mvprintw(max_y - 2, max_x - mx_strlen("Press 'r' to restart") - 2, "Press 'r' to restart");
        } else {
            mvprintw(max_y / 2, (max_x - mx_strlen("PAUSE")) / 2, "PAUSE");
            mvprintw(max_y - 2, max_x - mx_strlen("Press 'c' to continue") - 2, "Press 'c' to continue");
        }
        refresh();
        c = getch();
        if (c == 'r' || c == 'c') {
            erase();
            refresh();
            return 0;
        }
        if (c == 'e') {
            erase();
            refresh();
            return 1;
        }
    }
}

void mx_ping_pong(enum e_lvl lvl) {
    lvl = NORMAL;
    clock_t start = clock();
    clock_t end_time = 0;

    unsigned long speed = 20000;
    char ***numbers = mx_init_numbers();
    enum e_direction direction_h = RIGHT;
    enum e_direction direction_v = CENTER;
    int limit_left = 100, limit_right;
    int xr1 = limit_left, yr1 = 0;
    int xr2 = 0, yr2 = 0;
    int ball_x = limit_left + 10, ball_y = 0;
    int sizer = 10;
    int score1 = 0, score2 = 0;

    // initscr();
    keypad(stdscr, TRUE);
    // srand(time(0));
    ball_y = getmaxy(stdscr) / 2;
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
    // wbkgd(stdscr, COLOR_PAIR(2));

    for (int i = 0; i < sizer; ++i) {
        attron(COLOR_PAIR(1));
        mvprintw(yr1 + i, xr1, " ");
        mvprintw(yr2 + i, xr2, " ");
        attroff(COLOR_PAIR(1));
    }
    mx_print_ascii_int(score1, numbers, 30, 5, stdscr);
    mx_print_ascii_int(score2, numbers, getmaxx(stdscr) - 30, 5, stdscr);

    while (true) {
        int ch = getch();
        switch (ch) {
            case 'w':
                for (int i = 0; i < 3 && yr1 > 0; ++i, --yr1) {
                    mvprintw(yr1 + sizer - 1, xr1, " ");
                    attron(COLOR_PAIR(1));
                    mvprintw(yr1 - 1, xr1, " ");
                    attroff(COLOR_PAIR(1));
                }
                break;
            case 's':
                for (int i = 0; i < 3 && yr1  + sizer - 1 < getmaxy(stdscr); ++i, ++yr1) {
                    mvprintw(yr1, xr1, " ");
                    attron(COLOR_PAIR(1));
                    mvprintw(yr1 + sizer - 1, xr1, " ");
                    attroff(COLOR_PAIR(1));
                }
                break;
            case KEY_UP:
               for (int i = 0; i < 3 && yr2 > 0; ++i, --yr2) {
                    mvprintw(yr2 + sizer - 1, xr2, " ");
                    attron(COLOR_PAIR(1));
                    mvprintw(yr2 - 1, xr2, " ");
                    attroff(COLOR_PAIR(1));
                }
                break;
            case KEY_DOWN:
                for (int i = 0; i < 3 && yr2 + sizer - 1 < getmaxy(stdscr); ++i, ++yr2) {
                    mvprintw(yr2, xr2, " ");
                    attron(COLOR_PAIR(1));
                    mvprintw(yr2 + sizer - 1, xr2, " ");
                    attroff(COLOR_PAIR(1));
                }
                break;
            case 27:
                erase();
                refresh();
                if (mx_small_menu(PAUSE, 0, 0)) {
                    return;
                }
                for (int i = 0; i < sizer; ++i) {
                    attron(COLOR_PAIR(1));
                    mvprintw(yr1 + i, xr1, " ");
                    mvprintw(yr2 + i, xr2, " ");
                    attroff(COLOR_PAIR(1));
                }
                mx_print_ascii_int(score1, numbers, 30, 5, stdscr);
                mx_print_ascii_int(score2, numbers, getmaxx(stdscr) - 30, 5, stdscr);
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
            }
            else if (direction_v == DOWN) {
                ++ball_y;
            }

            if (ball_y >= yr2 && ball_y <= yr2 + sizer - 1 && ball_x == xr2 && direction_h == RIGHT) {
                if (ball_y >= yr2 && ball_y <= yr2 + (sizer - 1) / 2 && direction_v == CENTER) {
                    direction_v = UP;
                } else if (ball_y >= yr2 + (sizer - 1) / 2 && ball_y <= yr2 + sizer - 1 && direction_v == CENTER) {
                    direction_v = DOWN;
                }
                direction_h = LEFT;
                printf("\a");
                --ball_x;
            }
            else if (ball_y >= yr1 && ball_y <= yr1 + sizer - 1 && ball_x == xr1 && direction_h == LEFT) {
                if (ball_y >= yr2 && ball_y <= yr2 + (sizer - 1) / 2 && direction_v == CENTER) {
                    direction_v = UP;
                } else if (ball_y >= yr2 + (sizer - 1) / 2 && ball_y <= yr2 + sizer - 1 && direction_v == CENTER) {
                    direction_v = DOWN;
                }
                direction_h = RIGHT;
                printf("\a");
                ++ball_x;
            }

            if (ball_y < 0 || ball_y >= getmaxy(stdscr)) {
                direction_v == DOWN ? (direction_v = UP) : (direction_v = DOWN);
            }

            if (ball_x > limit_right + 50) {
                mx_clear_int(score1, numbers, 30, 5, stdscr);
                ball_x = limit_left + 10;
                ball_y = getmaxy(stdscr) / 2;
                direction_h = RIGHT;
                direction_v = CENTER;
                ++score1;
                mx_print_ascii_int(score1, numbers, 30, 5, stdscr);
                if (score1 >= 5) {
                    erase();
                    refresh();
                    if (mx_small_menu(GAME_OVER, score1, score2)) {
                        endwin();
                        return;
                    } else {
                        score2 = 0;
                        score1 = 0;
                    }
                    for (int i = 0; i < sizer; ++i) {
                        attron(COLOR_PAIR(1));
                        mvprintw(yr1 + i, xr1, " ");
                        mvprintw(yr2 + i, xr2, " ");
                        attroff(COLOR_PAIR(1));
                    }
                    mx_print_ascii_int(score1, numbers, 30, 5, stdscr);
                    mx_print_ascii_int(score2, numbers, getmaxx(stdscr) - 30, 5, stdscr);
                }
            }
            else if (ball_x < limit_left - 50) {
                mx_clear_int(score2, numbers, getmaxx(stdscr) - 30, 5, stdscr);
                ball_x = limit_left + 10;
                ball_y = getmaxy(stdscr) / 2;
                direction_h = RIGHT;
                direction_v = CENTER;
                ++score2;
                mx_print_ascii_int(score2, numbers, getmaxx(stdscr) - 30, 5, stdscr);
                if (score2 >= 5) {
                    erase();
                    refresh();
                    if (mx_small_menu(GAME_OVER, score1, score2)) {
                        endwin();
                        return;
                    } else {
                        score2 = 0;
                        score1 = 0;
                    }
                    for (int i = 0; i < sizer; ++i) {
                        attron(COLOR_PAIR(1));
                        mvprintw(yr1 + i, xr1, " ");
                        mvprintw(yr2 + i, xr2, " ");
                        attroff(COLOR_PAIR(1));
                    }
                    mx_print_ascii_int(score1, numbers, 30, 5, stdscr);
                    mx_print_ascii_int(score2, numbers, getmaxx(stdscr) - 30, 5, stdscr);
                }
            }
            attron(COLOR_PAIR(1));
            mvprintw(ball_y, ball_x, "o");
            attroff(COLOR_PAIR(1));
        }
        refresh();
    }
    endwin();
}
