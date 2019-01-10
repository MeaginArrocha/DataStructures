#include "Game.h"
#include "CConsole.h"
#include "Maze.h"
#include "Player.h"

Game::Game(int delay){
	console = new CConsole(60,25);
	maze = new Maze(console);
	maze -> loadMaze("MAZE" + to_string(player -> getLevel()) + ".txt");
	player = new Player(maze -> getPlayerStartX(), maze ->getPlayerStartY(), maze, console, 3, 0, 0);
	delayAmount = delay;
}

Game::~Game(){
	delete console;
	delete maze;
	delete player;
}

void Game::run(){
	maze -> display();
	maze -> displayActors();

	printMessage();
	console -> waitForEnter();

	console -> printStringClearLine(0 , 24 , "");
	console -> gotoXY(0 , 23);
	console -> printString("Lives: ");
	console -> printInt(player -> getNumLivesLeft());
	console -> gotoXY(9, 23);
	console -> printString("Levels: ");
	console -> printInt(player -> getLevel());
	console -> gotoXY(19, 23);
	console -> printString("Score: ");
	console -> printInt(player -> getScore());

	while(player -> isDead() == false){
		console -> delay(delayAmount);
		if(console -> getInput(input))
			player ->changeDirection(input);
		player -> move();
		/*if(maze -> clearMazePosition(player ->getX() , player ->getY())){
			console -> gotoXY(0 , 31);
			console -> printInt(player -> getScore());
		}*/
	}
}

void Game::printMessage(){
	console -> gotoXY(0, 24);
	console -> printString("Press Enter to Start Game");
}
	
void Game::startLevel(){

}
