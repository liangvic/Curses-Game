#include <curses.h>
#include <stdlib.h>
#include "bullet.h"

Bullet::Bullet()
	{
	int setrole = rand()%100;
	if (setrole < 80)
		shot = 'V';	//80% chance of bullet
	if (setrole >= 80 && setrole < 95)
		shot = 'P';     //15% chance of points
	if (setrole >= 95)
		shot = '+'; 	//2% chance of extra life

	c = rand()%50 + 25 ;
	r = 1; 
	speed = rand()%1+1; //not yet implemented
	on = true;
	//wnd = initscr();
	move (r, c);
	addch(shot);
	}


Bullet::~Bullet()
{}
void Bullet::turnOff()  //"shuts off" bullet and makes it inactive
{ 	on = false;
	move(r, c);
	delch();
	move(0, 0);
	}

void Bullet::erase(){
	move(r, c); 
	delch();
	insch(' ');
}

char Bullet::getShot(){
	return shot;
}

void Bullet::oneStep()  //moves bullet 1 space if bullet is turned on
{

	getmaxyx(wnd, rmax, cmax);
if (on){
	erase();
	if (r == rmax)	//turns off bullet if it reaches the bottom of the display
		turnOff();
	else{
	r+=speed;
	move(r, c); 
	delch();
	insch(shot);
	}	
	}
}
	 
int Bullet::getr(){
return r;
}

int Bullet::getc(){
return c;
}

void Bullet::setc(int newc){
c = newc;
}

void Bullet::setr(int newr){
r = newr;
}

