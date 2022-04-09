/*
*
* created by: serek90
*/
#include "Hero.h"
#include <iostream>
#include "TextureManager.h"


Hero::~Hero()
{
	std::cout << "Hero was killed!!!" << std::endl;
}

void Hero::Move(SDL_Event event)
{
	static int x = 0, y = 0;
	static int counter = 0;

	if(event.type ==  SDL_KEYDOWN)
	{
		switch (event.key.keysym.sym)
		{
		case SDLK_UP:
			yDecrease();
			break;
		case SDLK_DOWN:
			yIncrease();
			break;
		
		case SDLK_LEFT:
			xDecrease();
			if(currntTexture != "left")
				this->updateTexture(textureLeft);
			currntTexture = "left";
			counter = 0;
			break;

		case SDLK_RIGHT:
			xIncrease();
			if(currntTexture != "right")
				this->updateTexture(textureRight);
			currntTexture = "right";
			counter = 0;
			break;

		case SDLK_SPACE:
			std::cout << "I want to jump" << std::endl;
			break;

		case SDLK_a:
			std::cout << "Hit and kill!!! Ha ha ha" << std::endl;
			break;
		case SDLK_e:
			printItems();
			break;
		}
	}
	else
	{
		if (counter++ == 200) //JSJS ???
		{
			this->updateTexture(textureFront);
			currntTexture = "front";
		}

	}

	this->Update();
}

void Hero::takeItem(Item *item)
{
	item->hide();
	updateSwordTexture();

	equipment.push_back(*item);
	_defence += item->_defence;
	_attack += item->_attack;
	printItems();
}

void Hero::printItems()
{
	std::cout << "Hero has in his equipment:" << std::endl;
	// Iterate over a vector using range based for loop
	for (auto& elem : equipment)
	{
		std::cout << elem;
	}

	std::cout << "defence" << _defence << std::endl;
	std::cout << "attack" << _attack << std::endl;
}

bool Hero::fight()
{
	return true;
}

/*
*
* Metod to updated hero textures, need to move to item, sword class
*/
void Hero::updateSwordTexture()
{
	textureRight = "graphics/knight_right_sword.png";
	textureLeft = "graphics/knight_left_sword.png";
	textureFront = "graphics/knight_sword.png";
}
