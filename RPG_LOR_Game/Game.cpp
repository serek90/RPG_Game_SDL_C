#include "Game.h"
#include "TextureManager.h"
#include <iostream>
#include "GameObject.h"

GameObject* player;
GameObject *enemy_1, *enemy_2;


Game::Game()
{
	std::cout << "Call constructor????!" << std::endl;
}

Game::~Game()
{
	std::cout << "Call destructor" << std::endl;
}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;

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

	player = new GameObject("graphics/knight.png", renderer, 96, 96);
	enemy_1 = new GameObject("graphics/enemy.png", renderer, 0, 0);
	enemy_2 = new GameObject("graphics/enemy.png", renderer, 0, 96);
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
		break;
	}
}

void Game::update()
{
	cnt++;

	player->Update();
	enemy_1->Update();
	enemy_2->Update();
}

void Game::render()
{
	SDL_RenderClear(renderer);
	player->Render();
	enemy_1->Render();
	enemy_2->Render();
	SDL_RenderPresent(renderer);
}

void Game::clean() // ToDo: Move to destructor
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}



