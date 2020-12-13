#include "minilibmx.h"

int mx_strlen(const char *s) {
    for (const char *s_copy = s; s ; s_copy++)
        if (!*s_copy)
            return s_copy - s;
    return 0;
}
