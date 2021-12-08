#pragma once
#include "Game.h"

class GameObject
{
private:
	int xpos;
	int ypos;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, dstRect;
	SDL_Renderer* renderer;

public:
	GameObject(const char* texturesheet, SDL_Renderer* renderer, int x, int y);
	~GameObject();

	void Update();
	void Render();
};

