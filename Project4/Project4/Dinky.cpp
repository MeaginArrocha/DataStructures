#include "Dinky.h"

void Dinky::move(){
	if(state == 2)
		state = 4;
	if(state == 4){//special
		specVuln();
	}
	else{
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
}