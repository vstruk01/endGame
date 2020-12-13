#include "minilibmx.h"

int mx_atoi(const char *str) {
    unsigned long long int result = 0;
    int pos = 0;
    int sign = 1;

    for (; mx_isspace(str[pos]); ++pos);
    if ((str[pos] == '+' || (str[pos] == '-' && (sign = -1))) && ++pos) {}
    for (; mx_isdigit(str[pos]); ++pos)
        result = result * 10 + str[pos] - 48;
    return result * sign;
}
