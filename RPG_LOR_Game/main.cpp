/*
*
* created by: serek90
*/
#include <stdio.h>
#include <stdlib.h>
#include <thread>
#include <chrono>
#include <mutex>
#include <iostream>
#include "Game.h"
#include "audio.h"


#if defined(_WIN32)
#include <SDL.h>
#include <SDL_image.h>
#else
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#endif


int i = 0;
bool finishGame = false;
std::mutex m;


SDL_Event event;


int main(int argc, char** argv)
{
	const uint32_t FPS = 60;
	const uint32_t frameDelay = 1000 / FPS; // ms between each frames

	uint32_t frameStart;
	uint32_t frameTime;

	Game* game = new Game;

	game->init("Knight's game", 100, 100, 1200, 800, false);


	std::thread audio_thread(&audio_play);

	while (game->running())
	{
		i++;
		frameStart = SDL_GetTicks();

		SDL_PollEvent(&event);
		game->handleEvents(event);
		game->update();
		game->render();

		frameTime = frameStart - SDL_GetTicks();

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}

	finishGame = true;
	audio_thread.join();
	delete game;

	return 0;
}