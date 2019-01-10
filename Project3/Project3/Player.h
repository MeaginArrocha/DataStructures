#include "Actor.h"
class CConsole; //might not need this if inherited from Actor
class Maze; //might not need this if inherited from Actor

class Player:public Actor{
public:
	Player(int x, int y, Maze * m, CConsole * c):Actor(x, y, m, c){}
	int getNumLivesLeft(); //returs how many lives GacMan has left
	//should start at 3 at beginning of Game
	void decrementNumLives(); //decrements the number of lives the player has left before game is over
	int getScore(); //returns the current score of GacMan
	//should start at 0 at beginning of Game
	int getLevel(); //returns the current level
	void increaseLevel(); //increases level by 1 when it is completed
	void setDead(); //sets whether player is dead or not
	//starts out alive; if a monster kills GacMan, then set to dead
	bool isDead(); // returns true if the player is dead
	//this will help Game know if the level needs to reset or if game is over


	/*these next methods are passed down from Actor and are explained in Actor's comments
	void move();
	void resetDirection();
	char getDisplayChar();*/

private:
	//player needs to keep track of its lives, levels, and score
	//comes in handy when you have one or more players
	int lives, level, score, x, y;
	CConsole * console;
	Maze * maze;


};