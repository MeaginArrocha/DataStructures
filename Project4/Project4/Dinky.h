#include "Monster.h"

#ifndef DINKY_H
#define DINKY_H

class Dinky:public Monster{
public:
	Dinky(int x, int y, Maze * m, CConsole * c, Player * p):Monster(x, y, m, c, p){
		display = 'D';
		foreColor = red;
		moves = 0;
	}

	void move();

};

#endif