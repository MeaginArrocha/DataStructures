#include "Monster.h"
#include "Actor.h"
#include "Maze.h"


char Monster::getDisplayChar(){
	return display;
}

void Monster::setNormal(){
	state = 1;
	backColor = black;
	console -> setColor(foreColor, backColor);	
	display = toupper(display);
	

}

void Monster::setVulnerable(int level){
	state = 2;
	backColor = green;
	console -> setColor(foreColor, backColor);
	display = tolower(display);

	if(level <= 8)
		numOfTicks  = 100 - level * 10;
	else
		numOfTicks = 20;
}

int Monster::getState(){
	return state;
}

void Monster::decreaseTicks(){
	numOfTicks--;
	if(numOfTicks == 0)
		setNormal();
}

void Monster::changeDir(){
	possibleMoves = 0;
	if(maze -> getMazeValue(X, Y - 1) != '#'){//checks if wall is in the way
		directionArray[possibleMoves] = 5;//adds it to array if okay to move there
		possibleMoves++;//increments possible moves - used later for %
	}
	if(maze -> getMazeValue(X, Y + 1) != '#'){
		directionArray[possibleMoves] = 6;
		possibleMoves++;
	}
	if(maze -> getMazeValue(X - 1, Y) != '#'){
		directionArray[possibleMoves] = 7;
		possibleMoves++;
	}
	if(maze -> getMazeValue(X + 1, Y) != '#'){
		directionArray[possibleMoves] = 8;
		possibleMoves++;
	}	
	//now only get a random number from the possible moves in the array
	randomDir = rand() % (possibleMoves) ; //random direction 5-8
	//up = 5 down = 6 left = 7 right = 8	
	randomDir = directionArray[randomDir];
	randomSpots = 1 + rand() % (4);
	//random number 1 - 4
}

void Monster::moveRandom(){
	if(state == 2)//monster is vulnerable
		decreaseTicks();

	if(randomSpots == 0)//done with one way so
		changeDir();//change direction

	if(randomDir == 5 && maze -> getMazeValue(X, Y - 1) == '#')//if up and not a wall
		changeDir();//change direction
	else if(randomDir == 6 && maze -> getMazeValue(X, Y + 1) == '#')
		changeDir();
	else if(randomDir == 7 && maze -> getMazeValue(X - 1, Y) == '#')
		changeDir();
	else if(randomDir == 8 && maze -> getMazeValue(X + 1, Y) == '#')
		changeDir();


	if(randomDir == 5){//if its up
		Changes();//makes the color and randomSpots changes
		actorChanges('Y', Y - 1);//make the changes in actor passing up coord
		randomSpots--;
	}
	else if(randomDir == 6){
		Changes();
		actorChanges('Y', Y + 1);
		randomSpots--;
	}
	else if(randomDir == 7 ){
		Changes();
		actorChanges('X', X - 1);
		randomSpots--;
	}
	else if(randomDir == 8){
		Changes();
		actorChanges('X', X + 1);
		randomSpots--;
	}

}

void Monster::Changes(){
	console -> setColor(white, black);
	console -> printChar(X, Y, maze ->getMazeValue(X, Y));
}

bool Monster::LineOfSight(){
	xtemp = X;//column
	ytemp = Y;//row
	

	if(player -> getX() == xtemp){//same column
		if(player -> getY() > ytemp){//below
			while(maze -> getMazeValue(xtemp, ytemp) != '#' && ytemp != player -> getY())
				ytemp++;
			if(maze -> getMazeValue(xtemp, ytemp) == '#')
				return false;
			direction = 'Y';
			dirtemp = 6;
			return true;
		}
		if(player -> getY() < ytemp){//above
			while(maze -> getMazeValue(xtemp, ytemp) != '#' && ytemp != player -> getY())
				ytemp--;
			if(maze -> getMazeValue(xtemp, ytemp) == '#')
				return false;
			direction = 'Y';//used later for movement in moveLine()
			dirtemp = 5;//sets direction so the monster can chase GacMan
			return true;
		}
	}
	if(player ->getY() == ytemp){//same row
		if(player -> getX() > xtemp){//right
			while(maze -> getMazeValue(xtemp, ytemp) != '#' && xtemp !=  player -> getX())
				xtemp++;
			if(maze -> getMazeValue(xtemp, ytemp) == '#')
				return false;
			direction = 'X';
			dirtemp = 8;
			return true;
		}
		if(player -> getX() < xtemp){//left
			while(maze -> getMazeValue(xtemp, ytemp) != '#' && xtemp != player-> getX())
				xtemp--;
			if(maze -> getMazeValue(xtemp, ytemp) == '#')
				return false;
			direction = 'X';
			dirtemp = 7;
			return true;
		}
	}

	return false;//not in line of sight
}

void Monster::moveLine(){
	if(randomDir == 5 && maze -> getMazeValue(X, Y - 1) != '#'){
		Changes();
		actorChanges(direction, Y - 1);
		moves--;
		differentDirection = false;
	}
	else if(randomDir == 5 && maze -> getMazeValue(X, Y - 1) == '#'){
		moves = 0;
		differentDirection = true;
	}

	if(randomDir == 6 && maze -> getMazeValue(X, Y + 1) != '#'){
		Changes();
		actorChanges(direction, Y + 1);
		moves--;
		differentDirection = false;
	}
	else if(randomDir == 6 && maze -> getMazeValue(X, Y + 1) == '#'){
		moves = 0;
		differentDirection = true;
	}

	if(randomDir == 7 && maze -> getMazeValue(X - 1, Y) != '#'){
		Changes();
		actorChanges(direction, X - 1);
		moves--;
		differentDirection = false;
	}
	else if(randomDir == 7 && maze -> getMazeValue(X - 1, Y) == '#'){
		moves = 0;
		differentDirection = true;
	}

	if(randomDir == 8 && maze -> getMazeValue(X + 1, Y) != '#'){
		Changes();
		actorChanges(direction, X + 1);
		moves--;
		differentDirection = false;
	}
	else if(randomDir == 8 && maze -> getMazeValue(X + 1, Y) == '#'){
		moves = 0;
		differentDirection = true;
	}
}


void Monster::returnToHome(){
	state = 3;
	backColor = brown;
	console -> setColor(foreColor, backColor);
	console -> printChar(X, Y, '$');

	console -> setColor(white, black);
	console -> printChar(X, Y, maze ->getMazeValue(X, Y));

	if(maze -> getNextCoordinate(X, Y, X, Y)){
		console -> setColor(foreColor, backColor);
		console -> printChar(X, Y, '$');
	}
	else
		setNormal();


	if(maze -> getNumMazeValue(X, Y) == 0)
		moves = 0;

}

void Monster::specVuln(){
	if(state == 4)//dinky already vulnerable
		decreaseTicks();
	Changes();

	if(maze ->getNextCoordinate(X,Y, X, Y)){
		console -> setColor(foreColor, backColor);
		console -> printChar(X, Y, display);

	}

	if(maze -> getNumMazeValue(X, Y) == 0){
		console -> setColor(foreColor, backColor);
		console -> printChar(X, Y, display);
	}

}
	
