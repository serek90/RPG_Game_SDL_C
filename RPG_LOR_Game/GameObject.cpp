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
	SDL_DestroyTexture(objTexture);
	std::cout << "Game Object destructor" << std::endl;
}

void GameObject::Update()
{

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

int GameObject::getX()
{
	return xpos;
}

int GameObject::getY()
{
	return ypos;
}

int GameObject::getXsize()
{
	return xSize;
}

int GameObject::getYSize()
{
	return ySize;
}

void GameObject::setXsize(int size)
{
	//Update
}

void GameObject::setYsize(int size)
{
	//Update
}

/* Collision detection */
uint8_t GameObject::Collision(GameObject *object)
{
	int x1_obj = object->getX();
	int x2_obj = object->getXsize() + object->getX();
	int y1_obj = object->getY();
	int y2_obj = object->getYSize() + object->getY();

	int x1_col = xpos;
	int x2_col = xpos + xSize;
	int y1_col = ypos;
	int y2_col = ypos + ySize;

	int xCheck = 0;
	int yCheck = 0;

	if ((x1_obj >= x1_col) && (x1_obj <= x2_col))
		xCheck = 1;

	if ((x2_obj >= x1_col) && (x2_obj <= x2_col))
		xCheck = 1;

	if ((y1_obj >= y1_col) && (y1_obj <= y2_col))
		yCheck = 1;

	if ((y2_obj >= y1_col) && (y2_obj <= y2_col))
		yCheck = 1;

	if (xCheck && yCheck)
	{
		std::cout << "BIP BIP collision " << std::endl;
		return 1;
	}
	return 0;

}
