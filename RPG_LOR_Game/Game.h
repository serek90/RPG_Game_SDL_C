#ifndef GAME_H
#define GAME_H
#include "SDL.h"
#include "SDL_image.h"

class Game
{
public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	
	void handleEvents();
	void update();
	void render();
	void clean();

	bool running() { return is_Running; }

private:
	int cnt = 0;
	bool is_Running;
	SDL_Renderer *renderer;
	SDL_Window *window;
};

#endif /* Game.h */