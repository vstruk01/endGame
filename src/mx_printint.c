#include "minilibmx.h"

static void printint_recursive(int n);

void mx_printint(int n) {
    if (n == 0)
        mx_printchar(n + 48);
    if (n < 0)
        mx_printchar('-');
    printint_recursive(n);
}

static void printint_recursive(int n) {
    if (n == 0)
        return;
    printint_recursive(n / 10);
    n > 0 ? mx_printchar(n % 10 + 48) : mx_printchar((n % 10) * -1 + 48);
}
