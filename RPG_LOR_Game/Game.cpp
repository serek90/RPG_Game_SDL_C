/*
*
* created by: serek90
*/

#include <iostream>
#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"
#include "Hero.h"
#include "Guard.h"
#include "Item.h"
#include "MapScreen.h"
#include "MenuScreen.h"
#include "GameOverScreen.h"


Screen* actualScreen; // JSJS

SDL_Renderer* Game::renderer = NULL; //nullptr


Game::Game()
{
	std::cout << "Call constructor????!" << std::endl;
}

Game::~Game()
{
	std::cout << "Call destructor" << std::endl;
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;

	screenWidth = width;
	screenHeight = height;

	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystem initialised!..." << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
		{
			std::cout << "Window cretaed" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if(renderer)
		{
			SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
			std::cout << "Renderer cretaed" << std::endl;
		}
		is_Running = true;
	}
	else
	{
		is_Running = false;
	}

	actualScreen = new MapScreen();

}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		is_Running = false;
		break;

	default:
			actualScreen->handleEvent(event);
		break;
	}
}

void Game::update()
{
	Screen* tmp; 

	actualScreen->update();
	if(!(actualScreen->isOn()))
	{
		tmp = actualScreen->procedNext();
		delete(actualScreen);
		actualScreen = tmp;
	}
}

void Game::render()
{
	SDL_RenderClear(renderer);

	actualScreen->render();

	SDL_RenderPresent(renderer);
}




