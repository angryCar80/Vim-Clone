#include <ncurses.h>
#include <string>
#include <filesystem>
#include <fstream>
#include <iostream>

int main() {
  std::string mode = "NORMAL";
  initscr();
  raw();
  keypad(stdscr, TRUE);
  noecho();
  curs_set(0);

  printw("-- {mode} --\n");
  printw("ESC to exit\nUse hjkl to move the @ symbol.");
  refresh();

  int x = 0, y = 3;
  int maxy, maxx;
  int ch;

  while ((ch = getch()) != 27) {
    getmaxyx(stdscr, maxy, maxx);

    switch (ch) {
      case 'h':
        if (x > 0) x--;
        break;
      case 'l':
        if (x < maxx - 1) x++;
        break;
      case 'j':
        if (y < maxy - 1) y++;
        break;
      case 'k':
        if (y > 1) y--;
        break;
    }

    clear();
    mvprintw(0, 0, "Use hjkl to move, ESC to exit");
    mvprintw(y, x, "*");
    refresh();
  }

  endwin();
  return 0;
}
