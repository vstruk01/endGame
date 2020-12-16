#include "EndGame.h"
#define DELAY 3000000
int main() {
    initscr();
    start_color();
    enum e_direction direction_h = RIGHT;
    enum e_direction direction_v = CENTER;
    enum e_direction direction_r1 = NOT_MOVE;
    // enum e_direction direction_r2 = NOT_MOVE;

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
    timeout(100);
    wbkgd(stdscr, COLOR_PAIR(2));
    noecho();
    curs_set(FALSE);
    getmaxyx(stdscr, max_y, max_x);
    for (int i = 0; i < size_plat; ++i) {
        mvprintw(y_plat, x_plat + i, "-");
        attron(COLOR_PAIR(1));
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
        getmaxyx(stdscr, max_y, max_x);
        int color = 0;

        for (; y_kir > 10; y_kir = y_kir - 2, x_kir = 0) {
            for (;x_kir < max_x; x_kir++) {
                if (x_kir % 8) {
                    attron(COLOR_PAIR(color));
                    mvprintw(y_kir, x_kir, " ");
                    attroff(COLOR_PAIR(color));
                }  
                else {
                    color = rand() % 4 + 3;
                }
            }
        }
        mvwprintw(stdscr, ball_y, ball_x, " ");

            // direction_r2 == UP? (direction_v = UP) : (direction_v = DOWN);
            //     --ball_x;
            // direction_h == RIGHT ? ++ball_x : --ball_x;
            // if (direction_v == UP) {
            //     ++ball_y;
            // } 
            // else if (direction_v == DOWN) {
            //     --ball_y;
            // }
            if (ball_y >= y_kir && ball_y <= y_plat && ball_x == x_kir && direction_h == RIGHT) {
                direction_h = LEFT;
                direction_h == RIGHT ? ++ball_x : --ball_x;
            } else if (ball_y >= y_kir && ball_y <= y_plat && ball_x == x_plat && direction_h == LEFT) {
                direction_h = RIGHT;
                direction_r1 == UP ? (direction_v = UP) : (direction_v = DOWN);
                ++ball_x;
            }
            if (ball_x < 4 || ball_x >= getmaxx(stdscr) - 20) {
                direction_v == RIGHT ? (direction_v = LEFT) : (direction_v = RIGHT);
            }
            else if (ball_y > 0 || ball_y < y_plat) {
                // printf("%s","o");
                direction_v == DOWN ? (direction_v = UP) : (direction_v);
            }
            mvwprintw(stdscr, ball_y, ball_x, "o");
        refresh();
    }
    endwin();
}
