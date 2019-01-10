#include <fstream>
#include <string>
using namespace std;
#include "CConsole.h"
#include "Maze.h"

Maze::Maze(CConsole * console){
	//console = new CConsole(60,25);
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
	char pleaseWork;
	for(int y = 0; y < 21; y++){
		for(int x = 0; x < 23; x++){
			pleaseWork = input.get();		

			if(pleaseWork == '@'){
				playerX = x;
				playerY = y;
			}
			if(pleaseWork == '$'){
				monsterX = x;
				monsterY = y;
			}
			array[y][x] = pleaseWork;
		}
		pleaseWork = input.get();
	}

	return true;
}


/*void main () {
  Maze m;
  bool result =   m.loadMaze("MAZE0.txt");
  if (result) {
	m.display();
	m.displayActors();
  }
}*/