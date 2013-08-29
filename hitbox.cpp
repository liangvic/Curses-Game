#include <curses.h>
#include <stdlib.h>
#include "hitbox.h"

HitBox::HitBox() //constructors and deconstructors
	{HP = 3;
	c = 50;
	r = 20;
	icon = 'H';
	WINDOW *wnd;
	move(r, c);
	insch(icon);
}

HitBox::~HitBox()
{
}

//move character 1 space
	void HitBox::oneStep(char dir){
	wnd = initscr();
	getmaxyx(wnd, rmax, cmax);		
	if (dir == -1)
			return;

	move(r, c);
	delch();
	insch(' ');
	switch(dir)
	{
	case 'd':
		c++;
		break;
	case 's':
		r++;
		break;
	case 'a':
		 c--;
		break;
	case 'w':
		r--;
		break;
	default:
		break;//does nothing if no input
	}

	if (c < 25)
		c = 25;
	if (c == cmax-2)
		c = cmax-3;
	if (r < 3)
		r = 3;
	if (r == rmax-1)
		r = rmax-2;

	move(r, c);
	addch(icon);
}
	
//getters
	int HitBox::getHP()
	{ return HP;}
	int HitBox::getr()
	{ return r;}
	int HitBox::getc()
	{ return c;}
//setters
	void HitBox::setHP(int h)
	{ HP = h;}
	void HitBox::setr(int x)
	{r = x;}
	void HitBox::setc(int y)
	{c = y;}

	
	
