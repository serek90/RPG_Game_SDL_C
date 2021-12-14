#include "GameObject.h"
#include "TextureManager.h"
#include <iostream>

GameObject::GameObject(const char* texturesheet, int x, int y) : xpos(x), ypos(y)
{
	objTexture = TextureManager::LoadTexture(texturesheet);
	std::cout << "Game Object constructor call texture" << texturesheet << std::endl;
}

GameObject::~GameObject()
{

}

void GameObject::Update()
{
	//xpos++;
	//ypos++;

	srcRect.w = 32;
	srcRect.h = 32;
	srcRect.x = 0;
	srcRect.y = 0;

	dstRect.x = xpos;
	dstRect.y = ypos;
	dstRect.w = srcRect.w * 2;
	dstRect.h = srcRect.h * 2;
}

void GameObject::Render()
{
	SDL_RenderCopy(Game::renderer, objTexture, NULL, &dstRect); //for now it must be nullptr, 
}


void GameObject::xDecrease()
{
	xpos--;
}
void GameObject::xIncrease()
{
	xpos++;
}
void GameObject::yDecrease()
{
	ypos--;
}
void GameObject::yIncrease()
{
	ypos++;
}