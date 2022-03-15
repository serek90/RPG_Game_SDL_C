#pragma once
#include "Game.h"
class Screen
{

public:

	Screen() { };
	virtual ~Screen() { };
	virtual int update() = 0;
	virtual void render() = 0;
	virtual void handleEvent(SDL_Event event) = 0;
	Screen* next; //move to private
};

