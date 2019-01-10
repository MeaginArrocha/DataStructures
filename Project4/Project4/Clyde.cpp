#include "Clyde.h"

void Clyde::move(){
	if(state == 1){//normal
		if(LineOfSight()){
			randomNum = rand() % (4);
			if(randomNum > 0){
				randomDir = dirtemp;
				moves = 5;
				moveLine();
			}
			else{//randomNum == 0
				if(moves == 0)
					moveRandom();
				else
					moveLine();
			}
		}
		else{//!lineofsight()
			if(moves == 0)
				moveRandom();
			else
				moveLine();
		}
	}
	else
		moveRandom();
}		

