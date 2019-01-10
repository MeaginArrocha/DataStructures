#include <fstream>
#include <string>
#include "CConsole.h"
#include "Maze.h"

Maze::Maze(CConsole * c){
	console = c;
	pelletCounter = 0;
}

void Maze::display()const {
	for(int y = 0; y < 21; y++){
		for(int x = 0; x < 23; x++){
			console ->printChar(x,y,array[y][x]);
		}
	}
	
}

void Maze::displayActors() const{	
	console -> setColor(blue, white);
	console -> printChar(monsterX, monsterY, 'M');
	console -> setColor(black, red);
	console -> printChar(playerX, playerY, '@');
	console -> gotoXY(0,22);
	console -> setColor(white, black);
	
}

bool Maze::loadMaze(const string &filename){
	ifstream input(filename);
	char Input;
	for(int y = 0; y < 21; y++){
		for(int x = 0; x < 23; x++){
			Input = input.get();		

			if(Input == '@'){
				playerX = x;
				playerY = y;
			}
			if(Input == '$'){
				monsterX = x;
				monsterY = y;
			}
			if(Input == '.')
				pelletCounter ++;
			
			array[y][x] = Input;

		}
		Input = input.get();
	}

	return true;
}

bool Maze::done(){//needs to be checked after every tick
	if(pelletCounter == 0)
		return true;
	return false;
}

char Maze::getMazeValue(int x, int y){
	return array[y][x];
}

bool Maze::clearMazePosition(int x, int y){
	if(array[y][x] == '.' || array[y][x] == '*'){
		array[y][x] = ' ';
		pelletCounter--;
		return true;
	}
	return false;
}

int Maze::getPlayerStartX(){
	return playerX;
}

int Maze::getPlayerStartY(){
	return playerY;
}

int Maze::getMonsterStartX(){
	return monsterX;
}

int Maze::getMonsterStartY(){
	return monsterY;
}

int Maze::getPelletCounter(){
	return pelletCounter;
}
