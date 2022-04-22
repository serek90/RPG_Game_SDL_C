/*
*
* created by: serek90
*/
#pragma once
#include "Screen.h"
#include "Game.h"
#include "TextureManager.h"
#include "MapScreen.h"

class GameOverScreen :
	public Screen
{
	SDL_Texture* _texture;
	SDL_Rect  src, _dst;
public:
	GameOverScreen();
	virtual ~GameOverScreen();

	void display();

	int virtual update();
	void virtual render();
	virtual void handleEvent(SDL_Event event);
	Screen* procedNext();
};

