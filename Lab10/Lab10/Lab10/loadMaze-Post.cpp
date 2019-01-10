#include <fstream>
#include <string>
using namespace std;
#include "CConsole.h"

class Maze {
public:
  Maze();
  void display() const; //prints walls to screen
  void displayActors() const;
  //prints @ in black on red background at position indicated in maze file for player
  //print a blue M on a white background at position indicated in maze file for monsters
  bool loadMaze(const string &filename);
private:
  int playerX, playerY;//values set by laodMaze and used by displayActors 
  int monsterX, monsterY;
  CConsole * console;
  //add something(s) here to store the maze you read from the file
  char array[21][23];
};  

Maze::Maze(){
	console = new CConsole(60,25);
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


void main () {
  Maze m;
  bool result =   m.loadMaze("MAZE0.txt");
  if (result) {
	m.display();
	m.displayActors();
  }
}
