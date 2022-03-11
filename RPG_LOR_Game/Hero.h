/*
*
* created by: serek90
*/
#pragma once
#include "GameObject.h"
#include <vector>
#include "Item.h"

class Hero :
    public GameObject
{
public:
    void Move(SDL_Event event);
	Hero(const char* textureSheet, int X, int Y, int color) : GameObject(textureSheet, X, Y), color(color) {}
	virtual ~Hero();
	void takeItem(Item *item);
	void printItems();

private:
	std::vector<class Item> equipment;
	int color;

};

