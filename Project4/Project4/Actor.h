#include "CConsole.h"
class Maze;

#ifndef ACTOR_H
#define ACTOR_H

class Actor{
public:
	Actor(int x, int y, Maze * m, CConsole * c);
	virtual~Actor(); //cleans up junk
	int getX() const; //returns the X coordinate of the Actor
	int getY() const; //returns the Y coordinate of the Actor
	void setX(int); //sets the X coordinate of the Actor
	void setY(int); //sets the Y coordinate of the Actor
	void resetDirection(); //resets the Actor's current direction to "none"
	//used when a new level starts
	virtual void move() = 0; //to allow the Actor to make their move
	//needs to check keyboard to see if the player wants to change the direction
	//it should also move the GacMan in specified direction if it is allowed
	//use getInput from CConsole to read the keyboard
	Color getForeColor(); //returns foreground (text) colors that the Actor should be displayed in
	Color getBackColor(); //returns background colors for the Actor to be displayed in
	virtual char getDisplayChar() = 0; //returns the character that should be used when displaying this Actor
	//so that Game can display an Actor w/o having ot know which on it is or its state


protected:
	CConsole * console;
	Maze * maze;
	int X, Y;
	char direction;
	Color foreColor, backColor;
	void actorChanges(char xy, int coord);
};

#endif