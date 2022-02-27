/*
*
* created by: serek90
*/
#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include "Game.h"

class TextureManager
{
private:

public:
	TextureManager();
	~TextureManager();

	static SDL_Texture* LoadTexture(const char* fileName);
	static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);
};

#endif /* TextureManager.h */