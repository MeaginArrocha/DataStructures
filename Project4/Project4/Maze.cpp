#include <fstream>
#include <string>
#include <stack>
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
	console -> setColor(brown, black);
	console -> printChar(monsterX, monsterY, 'I');
	console -> setColor(black, red);
	console -> printChar(playerX, playerY, '@');
	console -> gotoXY(0,22);
	console -> setColor(white, black);
	
}

bool Maze::loadMaze(const string &filename){
	ifstream input(filename);
	if(input.is_open() == false)
		return false;
	char Input;
	for(int y = 0; y < 21; y++){
		for(int x = 0; x < 23; x++){
			Input = input.get();		

			if(Input == '@'){
				playerX = x;
				playerY = y;
				Input = ' ';
				DFSarray[y][x] = 99;
			}
			if(Input == '$'){
				monsterX = x;
				monsterY = y;
				DFSarray[y][x] = 0;
			}
			if(Input == '.' || Input == '*'){
				pelletCounter ++;
				DFSarray[y][x] = 99;
			}
			if(Input == '#')
				DFSarray[y][x] = -1;
			if(Input == ' ' || Input == '%')
				DFSarray[y][x] = 99;


			array[y][x] = Input;

		}
		Input = input.get();
	}

	return true;
}

void Maze::computeDistance(int sx, int sy) {
	stack <int> stackX;
	stack <int> stackY;

	stackX.push(sx);
	stackY.push(sy);

	while(!stackX.empty()){
		sx = stackX.top();
		sy = stackY.top();
		stackX.pop();
		stackY.pop();
		if(DFSarray[sy][sx] + 1 < DFSarray[sy + 1][sx]){
			stackX.push(sx);
			stackY.push(sy + 1);
			DFSarray[sy + 1][sx] = DFSarray[sy][sx] + 1;
		}
		if(DFSarray[sy][sx] + 1 < DFSarray[sy][sx + 1]){
			stackX.push(sx + 1);
			stackY.push(sy);
			DFSarray[sy][sx + 1] = DFSarray[sy][sx] + 1;
		}
		if(DFSarray[sy][sx] + 1 < DFSarray[sy - 1][sx]){
			stackX.push(sx);
			stackY.push(sy - 1);
			DFSarray[sy - 1][sx] = DFSarray[sy][sx] + 1;
		}
		if(DFSarray[sy][sx] + 1 < DFSarray[sy][sx - 1]){
			stackX.push(sx - 1);
			stackY.push(sy);
			DFSarray[sy][sx - 1] = DFSarray[sy][sx] + 1;
		}
	}

}

bool Maze::getNextCoordinate(int curX, int curY, int &newX, int &newY){
	
	if(DFSarray[newY - 1][newX] < DFSarray[curY][curX] && DFSarray[newY - 1][newX] != -1){
		newY = newY - 1;
		return true;
	}
	else if(DFSarray[newY + 1][newX] < DFSarray[curY][curX] && DFSarray[newY + 1][newX] != -1){
		newY = newY + 1;
		return true;
	}
	else if(DFSarray[newY][newX - 1] < DFSarray[curY][curX] && DFSarray[newY][newX - 1] != -1){
		newX = newX - 1;
		return true;
	}
	else if(DFSarray[newY][newX + 1] < DFSarray[curY][curX] && DFSarray[newY][newX + 1] != -1){
		newX= newX + 1;
		return true;
	}
	if(DFSarray[curY][curX] == DFSarray[newX][newY])
		return false;
	return false;
}

bool Maze::done(){//needs to be checked after every tick
	if(pelletCounter == 0)
		return true;
	return false;
}

char Maze::getMazeValue(int x, int y){
	return array[y][x];
}

int Maze::getNumMazeValue(int x, int y){
	return DFSarray[y][x];
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

