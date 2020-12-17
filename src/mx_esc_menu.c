#include "EndGame.h"

int mx_esc_menu(enum e_game game, int count1, int count2) {
    int max_y = 0, max_x = 0, c = 0;

    keypad(stdscr, TRUE);
    getmaxyx(stdscr, max_y, max_x);

    while (1) {
        mvprintw(max_y / 2 + 4, (max_x - strlen("PRESS 'e' TO EXIT")) / 2, "PRESS 'e' TO EXIT");
        if (count1 > count2 && game == GAME_OVER) {
            mvprintw(max_y / 2, (max_x / 2) - (mx_strlen("PLAYER 1 HAS WON!") / 2), "PLAYER 1 HAS WON!");
            mvprintw(max_y / 2 + 2, (max_x - mx_strlen("PRESS 'r' TO RESTART")) / 2, "PRESS 'r' TO RESTART");
        } else if (count1 < count2 && game == GAME_OVER) {
            mvprintw(max_y / 2, (max_x - mx_strlen("PLAYER 2 HAS WON!")) / 2, "PLAYER 2 HAS WON!");
            mvprintw(max_y / 2 + 2, (max_x - mx_strlen("PRESS 'r' TO RESTART")) / 2, "PRESS 'r' TO RESTART");
        } else if (game == PAUSE) {
            mvprintw(max_y / 2, (max_x - mx_strlen("PAUSE")) / 2, "PAUSE");
            mvprintw(max_y / 2 + 2, (max_x - mx_strlen("PRESS 'c' TO CONTINUE")) / 2, "PRESS 'c' TO CONTINUE");
        }
        c = getch();
        if (c == 'r' || c == 'c') {
            clear();
            refresh();
            return 0;
        }
        if (c == 'e') {
            clear();
            refresh();
            return 1;
        }
    }
}

