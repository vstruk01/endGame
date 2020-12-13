#include "minilibmx.h"

char *mx_strcpy(char *dst, const char *str) {
    int i = 0;
    
    for (;str[i]; dst[i] = str[i], ++i);
    dst[i] = '\0';
    return dst;
}
