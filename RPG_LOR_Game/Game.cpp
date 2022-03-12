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

Hero* player;
Guard *enemy_1, *enemy_2;
Item* sword;
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

	player = new Hero("graphics/knight.png",  192, 192, 8);
	enemy_1 = new Guard("graphics/guard.png", 0, 0, 0);
	enemy_2 = new Guard("graphics/guard.png", 0, 96, 0);
	sword = new Item("graphics/sword.png", 100, 296, "sword_1");
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

void Game::update() /*add issue, it is awful, must to rewrite it*/
{
	if (hit)
		return;
	cnt++;
	if(enemy_1)enemy_1->Move();
	if(enemy_2)enemy_2->Move();
	if (enemy_1 && enemy_2)
	{
		if (player->Collision(enemy_1) || player->Collision(enemy_2))
		{
			if (player->_attack > enemy_1->_attack || player->_attack > enemy_2->_attack)
			{
				delete enemy_1;
				delete enemy_2;
				enemy_1 = nullptr;
				enemy_2 = nullptr;
				std::cout << "Enemy was killed" << std::endl;
			}
			else
			{
				hit = 1;
				delete map;
				delete player;
				delete enemy_1;
				delete enemy_2;
				delete sword;
				game_over_screen = TextureManager::LoadTexture("graphics/game_over_screen.png");
			}

		}
	}
	if (sword->isOn())
	{
		if (player->Collision(sword))
		{
			player->takeItem(sword);
		}
		sword->Update();
	}

}

void Game::render()
{
	SDL_RenderClear(renderer);

	if (!hit)
	{
		map->Draw();
		player->Render();
		if(enemy_1)enemy_1->Render();
		if(enemy_2)enemy_2->Render();
		if (sword->isOn())
		{
			sword->Render();
		}
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




