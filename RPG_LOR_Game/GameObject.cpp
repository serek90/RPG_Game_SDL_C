#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* texturesheet, SDL_Renderer* ren, int x, int y) : renderer(ren), xpos(x), ypos(y)
{
	objTexture = TextureManager::LoadTexture(texturesheet, ren);
}

GameObject::~GameObject()
{

}

void GameObject::Update()
{
	xpos++;
	ypos++;

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
	SDL_RenderCopy(renderer, objTexture, NULL, &dstRect); //for now it must be nullptr, 
}
