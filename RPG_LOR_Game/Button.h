#pragma once
#include <stdint.h>
#include <iostream>
#include "TextureManager.h"


class Button
{
	unsigned int x_size;
	unsigned int y_size;
	unsigned int x_position;
	unsigned int y_position;
	SDL_Texture* texture;
	std::string texture_click;
	SDL_Rect  sdl_rect_dst;

	Button();
public:
	Button(const char* texture,std::string texture_clicked, int x, int y, int x_s, int y_s);
	void render();
	bool click_check(int, int);
};

