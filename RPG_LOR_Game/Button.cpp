#include "Button.h"


Button::Button(const char* texture_s, std::string texture_s_click, int x, int y, int x_s, int y_s)
{
	x_size = x_s > 0 ? x_s : 0;
	y_size = y_s > 0 ? y_s : 0;
	x_position = x > 0 ? x : 0; 
	y_position = y > 0 ? y : 0;
	sdl_rect_dst.x = x;
	sdl_rect_dst.y = y;
	sdl_rect_dst.w = x_s;
	sdl_rect_dst.h = y_s;
	texture = TextureManager::LoadTexture(texture_s);
	texture_click = std::move(texture_s_click);
}

void Button::render() 
{
	SDL_RenderCopy(Game::renderer, texture, NULL, &sdl_rect_dst);
}
bool Button::click_check(int click_x, int click_y) 
{
	if (click_x > x_position
		&& click_x < (x_size + x_position)
		&& click_y > y_position
		&& click_y < (y_size + y_position)
		)
	{
		texture = TextureManager::LoadTexture(texture_click.c_str());
		return true;
	}


	return false;
}
