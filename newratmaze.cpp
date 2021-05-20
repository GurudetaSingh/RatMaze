/* name: Gurudeta Singh
 * project: Rat Maze
 * class: CS 2500
 * Description: This program will navigate a maze for a rat that is trying to find the exit
 * using a recursive function.
 */

#include <iostream>
#include <fstream>
using namespace std;
const int SIZE = 5;
typedef char Mazes[SIZE][SIZE];

// This struct allows us to pass the maze by value instead of reference
struct Labs
{
	Mazes maze;
};

void clear(Mazes maze);
void printMaze(Mazes maze);
bool outOfBounds(int x, int y);
bool exit(Labs lab, int x, int y);

// This function clears the array for unnecessary data
void clear(Mazes maze)
{
	for(int x = 0; x < SIZE; x++)
		for(int y = 0; y < SIZE; y++)
			maze[x][y] = 0;
} // End clear

int main()
{
	Mazes startingMaze = {'.', '#', '.', '#', '#',
						  '.', '#', '.', '.', '.',
						  '.', '.', '.', '#', '.',
						  '.', '#', '.', '#', '.',
						  '#', '.', '.', '#', 'X'};
	Labs lab;


		for(int x = 0; x < SIZE; x++)
		{
			for(int y = 0; y < SIZE; y++)
				lab.maze[x][y] = startingMaze[x][y];
		}

		printMaze(lab.maze);

			if(exit(lab, 0, 0))
				cout << "The rat found the exit.";
			else
				cout << "No path found";

	return 0;

} // End main

// This function prints out the maze
void printMaze(Mazes maze)
{
	for(int x = 0; x < SIZE; x++)
	{
		for(int y = 0; y < SIZE; y++)
			cout << maze[x][y] << ' ';
		  cout << endl;
	}

} // End printMaze

// Makes sure the array is not out of bounds
bool outOfBounds(int x, int y)
{
	return(x < 0 || y < 0 || x >= SIZE || y >= SIZE);
} // end OutofBounds

// Checks to see if rat is navigating correctly and finding the exit
bool exit(Labs lab, int x, int y)
{
	if(outOfBounds(x, y))
		return false;
	else if(lab.maze[x][y] == 'X')
	{
		cout << endl << "Solution : " << endl;
		printMaze(lab.maze);
		return true;
	}
	else if(lab.maze[x][y] != '.')
		return false;
	else
	{
		lab.maze[x][y] = '@';
		return (exit(lab, x + 1, y) ||
				exit(lab, x, y + 1)  ||
				exit(lab, x - 1, y)  ||
				exit(lab, x, y - 1));
	}
}


