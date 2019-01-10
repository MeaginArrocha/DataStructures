#include <fstream>
#include <string>
using namespace std;
class CConsole;

#ifndef MAZE_H
#define MAZE_H

class Maze{
public:
	Maze(CConsole * c);
//	~Maze();
	void display() const; //prints walls to screen; prints level, lives, and score
	void displayActors() const;
	 //prints @ in black on red background at position indicated in maze file for player
     //print a blue M on a white background at position indicated in maze file for monsters
	bool loadMaze(const string &filename);  //loads the maze & returns true if it could load the file
	//would only return false if the player has completed all of the levels
	void resetDisplay(); // redraws starting positions when player dies
	//posibly redraw pelets that were under monsters when the player died
	bool done(); //returns true if there are no pellets remaining on board
	//try to avoid a loop that checks every spot in maze. ; maybye a pellet counter?
	char getMazeValue(int x, int y); // returns the char at the position in the maze
	//will be used to determine if move is legal
	bool clearMazePosition(int x, int y); //sets position x,y in maze to be empty when a player eats a pellet
	//decreases pellet counter so when it gets to 0 there are no more left; game over
	//returns true if successful.
	int getPlayerStartX(); //returns the x coordinate of player's starting position
	int getPlayerStartY(); //returns the y coordinate of player's starting position
	//startX & startY are helpful to Game when a Player dies and has to reset
	int getMonsterStartX(); //returns x coordinate of monster's starting position
	int getMonsterStartY(); //returns y coordinate of monster's starting position
	//useful to Game when Player dies so the monsters can reset
	int getPelletCounter(); //returns pellet count


private:
	int playerX, playerY; //values set by laodMaze and used by displayActors 
	int monsterX, monsterY; //used to remember monsters coordinates; set by loadMaze
	CConsole * console; 
	char array[21][23]; //holds of of the characters in the maze
	int pelletCounter; //will keep track of pellets to know if the game is over
	//add to counter when you fill in array; everytime there is a pellet = pellet++

};

#endif