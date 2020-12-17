#include "EndGame.h"

#define SLEEP 40000
#define SLEEP1 800000

void mx_print_picture(void) {
    FILE *file;
    initscr();
    curs_set(FALSE);

    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_CYAN, COLOR_BLACK);

    int size = 201;
    char *str = malloc(size);
    char *str1 = malloc(size);
    char *str2 = malloc(size);
    char *str3 = malloc(size);
    char *str4 = malloc(size);

    int y = 1;

    file = fopen("resource/achaur1.txt", "rb");

    while (fread(str, sizeof(char), 111, file)) {
        attrset(COLOR_PAIR(2));
        mvprintw(y + 30, 120, "%s", str);
        y++;
        usleep(SLEEP);
        refresh();
    }
    usleep(SLEEP1);
    fclose(file);
    clear();

    file = fopen("resource/achaur.txt", "rb");

    y = 1;
    while (fread(str, sizeof(char), size, file)) {
        attrset(COLOR_PAIR(2));
        mvprintw(y, 80, "%s", str);
        y++;
        usleep(SLEEP);
        refresh();
    }
    usleep(SLEEP1);
    fclose(file);
    clear();


    file = fopen("resource/vstruk1.txt", "rb");
    
    y = 1;
    while (fread(str1, sizeof(char), 120, file)) {
        attrset(COLOR_PAIR(1));
        mvprintw(y + 30, 110, "%s", str1);
        y++;
        usleep(SLEEP);
        refresh();
   }
    usleep(SLEEP1);
    fclose(file);
    clear();


    file = fopen("resource/vstruk.txt", "rb");
    
    y = 1;
    while (fread(str1, sizeof(char), size, file)) {
        attrset(COLOR_PAIR(1));
        mvprintw(y, 80, "%s", str1);
        y++;
        usleep(SLEEP);
        refresh();
   }
    usleep(SLEEP1);
    fclose(file);
    clear();

    file = fopen("resource/vshedenko1.txt", "rb");

    y = 1;
    while (fread(str2, sizeof(char), 172, file)) {
        attrset(COLOR_PAIR(3));
        mvprintw(y + 30, 90, "%s", str2);
        y++;
        usleep(SLEEP);
        refresh();
   }
    usleep(SLEEP1);
    fclose(file);
    clear();

    file = fopen("resource/vshedenko.txt", "rb");

    y = 1;
    while (fread(str2, sizeof(char), size, file)) {
        attrset(COLOR_PAIR(3));
        mvprintw(y, 80, "%s", str2);
        y++;
        usleep(SLEEP);
        refresh();
   }
    usleep(SLEEP1);
    fclose(file);
    clear();

    file = fopen("resource/mkvytkovsk1.txt", "rb");

    y = 1;
    while (fread(str3, sizeof(char), 208, file)) {
        attrset(COLOR_PAIR(4));
        mvprintw(y + 30, 75, "%s", str3);
        y++;
        usleep(SLEEP);
        refresh();
   }
    usleep(SLEEP1);
    fclose(file);
    clear();

    file = fopen("resource/mkvytkovsk.txt", "rb");

    y = 1;
    while (fread(str3, sizeof(char), size, file)) {
        attrset(COLOR_PAIR(4));
        mvprintw(y, 80, "%s", str3);
        y++;
        usleep(SLEEP);
        refresh();
   }
    usleep(SLEEP1);
    fclose(file);
    clear();

    file = fopen("resource/vbohaichuk1.txt", "rb");

    y = 1;
    while (fread(str4, sizeof(char), 183, file)) {
        attrset(COLOR_PAIR(5));
        mvprintw(y + 30, 80, "%s", str4);
        y++;
        usleep(SLEEP);
        refresh();
   }
    usleep(SLEEP1);
    fclose(file);
    clear();

    file = fopen("resource/vbohaichuk.txt", "rb");
    y = 1;
    while (fread(str4, sizeof(char), size, file)) {
        attrset(COLOR_PAIR(5));
        mvprintw(y, 80, "%s", str4);
        y++;
        usleep(SLEEP);
        refresh();
   }
    usleep(SLEEP1);
    fclose(file);
    clear();

    free(str);
    refresh();
    endwin();
}
