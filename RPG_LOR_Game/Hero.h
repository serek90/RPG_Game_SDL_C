#pragma once
#include "GameObject.h"

class Hero :
    public GameObject
{
public:
    void Move(SDL_Event event);
	Hero(const char* textureSheet, int X, int Y, int color) : GameObject(textureSheet, X, Y), color(color) {}
	~Hero();

private:

	int color;

};

