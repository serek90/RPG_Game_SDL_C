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
	static const int ySize = 64;
	static const int xSize = 64;
	bool _isShowing;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, dstRect;

	int _defence;
	int _attack;

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
	void updateTexture(const char* texturesheet);

	/*GameObject */ int operator+(const GameObject&);
	int operator>(const GameObject&);
	void Update();
	void Render();
};

