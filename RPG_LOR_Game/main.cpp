#include <stdio.h>
#include <stdlib.h>
#include "Game.h"

int main(int argc, char * argv[])
{
	const uint32_t FPS = 60;
	const uint32_t frameDelay = 1000 / 60; // ms between each frames

	uint32_t frameStart;
	uint32_t frameTime;

	Game* game = new Game;

	game->init("Knight's game", 100, 100, 1200, 800, false);

	while (game->running())
	{
		frameStart = SDL_GetTicks();

		game->handleEvents();
		game->update();
		game->render();

		frameTime = frameStart - SDL_GetTicks();

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}

	delete game;

	return 0;
}