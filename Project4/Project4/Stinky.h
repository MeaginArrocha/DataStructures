#include "Monster.h"

#ifndef STINKY_H
#define STINKY_H

class Stinky:public Monster{
public:
	Stinky(int x, int y, Maze * m, CConsole * c, Player * p):Monster(x, y, m, c, p){
		display = 'S';
		foreColor = purple;
		moves = 0;
	}

	void move();

};

#endif