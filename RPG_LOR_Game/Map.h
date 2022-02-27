/*
*
* created by: serek90
*/
#pragma once
#include "Game.h"
#include <iostream>
#include <fstream>

#define map_row  20
#define map_column 25

class Map
{
public:

	Map();
	~Map();

	void LoadMap();
	void Draw();

private:

	SDL_Rect src, dst;
	SDL_Texture* dirt; //create new class for each element
	SDL_Texture* grass;
	SDL_Texture* water;
	SDL_Texture* tree;
	SDL_Texture* snow;


	char map[map_row][map_column];

};

