#include "Hero.h"
#include <iostream>
#include "TextureManager.h"

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

		}

	}

	this->Update();
}

