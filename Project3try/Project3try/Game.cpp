#include "Game.h"
#include "CConsole.h"
#include "Maze.h"
#include "Player.h"

Game::Game(int delay){
	console = new CConsole(60,25);
	maze = new Maze(console);
	isFileFound = maze -> loadMaze("MAZE" + to_string(0) + ".txt");
	player = new Player(maze -> getPlayerStartX(), maze ->getPlayerStartY(), maze, console, 3, 0, 0);
	delayAmount = delay;
	
}

Game::~Game(){
	delete console;
	delete maze;
	delete player;
}

void Game::run(){
	printMessage();
	startLevel();
	console -> printStringClearLine(0 , 22 , "");

	while(player -> getNumLivesLeft() != 0 && isFileFound != false){
		console -> delay(delayAmount);
		if(console -> getInput(input))
			player ->changeDirection(input);
		player -> move();
		console -> gotoXY(26 , 21);
		console -> setColor(white, black);
		console -> printInt(player -> getScore());
		if(maze -> done()){
			endLevel();
			if(isFileFound == true){
				printMessage();
				startLevel();
				console -> printStringClearLine(0 , 22 , "");
			}
		}
	}

	if(player -> getNumLivesLeft() == 0){
		console -> gotoXY(0, 22);
		console -> printString("You lost all of your lives. Press Enter to Quit.");
		console -> waitForEnter();
	}
	if(isFileFound == false){
		console -> printString(0, 22, "YOU BEAT THE GAME!!!!");
		console -> printString(0, 23, "Press Enter to Quit.");
		console -> waitForEnter();
	}

}

void Game::printMessage(){
	console -> gotoXY(0 , 21);
	console -> printString("Lives: ");
	console -> printInt(player -> getNumLivesLeft());
	console -> gotoXY(9, 21);
	console -> printString("Levels: ");
	console -> printInt(player -> getLevel());
	console -> gotoXY(19, 21);
	console -> printString("Score: ");
	console -> printInt(player -> getScore());
}
	
void Game::startLevel(){
	maze -> display();
	maze -> displayActors();

	console -> gotoXY(0, 22);
	console -> printStringClearLine("Press Enter to Start Game");
	console -> waitForEnter();	
}

void Game::endLevel(){
	console -> printString(0, 22, "You beat the level!");
	player -> increaseLevel();
	isFileFound = maze -> loadMaze("MAZE" + to_string(player -> getLevel()) + ".txt");
	if(isFileFound == true){
		console -> gotoXY(17, 21);
		console ->printInt(player -> getLevel());
		console -> printString(21, 22, "Press Enter To Continue");
		console -> waitForEnter();

		player -> resetDirection();
		player -> setX(maze -> getPlayerStartX());
		player -> setY(maze -> getPlayerStartY());
		
	}
}
