#ifndef DODGER_H
#define DODGER_H
#include <curses.h>
#include <stdlib.h>
#include <vector>
#include "hitbox.h"
#include "bullet.h"
#include "display.h"

using namespace std;

class Dodger{
//DataMembers
private:
	WINDOW *wnd;
	vector<Bullet> bullets;
	HitBox hitbox;
	Display display;

	bool gameStarted;
	int nrows, ncols;
	int score;

//constructors
public:
 	Dodger();
	~Dodger();
//commands
public:
	void startGame();
	void oneMove();
	bool checkCollisionBullets();
	void lose();
	void win();
	};

#endif

