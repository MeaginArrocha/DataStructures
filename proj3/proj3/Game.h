class Maze;
class CConsole;
class Player;

#ifndef GAME_H
#define GAME_H

class Game{
public:
	Game(int delay); // creates universe but doesn't start it
	//the int parameter is used as the parameter to the CConsole delay method called during the main loop
	~Game();//cleans up memory
	void run(); //starts the game. will have a main game loop
	//inside this loop the delay method from the CConsole class is called using the delay value given by the constructor

	int getPlayerX() const; //gets x coordinate of player
	int getPlayerY() const; //gets y coordinate of player
	void killPlayer(); //used if a Monster does kill the Player so the Game can reset Actors
	char getMazeContents(int x, int y); //returns the char that is present in the maze at x,y


private:
	//put methods here for starting & ending levels, moving actors, and print messages
	void printMessage(); //the messages onto the command prompt;
	void startLevel(); //starts the level when the enter key is pressed
	void endLevel(); //ends the level if all pellets are gone or if all lives are gone

	//private data for Game should include Maze, CConsole, Player
	Maze * maze;
	CConsole * console;
	Player * player;
	int delayAmount;
	char input;

};

#endif