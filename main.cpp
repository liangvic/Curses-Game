#include <curses.h>
#include <stdlib.h>
#include "Dodger.h"

int main(){

WINDOW *wnd;
wnd = initscr();
cbreak();
noecho();
nonl();
// getmaxyx(wnd, nrows, ncols);
clear();
refresh();

Dodger Launcher;
Launcher.startGame();

endwin();
}

