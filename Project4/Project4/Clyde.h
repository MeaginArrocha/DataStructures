#include "Monster.h"

#ifndef CLYDE_H
#define CLYDE_H

class Clyde:public Monster{
public:
	Clyde(int x, int y, Maze * m, CConsole * c, Player * p):Monster(x, y, m, c, p){
		display = 'C';
		foreColor = blue;
		moves = 0;
	}
	
	void move();

};

#endif