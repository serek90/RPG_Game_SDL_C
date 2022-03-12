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

	int _defence = 0; //move to privaet section
	int _attack = 20; //move to privaet section

	friend std::ostream& operator<<(std::ostream& os, const Item& item);

};

