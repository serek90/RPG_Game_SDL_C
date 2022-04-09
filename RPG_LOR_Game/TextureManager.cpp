#include "TextureManager.h"
#include <iostream>

SDL_Texture* TextureManager::LoadTexture(const char* fileName)
{
	SDL_Surface* tmpSurface = IMG_Load(fileName);
	if (!tmpSurface)
	{
		std::cout << "Surface creation FAILED!" << std::endl;
		std::cout << "There is no graphic or zlib.dll or libpng.dll is mising" << std::endl;
	}
	SDL_Texture * tmpText = SDL_CreateTextureFromSurface(Game::renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);

	return tmpText;
}

void TextureManager::Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest)
{
	SDL_RenderCopy(Game::renderer, tex, /*&src*/ NULL, &dest);
}
