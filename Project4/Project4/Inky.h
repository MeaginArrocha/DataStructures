#include "Monster.h"

#ifndef INKY_H
#define INKY_H

class Inky:public Monster{
public:
	Inky(int x, int y,Maze * m, CConsole * c):Monster(x, y, m, c){
		display = 'I';
		foreColor = brown;
	}	

	//passed down from Monster
	void move();
	//will use the ICVulnMove because he uses random for normal and vulnerable


};

#endif