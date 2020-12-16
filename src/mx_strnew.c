#include <stdlib.h>

char *mx_strnew(const int size) {
    char *strnew = malloc(size < 0 ? size : size + 1);
    
    for (int i = 0; strnew && i <= size; ++i)
        strnew[i] = '\0';
    return strnew;
}

// #include <stdio.h>

// int main(void) {
//     printf("%s\n", mx_strnew(10));
//     printf("%s\n", mx_strnew(1));
//     printf("%s\n", mx_strnew(0));
//     printf("%s\n", mx_strnew(123));
// }

