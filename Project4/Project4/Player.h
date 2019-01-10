#include "Actor.h"


#ifndef PLAYER_H
#define PLAYER_H

class Player:public Actor{
public:
	Player(int x, int y, Maze * m, CConsole * c, int liv, int lev, int sco):Actor(x, y, m, c){
		lives = liv; 
		level = lev;
		score = sco;
		foreColor = black;
		backColor = red;
		star = 0;
	}
	//~Player();
	int getNumLivesLeft(); //returns how many lives GacMan has left
	//should start at 3 at beginning of Game
	void decrementNumLives(); //decrements the number of lives the player has left before game is over
	int getScore(); //returns the current score of GacMan
	//should start at 0 at beginning of Game
	int getLevel(); //returns the current level
	void increaseLevel(); //increases level by 1 when it is completed
	void changeDirection(char input);//changes the directions
	void playerChanges();
	bool incScore(char symbol);
	int getStar();
	void decreaseStar();

	//these next methods are passed down from Actor and are explained in Actor's comments
	
	void move();
	char getDisplayChar();

private:
	//player needs to keep track of its lives, levels, and score
	//comes in handy when you have one or more players
	int lives, level, score, star;
};

#endif