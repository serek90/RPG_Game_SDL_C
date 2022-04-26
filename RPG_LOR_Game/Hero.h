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
	Hero(const char* textureSheet, int X, int Y, int color) : GameObject(textureSheet, X, Y), _color(color) {
		_defence = 5;
		_attack = 5;
	}
	virtual ~Hero();
	void takeItem(Item *item);
	void printItems() const;
	bool fight();


private:
	std::vector<class Item> equipment;
	int _color;
	std::string _name;

	const char* textureRight = "graphics/knight_right.png";
	const char* textureLeft = "graphics/knight_left.png";
	const char* textureFront = "graphics/knight.png";
	void updateSwordTexture(); 
	std::string currntTexture = "front";
};

