int mx_strlen(const char *s);

#include <ncurses.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
int max_y = 0, max_x = 0, c = 0;

 initscr();
 noecho();
 curs_set(FALSE);
 keypad(stdscr, TRUE);
 getmaxyx(stdscr, max_y, max_x);
 
 while(1) {
  clear();
  mvprintw(max_y - 2, max_x - mx_strlen("Press 'r' to restart") - 2, "Press 'r' to restart");
  mvprintw(max_y - 2, 2, "Press 'e' to exit");
  refresh();
  // if (count1 > count2) {
  //  mvprintw(max_y / 2, (max_x / 2) - (mx_strlen("Player 1 wins!") / 2), "Player 1 wins!");
  //  else mvprintw(max_y - 2, max_x - mx_strlen("Player 2 wins!") - 2, "Player 2 wins!");
  // }
  
  c = wgetch(stdscr);
  if (c == 'r') break;
  if (c == 'e') break;
 }
 endwin();
}
