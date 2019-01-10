#include "Player.h"
#include "Actor.h"
#include "Maze.h"


void Player::resetDirection(){
	direction = '?';
}

void Player::move(){
	if(direction == '2' && maze ->getMazeValue(X, Y + 1) != '#' && maze ->getMazeValue(X, Y + 1) != '%'){
		console ->printChar(X, Y, ' ');
		console ->setColor(foreColor, backColor);//change to actor getcolor later
		setY(Y + 1);
		console -> printChar(X, Y, getDisplayChar());
		incScore(maze -> getMazeValue(X, Y));
		maze -> clearMazePosition(X , Y);
	}
	if(direction == '4' && maze ->getMazeValue(X - 1, Y) != '#' && maze ->getMazeValue(X - 1, Y) != '%'){
		console ->printChar(X, Y , ' ');
		console ->setColor(foreColor, backColor);
		setX(X - 1);
		console -> printChar(X, Y, getDisplayChar());
		incScore(maze -> getMazeValue(X, Y));
		maze -> clearMazePosition(X, Y);
	}
	if(direction == '6' && maze ->getMazeValue(X + 1, Y) != '#' && maze ->getMazeValue(X + 1, Y) != '%'){
		console ->printChar(X, Y , ' ');
		console ->setColor(foreColor, backColor);
		setX(X + 1);
		console -> printChar(X, Y, getDisplayChar());
		incScore(maze -> getMazeValue(X, Y));
		maze -> clearMazePosition(X, Y);

	}
	if(direction == '8' && maze ->getMazeValue(X, Y - 1) != '#' && maze ->getMazeValue(X, Y - 1) != '%'){
		console ->printChar(X, Y , ' ');
		console ->setColor(foreColor, backColor);
		setY(Y - 1);
		console -> printChar(X, Y, getDisplayChar());
		incScore(maze -> getMazeValue(X, Y));
		maze -> clearMazePosition(X, Y);
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


char Player::getDisplayChar(){
	return '@';
}

int Player::getNumLivesLeft(){
	return lives;
}

void Player::decrementNumLives(){
	if(isDead())
		lives--;
}

void Player::incScore(char symbol){
	if(symbol == '.')
		score = score + 10;
	if(symbol == '*')
		score = score + 100;
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

void Player::setDead(){

}

bool Player::isDead(){
	return false;
}