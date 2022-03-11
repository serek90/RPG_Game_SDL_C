/*
*
* created by: serek90
*/
#pragma once
#include <iostream>
#include "GameObject.h"

class Item:public GameObject
{
private:
	int _color = 12;
	std::string _name;
	bool _visible = true;

public:
	Item();
	Item(const char* textureSheet, int X, int Y,  std::string name) : GameObject(textureSheet, X, Y), _name(name) {}
	virtual ~Item();
	bool isOn();
	void hide();

	friend std::ostream& operator<<(std::ostream& os, const Item& item);

};

