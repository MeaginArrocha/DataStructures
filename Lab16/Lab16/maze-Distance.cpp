#include <iostream>
#include <stack>
using namespace std;

void computeDistance(int maze[][10], int sx, int sy) {
	stack <int> stackX;
	stack <int> stackY;

	stackX.push(sx);
	stackY.push(sy);
	maze[sy][sx] = 0;

	while(!stackX.empty()){
		sx = stackX.top();
		sy = stackY.top();
		stackX.pop();
		stackY.pop();
		if(maze[sy][sx] + 1 < maze[sy + 1][sx]){
			stackX.push(sx);
			stackY.push(sy + 1);
			maze[sy + 1][sx] = maze[sy][sx] + 1;
		}
		if(maze[sy][sx] + 1 < maze[sy][sx + 1]){
			stackX.push(sx + 1);
			stackY.push(sy);
			maze[sy][sx + 1] = maze[sy][sx] + 1;
		}
		if(maze[sy][sx] + 1 < maze[sy - 1][sx]){
			stackX.push(sx);
			stackY.push(sy - 1);
			maze[sy - 1][sx] = maze[sy][sx] + 1;
		}
		if(maze[sy][sx] + 1 < maze[sy][sx - 1]){
			stackX.push(sx - 1);
			stackY.push(sy);
			maze[sy][sx - 1] = maze[sy][sx] + 1;
		}
	}
/*compute distances from (sx,sy) to all other points
use y for first vertical dimension and x for second horizontal dimension of maze
  (this should be similar to the way your project code works)
for simplicity, you should assume the maze array is 
10x10
contains either -1 or 99
    99 represents a spot that has never been visitied
    -1 indicates an impassable wall
sx,sy are valid coordinates and maze[sy][sx] is a 99, i.e. an open spot

Code this method in some manner.
If a position in the maze is unreachable, meaning there is no way to get there
from (sx,sy), then leave its value as 99.

You should do this iteratively using a stack using the depth first search
algorithm described in class.
*/	


}

void print(int maze[10][10]) {//neatly prints the maze
/*Walls are displayed as # signs.  
Unreachable positions as spaces.
All other positions will have their distance printed. Since some distances
are >9 and wouldn't fit in a single digit, so print uses letters.  The
letter A represents 10, B is 11, C is 12, etc.*/

  for (int row=0; row<10; row++) {
	for (int col=0; col<10; col++) {
	  if      (maze[row][col]==-1 ) cout <<"#";
	  else if (maze[row][col]== 99) cout << ' ';
	  else if (maze[row][col]>  9 ) cout << (char)(maze[row][col]-10+'A');
	  else cout <<maze[row][col];
	}
	cout <<endl;
  }
  cout <<endl;
}

void main () {
  int maze[10][10] = {//-1 is a wall, 99 is empty, note border is all wall
    { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    { -1,99,99,99,99,99,99,99,99,-1},
    { -1,99,-1,-1,99,-1,-1,99,99,-1},
    { -1,99,-1,99,99,99,-1,99,99,-1},
    { -1,99,-1,-1,-1,99,-1,-1,-1,-1},
    { -1,99,-1,99,99,99,-1,99,99,-1},
    { -1,99,99,99,-1,99,-1,99,99,-1},
    { -1,-1,-1,-1,-1,99,-1,-1,-1,-1},
    { -1,99,99,99,99,99,99,99,99,-1},
    { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1} 
  };
  print(maze);//starting maze, all 99 so just walls and spaces
  cout <<endl;
  computeDistance(maze, 3,3);//starting from 3,3
  print(maze);//should have distances in it now
}