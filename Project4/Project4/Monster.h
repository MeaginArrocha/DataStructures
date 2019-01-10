#include "Actor.h"
class Maze;
#include "Player.h"

#ifndef MONSTER_H
#define MONSTER_H

class Monster:public Actor{
public:
	Monster(int x, int y,Maze * m, CConsole * c):Actor(x, y, m, c){
		backColor = black;
		numOfTicks = 0;
		randomSpots = 0;
		directionArray[4];
		state = 1;
		moves = 0;
	}

	Monster(int x, int y,Maze * m, CConsole * c, Player * p):Actor(x, y, m, c){
		backColor = black;
		numOfTicks = 0;
		randomSpots = 0;
		directionArray[4];
		state = 1;
		player = p;
		moves = 0;
	}

	void returnToHome();//monster takes shortest route home from their position when eaten
	//need to make sure nothing messes with it when its on its path home
	//all monsters are a $ when they return
	void setNormal();//will set everything back to normal - colors, chars, call specific movement method
	//used when Monsters go back home after being eaten or after counter for vulnerability counter is 0
	void setVulnerable(int level);//will set everything to vulnerable - colors, chars, call specific movement method
	//used when player eats a power pellet
	//level passes by player - used for counter
	void decreaseTicks();//decreases numofticks - used when monster is vulnerable
	void changeDir();//checks if the move monster wants to do when random is a viable move
	int getState();//returns state monster is in
	void Changes(); // makes the changes that are the same for each monster in random move


	//these are passed down from Actor
	virtual void move() = 0; //passing down again because each monster will move differently
	//print what was in the space before Monster moved there after they leave;
	//don't eat pellets or reput them back on map.
	char getDisplayChar();//will return each specific char for each monster during certain state



protected:
	char display;//holds each monsters character for display
	void moveRandom();//will move the monster randomly
	//used for Inky's normal and vulnerable state
	//used for Clyde's vulnerable state
	bool LineOfSight();//checks if player is in line of sight
	//used for Clyde's normal state
	//used for Stinky's normal state
	void moveLine();//makes the line of sight movement
	int numOfTicks, randomSpots, randomDir, possibleMoves;//used for random moving
	int directionArray[4];//used for checking possibleMoves
	int state; //1 = norm 2 = vuln 3 = home 4 = dinky's special
	Player * player;//used for line of sight
	int xtemp, ytemp, dirtemp, moves, randomNum;//used for line of sight movement
	//helps so I don't change any variables when looking for GacMan
	void specVuln();//used for dinky to return to home with power pellet eaten and hide there
	bool differentDirection;
}; 


#endif