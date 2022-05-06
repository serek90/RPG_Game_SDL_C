#pragma once
#include <stdint.h>
#include "TextureManager.h"


class Button
{
	unsigned int x_size;
	unsigned int y_size;
	unsigned int x_position;
	unsigned int y_position;
	SDL_Texture* texture;
	SDL_Texture* texture_click;


	Button();
public:
	Button(const char* textureSheet, int x, int y, int x_s, int y_s);
};

