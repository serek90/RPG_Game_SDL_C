#include "Button.h"


Button::Button(const char* textureSheet, int x, int y, int x_s, int y_s) : x_size(x_s), y_size(y_s), x_position(x), y_position(y)
{
	texture = TextureManager::LoadTexture(textureSheet);
}
