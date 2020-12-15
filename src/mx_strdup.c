char *mx_strnew(const int size);
int mx_strlen(const char *s);
void mx_strcpy(char *dst, char *str);

char *mx_strdup(const char *s) {
    char *strdup = mx_strnew(mx_strlen(s));

    mx_strcpy(strdup, (char*)s);
    return strdup;
}

// #include <stdio.h>
// #include <stdlib.h>

// int main(void) {
//     char *s1 = mx_strdup("Hello");
//     char *s2 = mx_strdup("World!");
//     printf("%s\n%s\n", s1, s2);
// }

