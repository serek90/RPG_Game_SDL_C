/*
*
* created by: serek90
*/

#include "GameOverScreen.h"
#include "MenuScreen.h"
#include <iostream>

GameOverScreen::GameOverScreen()
{
	_texture = TextureManager::LoadTexture("graphics/game_over_screen.png");
}

GameOverScreen::~GameOverScreen()
{
	SDL_DestroyTexture(_texture);
	std::cout << "Game Object destructor" << std::endl;
}

void GameOverScreen::display()
{

}

int GameOverScreen::update()
{
	return 0;
}

void GameOverScreen::render()
{
	_dst.x = 0;
	_dst.y = 0;
	_dst.w = 1200;
	_dst.h = 800;
	SDL_RenderCopy(Game::renderer, _texture, NULL, &_dst);
}

void GameOverScreen::handleEvent(SDL_Event event)
{
	if (event.type == SDL_KEYDOWN)
			this->off();
}

Screen* GameOverScreen::procedNext() 
{ 
	Screen* next = new MenuScreen();
	return next;
}