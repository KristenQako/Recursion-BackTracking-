/*Name: Kristen Qako
 *Date: 3/28/2019
 *Specification File: solveMaze.cc 
 * Program to draw a random maze and solve it.
 */
 
#include "maze.h"

bool solve(Maze &, int, int);
bool isWallAbove(Maze &, int, int);
bool isWallBelow(Maze &, int, int);
bool isWalltoLeft(Maze &, int, int);
bool isWalltoRight(Maze &, int, int);

int main()  {
	int width, height;
	char answer;
	
	cout << "Do you want me to solve a maze (y/n)? ";
	cin >> answer;

	while (answer == 'y') {
		cout << "Enter number for width of maze: " ;
		cin >> width;
		cout  << "Enter number for height of maze: ";
		cin >> height;

		Maze myMaze(width, height);
		cout << "Maze to be solved: " << endl;
		myMaze.print_maze();
		if (!solve(myMaze, 0, 0)) {
			cout << "Couldn't solve this maze!" << endl;
		} //if maze not solved
		
		cout << "Do you want me to solve another maze (y/n)? ";
		cin >> answer;
                cout << answer << endl;
	} // while solving another maze
		
	return 0;
} //end main program

bool solve(Maze &theMaze, int x, int y) {
    //PreCondition: A maze needs to be declared.
    //Post: Recursively solve theMaze from position x, y
 
    bool mazeIsSolved = false;
    if(theMaze.get_position(x,y) == 2){ //first condition. If position value = 2, return true. Meaning the maze is done.
        theMaze.print_maze();
        return true;
    }else if(theMaze.get_position(x,y) == 1){ //if position is 1, return false, that position was checked and not viable.
        return false;
    }else{ //general case that checks if there is a wall in any position adjacent to it.
        theMaze.set_position(x,y,1);
        if((mazeIsSolved == false) && (!isWallAbove(theMaze,x,y))){
            mazeIsSolved = solve(theMaze,x,y-1);
        } if((mazeIsSolved == false) && (!isWallBelow(theMaze,x,y))){
            mazeIsSolved = solve(theMaze,x,y + 1);
        }if((mazeIsSolved == false) && (!isWalltoLeft(theMaze,x,y))){
            mazeIsSolved = solve(theMaze,x -1, y);
        }if((mazeIsSolved == false) && (!isWalltoRight(theMaze,x,y))){
            mazeIsSolved = solve(theMaze,x + 1, y);
        }
        theMaze.set_position(x,y,0); //the positions that did not work, remove.
    }
    return mazeIsSolved;    
}//end solve

bool isWallAbove(Maze &theMaze, int x, int y) {

	return theMaze.is_horizontal_wall(x,  y); //returns true if there is a wall above.

} //end isWallAbove

bool isWallBelow(Maze &theMaze, int x, int y) {

	return theMaze.is_horizontal_wall(x, y + 1 ); //return true if there is wall Below.
} //end isWallBelow

bool isWalltoLeft(Maze &theMaze, int x, int y) {

	return theMaze.is_vertical_wall(x, y); //returns true if there is a wall left
} //end isWalltoLeft

bool isWalltoRight(Maze &theMaze, int x, int y) {

	return theMaze.is_vertical_wall(x + 1,y); //returns true if there is a wall to the right.
} //end isWalltoRight
