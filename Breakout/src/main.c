#include "EndGame.h"
#include <time.h>

#define DELAY 3000000

int main() {
    initscr();
    start_color();
    // enum e_direction direction_h = CENTER;

    enum e_direction direction_v = UP;

    unsigned long speed = 60000;
    clock_t start_t = clock();
    clock_t end_t = 0;

    init_pair(1, COLOR_WHITE, COLOR_WHITE);
    init_pair(2, COLOR_WHITE, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_RED);
    init_pair(4, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(5, COLOR_BLUE, COLOR_BLUE);
    init_pair(6, COLOR_GREEN, COLOR_GREEN);

    int x_plat = 10, y_plat = 30;
    int size_plat = 10;
    int x_kir = 0, y_kir = 15;
    int max_x = 0, max_y = 0;
    int ball_x = 12, ball_y = 25;

    cbreak();
    timeout(0);
    // wbkgd(stdscr, COLOR_PAIR(2));
    noecho();
    curs_set(FALSE);

    getmaxyx(stdscr, max_y, max_x);
    for (int i = 0; i < size_plat; ++i) {
        attron(COLOR_PAIR(1));
        mvprintw(y_plat, x_plat + i, "-");
        attroff(COLOR_PAIR(1));
    }

    int color = 0;
    int size_block = 8;
    getmaxyx(stdscr, max_y, max_x);
    for (; y_kir > 10; y_kir = y_kir - 2, x_kir = 0) {
        for (;x_kir < max_x; x_kir++) {
            if (x_kir % size_block) {
                // attron(COLOR_PAIR(color));
                mvprintw(y_kir, x_kir, "0");
                // attroff(COLOR_PAIR(color));
            } else {
                color = rand() % 4 + 3;
            }
        }
    }
    while (true) {
        switch (getch()) {
            case 68: //left
                if (x_plat - 1 >= 0) {
                    mvprintw(y_plat, x_plat + size_plat - 1, " ");
                    x_plat--;
                    attron(COLOR_PAIR(1));
                    mvprintw(y_plat, x_plat, " ");
                    attroff(COLOR_PAIR(1));
                }
                break;
            case 67: //right
                if (max_x >= x_plat + size_plat + 1) {
                    mvprintw(y_plat, x_plat, " ");
                    x_plat++;
                    attron(COLOR_PAIR(1));
                    mvprintw(y_plat, x_plat + size_plat - 1, " ");
                    attroff(COLOR_PAIR(1));
                }
                break;
        }
        mvwprintw(stdscr, ball_y, ball_x, " ");
        if (direction_v == UP && ball_y - 1 <= 0) {
            direction_v = DOWN;
        } else if (direction_v == DOWN && ball_y + 1 >= getmaxy(stdscr)) {
            exit(5);
        } else if (direction_v == DOWN && ball_y + 1 == y_plat
                   && ball_x >= x_plat && ball_x <= x_plat + size_plat) {
            direction_v = UP;
        }

        end_t = clock();
        if (end_t - start_t > speed) {
            start_t = end_t;
            direction_v == UP ? --ball_y : ++ball_y;
            if (mvinch(ball_y, ball_x) == '0') {
                for (int i = ball_x - ball_x % size_block + 1; mvinch(ball_y, i) == '0'; ++i)
                    mvprintw(ball_y, i, " ");
                direction_v = DOWN;
                ++ball_y;
            }
        }
        mvwprintw(stdscr, ball_y, ball_x, "o");
        refresh();
    }
    endwin();
}
