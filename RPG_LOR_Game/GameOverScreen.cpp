/*
*
* created by: serek90
*/
#include "GameOverScreen.h"

GameOverScreen::GameOverScreen()
{
	_texture = TextureManager::LoadTexture("graphics/game_over_screen.png");
}

GameOverScreen::~GameOverScreen()
{

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