#pragma once

#define WIDTH 8
#define HEIGHT 8

#define NUM_DIRECTIONS 4

//offset: x, y
static int DIRECTION_OFFSETS[NUM_DIRECTIONS][2] = {
	{0, -1},	//UP
	{1, 0},		//RIGHT
	{0, 1},		//DOWN
	{-1, 0}		//LEFT
};

enum PostStatus { NOT_VISIT = 0, WALL = 1, VISIT = 2 };

struct MapPosition
{
	int x;
	int y;
	int direction;
};