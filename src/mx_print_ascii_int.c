#include "EndGame.h"

static void printint_recursive(int n, char ***numbers, int *x, int y, WINDOW *win);

void mx_print_ascii_int(int n, char ***numbers, int x, int y, WINDOW *win) {
    if (n == 0) {
        for (int i = 0; numbers[n % 10][i]; ++i, ++y) {
            for (int j = 0; numbers[n % 10][i][j] && numbers[n % 10][i][j] != '\n'; ++j) {
                mvwprintw(win, y, x + j, "%c", numbers[n % 10][i][j]);
            }
        }
        return;
    }
    if (n < 0)
        return;
    printint_recursive(n, numbers, &x, y, win);
}

static void printint_recursive(int n, char ***numbers, int *x, int y, WINDOW *win) {
    if (n == 0)
        return;
    printint_recursive(n / 10, numbers, x, y, win);
    for (int i = 0; numbers[n % 10][i]; ++i, ++y) {
        for (int j = 0; numbers[n % 10][i][j] && numbers[n % 10][i][j] != '\n'; ++j) {
            mvwprintw(win, y, *x + j, "%c", numbers[n % 10][i][j]);
        }
    }
    *x += mx_strlen(numbers[n % 10][0]);
}
