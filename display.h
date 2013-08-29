#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdlib.h>
#include <curses.h>


class Display{
	private: 
		int rows, cols, HP, score;
		char border;
		WINDOW *wnd;
	public:
		Display();
		~Display();
		void printscreen();
		void updateStats(int HP, int SCORE); //updates HP 
		void printDoubleBorder(int Y, int X);
		void printLose();
		void printWin();
		//void printStart();

};


#endif
