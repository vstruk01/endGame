#include "EndGame.h"

t_menu *mx_init_menu() {
    t_menu *menu = malloc(sizeof(t_menu));

    menu->help_phrase = "Use arrow keys to go up and down, Press enter to select a choice";
    menu->s_help_phrase = strlen(menu->help_phrase);

    menu->startx = (getmaxx(stdscr) - WIDTH) / 2;
    menu->starty = (getmaxy(stdscr) - HEIGHT) / 2;
    menu->s_game_m = 6;
    menu->s_main_m = 5;

    // * init main menu
    menu->main_m = malloc(sizeof(char *) * menu->s_main_m);
    menu->main_m[0] = mx_strdup("Ping  Pong");
    menu->main_m[1] = mx_strdup("Breakout");
    menu->main_m[2] = mx_strdup("Spase Invaders");
    menu->main_m[3] = mx_strdup("EXIT");
    menu->main_m[4] = NULL;

    // * init game menu
    menu->game_m = malloc(sizeof(char *) * menu->s_game_m);
    menu->game_m[0] = mx_strdup("EASY");
    menu->game_m[1] = mx_strdup("NORMAL");
    menu->game_m[2] = mx_strdup("HARD");
    menu->game_m[3] = mx_strdup("SETTINGS");
    menu->game_m[4] = mx_strdup("BACK");
    menu->game_m[5] = NULL;

    return menu;
}
