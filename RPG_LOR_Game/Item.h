/*
*
* created by: serek90
*/
#pragma once
#include <iostream>
#include "GameObject.h"

class Item:public GameObject
{
public:
	Item();
	Item(const char* textureSheet, int X, int Y, int color) : GameObject(textureSheet, X, Y), _color(color) {}
	virtual ~Item();
	bool isOn();
	void hide();


private:
	int _color;
	bool _visible = true;
	std::string name;
};

