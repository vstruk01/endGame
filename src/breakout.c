#include "EndGame.h"

static void mx_del_block(WINDOW *win, int y, int x, int k_start, int size_block) {
    for (int i = x - (x - k_start) % (size_block + 1); size_block >= 0; ++i) {
        mvwprintw(win, y, i, " ");
        --size_block;
    }
}

void mx_breakout(enum e_lvl lvl) {
    lvl = NORMAL;
    keypad(stdscr, TRUE);

    enum e_direction direction_h = CENTER;
    enum e_direction direction_v = UP;

    unsigned long speed = 20000;
    clock_t start_t = clock();
    clock_t end_t = 0;

    init_pair(1, COLOR_WHITE, COLOR_WHITE);
    init_pair(2, COLOR_WHITE, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_RED);
    init_pair(4, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(5, COLOR_BLUE, COLOR_BLUE);
    init_pair(6, COLOR_GREEN, COLOR_GREEN);

    int x_plat = 10, y_plat = getmaxy(stdscr) - 5;
    int size_plat = 30;
    int max_x = 0, max_y = 0;
    int ball_x = 12, ball_y = y_plat - 10;
    int object = 0;
    int color = 0;
    int size_block = 8;

    getmaxyx(stdscr, max_y, max_x);
    for (int i = 0; i < size_plat; ++i) {
        attron(COLOR_PAIR(1));
        mvprintw(y_plat, x_plat + i, "-");
        attroff(COLOR_PAIR(1));
    }
    int k_start = 1 + (max_x - 2) % (size_block + 1) / 2;

    for (int y_kir = max_y / 5; y_kir > 6; y_kir -= 2) {
        for (int x_kir = k_start; x_kir < max_x - 1 - k_start; ++x_kir) {
            color = rand() % 4 + 3;
            attron(COLOR_PAIR(color));
            for (int i = 0; i < size_block; ++x_kir, ++i)
                mvprintw(y_kir, x_kir, "0");
            attroff(COLOR_PAIR(color));
            // refresh();
        }
    }
    refresh();
    box(stdscr, 0, 0);

    int ch = 0;
    while (true) {
        switch (getch()) {      //    0000
            case KEY_LEFT:            //left 0000
                for (int i = 0; x_plat != 1 && i < 4; ++i) {
                    mvprintw(y_plat, x_plat-- + size_plat - 1, " ");
                    attron(COLOR_PAIR(1));
                    mvprintw(y_plat, x_plat, "-");
                    attroff(COLOR_PAIR(1));
                }
                break;
            case KEY_RIGHT: //right
                for (int i = 0; x_plat + size_plat != max_x - 1 && i < 4; ++i) {
                    mvprintw(y_plat, x_plat, " ");
                    attron(COLOR_PAIR(1));
                    mvprintw(y_plat, x_plat++ + size_plat, "-");
                    attroff(COLOR_PAIR(1));
                }
                break;
            case 27:
                while (true) {
                    ch = getch();
                    mvprintw(max_y / 2 + 4, (max_x - strlen("PRESS 'e' TO EXIT")) / 2, "PRESS 'e' TO EXIT");
                    mvprintw(max_y / 2, (max_x - mx_strlen("PAUSE")) / 2, "PAUSE");
                    mvprintw(max_y / 2 + 2, (max_x - mx_strlen("PRESS 'c' TO CONTINUE")) / 2, "PRESS 'c' TO CONTINUE");
                    if (ch == 'e') {
                        clear();
                        refresh();
                        return;
                    } else if (ch == 'c') {
                        mvprintw(max_y / 2 + 4, (max_x - strlen("                            ")) / 2, "                            ");
                        mvprintw(max_y / 2, (max_x - mx_strlen("                            ")) / 2, "                            ");
                        mvprintw(max_y / 2 + 2, (max_x - mx_strlen("                            ")) / 2, "                            ");
                        ch = 0;
                        break;
                    }
                }
                break;
        }
        mvwprintw(stdscr, ball_y, ball_x, " ");

        end_t = clock();
        if (end_t - start_t > speed) {
            start_t = end_t;
            // ? direction vertical LEFT RIGHT
            if (direction_h == LEFT) {
                // * direction LEFT
                if ((mvinch(ball_y, ball_x - 1) & A_CHARTEXT) != ' ') {
                    direction_h = RIGHT;
                    if ((mvinch(ball_y, ball_x - 1) & A_CHARTEXT) == '0') {
                        mx_del_block(stdscr, ball_y, ball_x - 1, k_start, size_block);
                    }
                } else if ( direction_v == UP && (mvinch(ball_y - 1, ball_x - 1) & A_CHARTEXT) != ' ') {
                    direction_v = DOWN;
                    if ((mvinch(ball_y - 1, ball_x - 1) & A_CHARTEXT) == '0') {
                        mx_del_block(stdscr, ball_y - 1, ball_x - 1, k_start, size_block);
                    }
                } else if ( direction_v == DOWN && (mvinch(ball_y + 1, ball_x - 1) & A_CHARTEXT) != ' ') {
                    direction_v = UP;
                    if ((mvinch(ball_y + 1, ball_x - 1) & A_CHARTEXT) == '0') {
                        mx_del_block(stdscr, ball_y + 1, ball_x - 1, k_start, size_block);
                    }
                }
            } else if (direction_h == RIGHT) {
                // * direction RIGHT
                if ((mvinch(ball_y, ball_x + 1) & A_CHARTEXT) != ' ') {
                    direction_h = LEFT;
                    if ((mvinch(ball_y, ball_x + 1) & A_CHARTEXT) == '0') {
                        mx_del_block(stdscr, ball_y, ball_x + 1, k_start, size_block);
                    }
                } else if ( direction_v == UP && (mvinch(ball_y - 1, ball_x + 1) & A_CHARTEXT) != ' ') {
                    direction_v = DOWN;
                    if ((mvinch(ball_y - 1, ball_x + 1) & A_CHARTEXT) == '0') {
                        mx_del_block(stdscr, ball_y - 1, ball_x + 1, k_start, size_block);
                    }
                } else if ( direction_v == DOWN && (mvinch(ball_y + 1, ball_x + 1) & A_CHARTEXT) != ' ') {
                    direction_v = UP;
                    if ((mvinch(ball_y + 1, ball_x + 1) & A_CHARTEXT) == '0') {
                        mx_del_block(stdscr, ball_y + 1, ball_x + 1, k_start, size_block);
                    }
                }
            }


            // ? direction vertical UP DOWN
            if (direction_v == UP) {
                // * direction UP
                if ((mvinch(ball_y - 1, ball_x) & A_CHARTEXT) != ' ') {
                    direction_v = DOWN;
                    if ((mvinch(ball_y - 1, ball_x) & A_CHARTEXT) == '0') {
                        mx_del_block(stdscr, ball_y - 1, ball_x, k_start, size_block);
                    }
                }
            } else if (direction_v == DOWN) {
                object = (mvinch(ball_y + 1, ball_x) & A_CHARTEXT);
                // * direction DOWN
                if (object != ' ') {
                    direction_v = UP;
                    if (object == '0') {
                        mx_del_block(stdscr, ball_y + 1, ball_x, k_start, size_block);
                    } else if (object == '-' && direction_h == CENTER) {
                        if (ball_x >= x_plat && ball_x <= x_plat + size_plat / 2) {
                            direction_h = LEFT;
                        } else if (ball_x >= x_plat + size_plat / 2 && ball_x <= x_plat + size_plat) {
                            direction_h = RIGHT;
                        }
                    }
                }
            }
            if (direction_h != CENTER)
                direction_h == LEFT ? --ball_x : ++ball_x;
            if (direction_v != CENTER)
                direction_v == UP ? --ball_y : ++ball_y;
        }
        mvwprintw(stdscr, ball_y, ball_x, "0");
        refresh();
    }
}

