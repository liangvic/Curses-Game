#ifndef HITBOX_H
#define HITBOX_H

#include <curses.h>
#include <stdlib.h>
#include <vector>

class HitBox
{
//Data Members
private:
	WINDOW *wnd;
	int HP;
	int r, c, rmax, cmax;
	char icon;
//constructors
public: 
	HitBox();
	~HitBox();
//commands
public:
	void oneStep(char);
//getters and setters
	int getHP();
	void setHP(int);
	int getc();
	int getr();
	void setr(int);
	void setc(int);


};

#endif
