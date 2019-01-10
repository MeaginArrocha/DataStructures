#include "Actor.h"

Actor::Actor(int x, int y, Maze * m, CConsole * c){
	X = x; 
	Y = y;
	maze = m;
	console = c;
}

Actor::~Actor(){

}

int Actor::getX() const{
	return X;
}

int Actor::getY() const{
	return Y;
}

void Actor::setX(int newX){
	X = newX;
}

void Actor::setY(int newY){
	Y = newY;
}

Color Actor::getForeColor(){
	return foreColor;
}

Color Actor::getBackColor(){
	return backColor;
}

void Actor::resetDirection(){
	direction = '?';
}

void Actor::actorChanges(char xy, int coord){
	console ->setColor(foreColor, backColor);
	if(xy == 'X')
		setX(coord);
	if(xy == 'Y')
		setY(coord);
	console -> printChar(X, Y, getDisplayChar());
}
