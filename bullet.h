#ifndef BULLET_H
#define BULLET_H
#include <curses.h>
#include <stdlib.h>

class Bullet
{
	public:
		WINDOW *wnd;
		Bullet();
		~Bullet();
	private:
	int rmax, cmax;
	char shot;
	bool on;
	int r, c, speed;
	public:
	char getShot();
	void erase();
	void oneStep(); //moves bullet down 1 space
	void turnOff(); //turns off Bullet, making it invisible
	int getr();  //return row
	int getc();  //returns column
	void setc(int);
	void setr(int);
};

#endif
