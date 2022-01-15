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

	if(event.type ==  SDL_KEYDOWN)
	{
		switch (event.key.keysym.sym)
		{
		case SDLK_UP:
			std::cout << "Ide w gore" << std::endl;
			yDecrease();
			break;
		case SDLK_DOWN:
			std::cout << "Ide w dol" << std::endl;
			yIncrease();
			break;
		
		case SDLK_LEFT:
			std::cout << "Ide w lewo" << std::endl;
			xDecrease();
			break;

		case SDLK_RIGHT:
			std::cout << "Ide w prawo" << std::endl;
			xIncrease();
			break;

		case SDLK_SPACE:
			std::cout << "I want to jump" << std::endl;
			break;

		case SDLK_a:
			std::cout << "Hit and kill!!! Ha ha ha" << std::endl;
			break;
		}

	}

	this->Update();
}

