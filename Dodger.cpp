#include <curses.h>
#include <stdlib.h>
#include <vector>

#include "hitbox.h"
#include "bullet.h"
#include "Dodger.h"
#include "display.h"

using namespace std;



//constructor for Dodger class
Dodger::Dodger()
{
//WINDOW *wnd;
vector<Bullet> bullets;
gameStarted = false;
score = 0;
wnd = initscr();
getmaxyx(wnd, nrows, ncols);
}	

Dodger::~Dodger()
{}

void Dodger::startGame(){
	char d = 'e';

	score = 0;		//setup game
	hitbox.setHP(3);
	clear();
	refresh();
	timeout(-1);	
	display.updateStats(hitbox.getHP(), score);
	display.printscreen();
	mvprintw(nrows/2+2, ncols/2, "Press any key to begin");

	d = getch(); 		//start when key entered
	clear();
	display.updateStats(hitbox.getHP(), score);
	display.printscreen();
	timeout(10);
	hitbox.oneStep('w');
	//display.printStart();
	int timer = 0;		//reset timer to 0
	double countdown = 10000;
	gameStarted = true;
	
	while (gameStarted)
	{
		if (hitbox.getHP() == 0)	//if lives reach 0, go to lose
		{ lose();
		  break;
		}

		if (countdown == 0)	//if lives reach 0, go to lose
		{ win();
		  break;
		}

		d = getch();			//get input
		if (d == 'q'){	
		break;
		}
	gameStarted = true;
		if (timer==10) // add points for surviving
			score++;
		
		if (timer == 10){
		oneMove();		//moves bullets and checks for collision
		timer = 0;		
		}
		if (timer ==2){		//add new bullets
			
			Bullet b;
			bullets.push_back(b);		

			}
		timer++;		//increase timer
		countdown--;
		
		checkCollisionBullets();	//checks for collision again
		hitbox.oneStep(d); 		//hitbox movement
		

		display.updateStats(hitbox.getHP(), score);
		display.printscreen();			
		
		move(0, 0);
		refresh();
	}
}

void Dodger::oneMove()
	{
	
	if(!checkCollisionBullets())
	{
  
		for (int i = 0; i<bullets.size(); i++)  //deletes bullets that have reached the end
		{  
			if (bullets[i].getr() == nrows)
			{
				move(hitbox.getr(), hitbox.getc());
				addch('H');
				Bullet c;
				c = bullets[bullets.size()-1];
				bullets[i]=c;
				bullets.pop_back();
			}
			checkCollisionBullets();
			bullets[i].oneStep();	//	bullet movement
		}	
	}
	refresh();
	
}
	
bool Dodger::checkCollisionBullets(){
	for (int i = 0; i <bullets.size(); i++)
		{
	 if (hitbox.getr() == bullets[i].getr() && hitbox.getc() == bullets[i].getc())
			{ 
		if (bullets[i].getShot() == 'V')
			hitbox.setHP(hitbox.getHP()-1);
		else
		if (bullets[i].getShot() == '+')
			hitbox.setHP(hitbox.getHP()+1);
		else
		if (bullets[i].getShot() == 'P')
			score+=50;
		
		
					Bullet c;
					c = bullets[bullets.size()-1];
					bullets[i]=c;
					bullets.pop_back();
		return true;
		}
		}
	return false;	
}

void Dodger::lose(){
	char key;
	clear();
	display.printLose();
	do{
	key = getch();
	if (key == 'r')
	{
		bullets.clear();
		gameStarted = true;
		startGame();
		break;
	}
	if (key == 'q')
		break;
	}
	while (1);
endwin();
}

void Dodger::win(){   //this case does not yet exist
	char key;
	clear();
	display.printWin();
	do{
	key = getch();
	if (key == 'r')
	{
		bullets.clear();
		gameStarted = true;
		startGame();
		break;
	}
	if (key == 'q')
		break;
	}
	while (1);
endwin();
}

