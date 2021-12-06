#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include "Game.h"

class TextureManager
{
private:

public:
	TextureManager();
	~TextureManager();

	static SDL_Texture* LoadTexture(const char* fileName, SDL_Renderer* renderer);
};

#endif /* TextureManager.h */