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
	Hero(const char* textureSheet, int X, int Y, int color) : GameObject(textureSheet, X, Y), _color(color) {}
	virtual ~Hero();
	void takeItem(Item *item);
	void printItems();
	bool fight();


	int _defence = 5; //move to private
	int _attack = 5; //move to private

private:
	std::vector<class Item> equipment;
	int _color;
	std::string _name;


};

