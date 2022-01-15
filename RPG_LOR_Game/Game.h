#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <SDL_image.h>

class Game
{
public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	
	void handleEvents();
	void update();
	void render();

	bool running() { return is_Running; }

	static SDL_Renderer *renderer;
	static SDL_Event* event;

private:
	int cnt = 0;
	bool is_Running;
	SDL_Window *window;

	int screenWidth;
	int screenHeight;
};

#endif /* Game.h */
