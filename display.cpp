#include <stdlib.h>
#include <curses.h>
#include "display.h"

using namespace std;
Display::Display()
{
//WINDOW *wnd;
border = '*';
score = 0;
wnd = initscr();
	getmaxyx(wnd, rows, cols);
}

Display::~Display()
{}

/*
void Display::printStart(){
	clear();
	refresh();
	timeout(-1);	
	display.updateStats(hitbox.getHP(), score);
	display.printscreen();
	mvprintw(nrows/2+2, ncols/2, "Press any key to begin");
	d = getch();
	clear();
	display.updateStats(hitbox.getHP(), score);
	display.printscreen();
	timeout(30);
	hitbox.oneStep('w');
*/

void Display::printLose(){

	move(rows/2 - 2, cols/2-4);
	printw("You lose!");
	move(rows/2 , cols/2-6);
	printw("Final Score: %d", score);
	move(rows/2 + 3 , cols/2-8);
	printw("Press 'q' to quit");
	move(rows/2 + 4 , cols/2-9);
	printw("Press 'r' to restart");
	move(0, 0);
}
	

void Display::printWin(){

	move(rows/2 - 2, cols/2-4);
	printw("You Win!");
	move(rows/2 , cols/2-6);
	printw("Final Score: %d", score);
	move(rows/2 + 3 , cols/2-8);
	printw("Press 'q' to quit");
	move(rows/2 + 4 , cols/2-9);
	printw("Press 'r' to restart");
	move(0, 0);
}


void Display::printscreen(){ //prints the screen
	/*wnd = initscr();
	getmaxyx(wnd, rows, cols); */

	int r=0;
	move(0, 0);
	printw("********************************* Dodgetheshit **********************************");
	printw("*********************************************************************************");
	move(2, 2);
	printw("  Dodge the arrows ");
	move(3, 2);
	printw(" and get to the end ");
	move(4, 2);
	printw("********************");
	move(5, 2);
	printw("********************");
	move(6, 2);
	printw("    Score: %d", score);
	move(7, 2);
	printw("    HP: %d", HP);
	move(9, 2);
	printw("  'P' -> +50 points");
	move(10, 2);
	printw("  '+' -> +1 HP");
	move(11, 2);
	printw("  'V' -> -1 HP");
	

	move(13, 2);
	printw("********************");
	move(14, 2);
	printw("********************");
	move(15, 2);
	printw(" Controls: 'w' = up");
	move(16, 2);
	printw("        'a' = left");
	move(17, 2);
	printw("        's' = down");
	move(18, 2);
	printw("        'd' = right");
	move(20, 2);
	printw(" 'q' to quit");
	move(21, 2);
	printw(" 'Ctrl+s' to pause");

	move (rows-1,0);
	printw("*********************************************************************************");
	

	for(int i = 0; i < rows; i++)
		printDoubleBorder(i, 22);
	
	for(int i = 0; i < rows; i++)
		printDoubleBorder(i, 0);

	for(int i = 0; i < rows; i++)
		printDoubleBorder(i, cols-2);

refresh();

}

void Display::printDoubleBorder(int r, int c){  //prints a vertical border
	move (r, c);
	printw("**");
}

void Display::updateStats(int H, int S){  //changes stats of class 
HP = H; 
score = S;
}

