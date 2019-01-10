#include "Game.h"
#include "CConsole.h"
#include "Maze.h"
#include "Player.h"
#include "Monster.h"
#include "Inky.h"
#include "Clyde.h"
#include "Stinky.h"
#include "Dinky.h"

Game::Game(int delay){
	console = new CConsole(60,25);
	maze = new Maze(console);
	isFileFound = maze -> loadMaze("MAZE" + to_string(0) + ".txt");
	maze -> computeDistance(maze -> getMonsterStartX(), maze -> getMonsterStartY());
	player = new Player(maze -> getPlayerStartX(), maze ->getPlayerStartY(), maze, console, 3, 0, 0);
	delayAmount = delay;
	monsterArray[0] = new Inky(maze -> getMonsterStartX(), maze -> getMonsterStartY(), maze, console);
	monsterArray[1] = new Clyde(maze -> getMonsterStartX(), maze ->getMonsterStartY(), maze, console, player);
	monsterArray[2] = new Stinky(maze -> getMonsterStartX(), maze ->getMonsterStartY(), maze, console, player);
	monsterArray[3] = new Dinky(maze -> getMonsterStartX(), maze ->getMonsterStartY(), maze, console, player);
}

Game::~Game(){
	delete console;
	delete maze;
	delete player;
	for(int i = 0; i < 4; i++){
		delete monsterArray[i];
	}
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
		getEaten();
		
		console -> gotoXY(26 , 21);
		console -> setColor(white, black);
		console -> printInt(player -> getScore());
		
		if(player -> getStar() == 1){
			for(int i = 0; i < 4; i ++){
				if(monsterArray[i] -> getState() != 3){
					monsterArray[i] ->setVulnerable(player ->getLevel());
				}
			}
			player-> decreaseStar();
		}

		for(int i = 0; i < 4; i ++){
			if(monsterArray[i] -> getState() == 3){
				monsterArray[i] -> returnToHome();
			}
			else{
				monsterArray[i] -> move();
				if(getEaten())
					break;
			}
		}

		if(maze -> done()){
			endLevel();
			if(isFileFound == true){
				printMessage();
				startLevel();
				console -> printStringClearLine(0, 22, "");
			}
		}
	}

	if(player -> getNumLivesLeft() == 0){
		console -> setColor(white, black);
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

bool Game::getEaten(){
	for(int i = 0; i < 4; i ++){
		if(player -> getX() == monsterArray[i] -> getX() && player -> getY() == monsterArray[i] -> getY() && monsterArray[i] -> getState() != 3){
			if(monsterArray[i] -> getState() == 2){
				player -> incScore('M');
				monsterArray[i] -> returnToHome();
				console -> setColor(player -> getForeColor(), player -> getBackColor());
				console -> printChar(player -> getX(), player -> getY(), player -> getDisplayChar());
			}
			else
				killPlayer();
			return true;
		}
	}
	return false;
}

void Game::Set(){
	player -> resetDirection();
	player -> setX(maze -> getPlayerStartX());
	player -> setY(maze -> getPlayerStartY());


	for(int i = 0; i < 4; i ++){
		monsterArray[i] -> resetDirection();
		monsterArray[i] -> setX(maze -> getMonsterStartX());
		monsterArray[i] -> setY(maze -> getMonsterStartY());
	}
}

void Game::killPlayer(){
	Set();

	player -> decrementNumLives();
	console -> gotoXY(7, 21);
	console -> setColor(white, black);
	console -> printInt(player -> getNumLivesLeft());
	if( player -> getNumLivesLeft() > 0){
		console -> printString(0, 22, "You lost a life but still have more! Press Enter to Continue");
		console -> waitForEnter();
		console -> printStringClearLine(0, 22, "");
		console -> setColor(white, black);
		maze -> display();
		maze -> displayActors();
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
	console -> setColor(white, black);
	console -> printString(0, 22, "You beat the level!");
	player -> increaseLevel();
	isFileFound = maze -> loadMaze("MAZE" + to_string(player -> getLevel()) + ".txt");
	maze -> computeDistance(maze -> getMonsterStartX(), maze -> getMonsterStartY());
	if(isFileFound == true){
		console -> gotoXY(17, 21);
		console ->printInt(player -> getLevel());
		console -> printString(21, 22, "Press Enter To Continue");
		console -> waitForEnter();

		Set();
	}
}
