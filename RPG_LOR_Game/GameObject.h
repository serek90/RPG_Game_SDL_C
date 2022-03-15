/*
*
* created by: serek90
*/
#pragma once
#include "Game.h"

class GameObject
{
protected:
	int xpos;
	int ypos;
	int ySize = 64;
	int xSize = 64;
	bool _isShowing;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, dstRect;

public:
	GameObject(const char* texturesheet, int x, int y) ;
	~GameObject();

	//Move functions
	void xIncrease();
	void xDecrease();
	void yIncrease();
	void yDecrease();

	int getX();
	int getY();

	int getXsize();
	int getYSize();
	void setXsize(int size);
	void setYsize(int size);

	uint8_t Collision(GameObject *object);
	bool isShowing() { return _isShowing;  }
	void stopShowing() { _isShowing = false; }

	void Update();
	void Render();
};

