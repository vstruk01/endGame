#include "EndGame.h"

static void clear_recursive(int n, char ***numbers, int *x, int y, WINDOW *win);

void mx_clear_int(int n, char ***numbers, int x, int y, WINDOW *win) {
    if (n == 0) {
        for (int i = 0; numbers[n % 10][i]; ++i, ++y) {
            for (int j = 0; numbers[n % 10][i][j]; ++j) {
                mvwprintw(win, y, x + j, " ");
            }
        }
        return;
    }
    if (n < 0)
        return;
    clear_recursive(n, numbers, &x, y, win);
}

static void clear_recursive(int n, char ***numbers, int *x, int y, WINDOW *win) {
    if (n == 0)
        return;
    clear_recursive(n / 10, numbers, x, y, win);
    for (int i = 0; numbers[n % 10][i]; ++i, ++y) {
        for (int j = 0; numbers[n % 10][i][j]; ++j) {
            mvwprintw(win, y, *x + j, " ");
        }
    }
    *x += mx_strlen(numbers[n % 10][0]);
}
