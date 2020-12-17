#include "EndGame.h"

void mx_clear_menu(t_menu **menu) {
    for (int i = 0; i < (*menu)->s_main_m; ++i) {
        mx_strdel(&(*menu)->main_m[i]);
    }
    for (int i = 0; i < (*menu)->s_game_m; ++i) {
        mx_strdel(&(*menu)->game_m[i]);
    }
    free((*menu)->game_m);
    free((*menu)->main_m);
    free(*menu);
    *menu = NULL;
}
