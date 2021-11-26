#include <stdio.h>
#include <stdlib.h>
#include "Game.h"

int main(int argc, char * argv[])
{
	Game* game = new Game;

	game->init("New title", 300, 300, 300, 300, false);

	while (game->running())
	{
		game->handleEvents();
		game->update();
		game->render();
	}
	game->clean();
	return 0;
}