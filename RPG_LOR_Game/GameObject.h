#pragma once
#include "Game.h"

class GameObject
{
private:
	int xpos;
	int ypos;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, dstRect;

public:
	GameObject(const char* texturesheet, int x, int y);
	~GameObject();

	//MOve functions
	void xIncrease();
	void xDecrease();
	void yIncrease();
	void yDecrease();


	void Update();
	void Render();
};

