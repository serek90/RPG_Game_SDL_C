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

SDL_Event event;

int main(int argc, char** argv)
{
	constexpr const uint32_t FPS = 60;
	constexpr const uint32_t frameDelay = 1000 / FPS; // ms between each frames

	uint32_t frameStart;
	uint32_t frameTime;
	
	auto game = std::make_unique<Game>();
	auto audio = std::make_unique<GameAudio>("resources/file_example_WAV_1MG.wav");

	game->init("Knight's game", 100, 100, 1200, 800, false); // move to the constructor

	while (game->running())
	{
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

	return 0;
}
