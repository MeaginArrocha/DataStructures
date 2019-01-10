#include "Player.h"
#include "Actor.h"
#include "Maze.h"


void Player::move(){
	if(direction == '2' && maze ->getMazeValue(X, Y + 1) != '#' && maze ->getMazeValue(X, Y + 1) != '%'){
		console -> setColor(white, black);
		console ->printChar(X, Y , ' ');
		actorChanges('Y', Y + 1);
		playerChanges();
	}
	if(direction == '4' && maze ->getMazeValue(X - 1, Y) != '#' && maze ->getMazeValue(X - 1, Y) != '%'){
		console -> setColor(white, black);
		console ->printChar(X, Y , ' ');
		actorChanges('X', X - 1);
		playerChanges();
	}
	if(direction == '6' && maze ->getMazeValue(X + 1, Y) != '#' && maze ->getMazeValue(X + 1, Y) != '%'){
		console -> setColor(white, black);
		console ->printChar(X, Y , ' ');			
		actorChanges('X', X + 1);
		playerChanges();
	}
	if(direction == '8' && maze ->getMazeValue(X, Y - 1) != '#' && maze ->getMazeValue(X, Y - 1) != '%'){
		console -> setColor(white, black);
		console ->printChar(X, Y , ' ');
		actorChanges('Y', Y - 1);
		playerChanges();
	}

}

	void Player::changeDirection(char input){
	switch(input){
	case '2'://down
		if(maze -> getMazeValue(X, Y + 1) != '#' && maze -> getMazeValue(X, Y + 1) != '%')
			direction = input;
		break;
	case '4'://left
		if(maze -> getMazeValue(X - 1, Y) != '#' && maze -> getMazeValue(X - 1, Y) != '%')
			direction = input;
		break;
	case '6'://right
		if(maze -> getMazeValue(X + 1, Y) != '#' && maze -> getMazeValue(X + 1, Y) != '%')
			direction = input;
		break;
	case '8'://up
		if(maze -> getMazeValue(X, Y - 1) != '#' && maze -> getMazeValue(X, Y - 1) != '%')
			direction = input;
		break;
	default:
		break;
	}
}

void Player::playerChanges(){
	incScore(maze -> getMazeValue(X, Y));
	maze -> clearMazePosition(X, Y);
}
int Player::getStar(){
	return star;
}

void Player::decreaseStar(){
	star--;
}

char Player::getDisplayChar(){
	return '@';
}

int Player::getNumLivesLeft(){
	return lives;
}

void Player::decrementNumLives(){
		lives--;
}

bool Player::incScore(char symbol){	
	if(score == 10000){
		lives ++;
		console -> gotoXY(7, 21);
		console -> setColor(white, black);
		console -> printInt(lives);
	}
	if(symbol == '.'){
		score = score + 10;
		return true;
	}
	if(symbol == '*'){
		score = score + 100;
		star++;
		return true;
	}
	if(symbol == 'M'){
		score = score + 1000;
		return true;
	}

	return false;
}


int Player::getScore(){
	return score;
}

int Player::getLevel(){
	return level;
}

void Player::increaseLevel(){
	if(maze -> done())
		level++;
}
