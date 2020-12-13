#include "minilibmx.h"

int mx_strcmp(const char *s1, const char *s2) {
    for (;*s1 != '\0' && *s2 != '\0' && *s1 == *s2; s1++, s2++);
    return *s1 == *s2 ? 0 : *s1 > *s2 ? 1 : -1;
}
