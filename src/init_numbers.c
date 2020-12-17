#include "EndGame.h"

char ***mx_init_numbers() {
    char ***numbers = NULL;
    char buff[100];
    char *error = NULL;
    int height = 0;

    FILE *file = fopen("resource/numbers", "rb");
    error = fgets(buff, '\n', file);
    height = mx_atoi(buff);
    if (error == NULL) {
        return NULL;
    }

    numbers = malloc(sizeof(char*) * 11);
    numbers[10] = NULL;
    for (int i = 0; i < 10; ++i) {
        numbers[i] = malloc(sizeof(char*) * (height + 1));
        for (int j = 0; j < height; ++j){
            char buff1[10];
            fgets(buff1, '\n', file);
            numbers[i][j] = mx_strdup(buff1);
        }
        numbers[i][height] = NULL;
        printf("\n");
    }
    return numbers;
}

