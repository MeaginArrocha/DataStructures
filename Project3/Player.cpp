#include "Player.h"
#include "Actor.h"
#include "Maze.h"

Player::Player(int x, int y, Maze * m, CConsole * c):Actor(x, y, m, c){
	lives = 3;
	level = 0;
	score = 0;
}

Player::~Player(){

}

void Player::resetDirection(){

}

void Player::move(){
	if(direction == '2' && maze ->getMazeValue(X, Y + 1) != '#' && maze ->getMazeValue(X, Y + 1) != '%'){
		console ->printChar(X, Y, ' ');
		console ->setColor(red, black);//change to actor getcolor later
		setY(Y + 1);
		console -> printChar(X, Y, getDisplayChar());
		maze -> clearMazePosition(X , Y);
	}
	if(direction == '4' && maze ->getMazeValue(X - 1, Y) != '#'){
		console ->printChar(X, Y , ' ');
		console ->setColor(red, black);
		setX(X - 1);
		console -> printChar(X, Y, getDisplayChar());
		maze -> clearMazePosition(X, Y);
	}
	if(direction == '6' && maze ->getMazeValue(X + 1, Y) != '#'){
		console ->printChar(X, Y , ' ');
		console ->setColor(red, black);
		setX(X + 1);
		console -> printChar(X, Y, getDisplayChar());
		maze -> clearMazePosition(X, Y);
	}
	if(direction == '8' && maze ->getMazeValue(X, Y - 1) != '#'){
		console ->printChar(X, Y , ' ');
		console ->setColor(red, black);
		setY(Y - 1);
		console -> printChar(X, Y, getDisplayChar());
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
		if(maze -> getMazeValue(X - 1, Y) != '#')
			direction = input;
		break;
	case '6'://right
		if(maze -> getMazeValue(X + 1, Y) != '#')
			direction = input;
		break;
	case '8'://up
		if(maze -> getMazeValue(X, Y - 1) != '#')
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
	bool dead = isDead();
	if(dead == true)
		lives--;
}

int Player::getScore(){
	if(maze ->getMazeValue(X,Y)=='.')
		return score + 10;
	if(maze ->getMazeValue(X,Y) == '*')
		return score +100;
	return score;
}

int Player::getLevel(){
	return 0;//doesn;t like level = crashes; because games get level const?
}

void Player::increaseLevel(){
	if(maze -> getPelletCounter() == 0)
		level++;
}

void Player::setDead(){

}

bool Player::isDead(){
	return false;
}