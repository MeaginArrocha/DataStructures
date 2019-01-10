#include "Stinky.h"

void Stinky::move(){
	if(state == 1)//normal
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
	else{//vulnerable
		if(LineOfSight()){
			randomNum = rand() % (4);
			if(randomNum > 0){
				if(dirtemp == 5)
					randomDir =6;
				else if(dirtemp == 6)
					randomDir =5;
				if(dirtemp == 7)
					randomDir = 8;
				else if(dirtemp == 8)
					randomDir = 7;
				moves = 5;
				moveLine();
			}
			else{//randomNum == 0
				if(moves == 0 && differentDirection == false)
					moveRandom();
				else if(moves == 0 && differentDirection == true){
					changeDir();
					if(direction == 'Y')
						if(randomDir == 7 || randomDir == 8)
							moveLine();
					else if(direction == 'X')
						if(randomDir == 5 ||randomDir == 6)
							moveLine();
					else
						changeDir();

				}
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