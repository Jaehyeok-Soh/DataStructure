#include "pch.h"

int main()
{
	LinkedStack linkedStack;
	//map
	MapPosition startPos, endPos;
	int mazeArray[HEIGHT][WIDTH] = {
		{0, 0, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 0, 1, 1, 1, 1},
		{1, 1, 1, 0, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0},
		{1, 1, 1, 1, 1, 1, 1, 0}
	};

	startPos.x = 0;
	startPos.y = 0;
	endPos.x = 7;
	endPos.y = 7;

	linkedStack.printMaze(mazeArray);

	linkedStack.findPath(mazeArray, startPos, endPos);

	linkedStack.showPath(mazeArray);

	linkedStack.deleteLinkedStack();
	return 0;
}