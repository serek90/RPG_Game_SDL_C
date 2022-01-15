#include "Game.h"
#include "TextureManager.h"
#include <iostream>
#include "GameObject.h"
#include "Map.h"
#include "Hero.h"
#include "Guard.h"

Hero* player;
Guard *enemy_1, *enemy_2;
Map* map;


SDL_Renderer* Game::renderer = NULL; //nullptr

SDL_Rect  src, dst;
int hit = 0;
SDL_Texture* game_over_screen;

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

	player = new Hero("graphics/knight.png",  96, 96, 8);
	enemy_1 = new Guard("graphics/guard.png", 0, 0, 0);
	enemy_2 = new Guard("graphics/guard.png", 0, 96, 0);
	map = new Map();

}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	player->Move(event);
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
	if (hit)
		return;
	cnt++;
	enemy_1->Move();
	enemy_2->Move();
	if (player->Collision(enemy_1) || player->Collision(enemy_2))
	{
		hit = 1;
		delete map;
		delete player;
		delete enemy_1;
		delete enemy_2;
		game_over_screen = TextureManager::LoadTexture("graphics/game_over_screen.png");
	}
}

void Game::render()
{
	SDL_RenderClear(renderer);

	if (!hit)
	{
		map->Draw();
		player->Render();
		enemy_1->Render();
		enemy_2->Render();
	}
	else
	{
		dst.x = 0;
		dst.y = 0;
		dst.w = screenWidth;
		dst.h = screenHeight;
		SDL_RenderCopy(Game::renderer, game_over_screen, NULL, &dst);
	}

	SDL_RenderPresent(renderer);
}




