#include "Map.h"
#include "TextureManager.h"


Map::Map()
{
	dirt = TextureManager::LoadTexture("graphics/dirt.png");
	grass = TextureManager::LoadTexture("graphics/grass.png");
	water = TextureManager::LoadTexture("graphics/water.png");

	LoadMap();

	src.x = src.y = 0;
	src.w = dst.w = 32;
	src.h = dst.h = 32;

	dst.x = dst.y = 0;
}

Map::~Map()
{

}

void Map::LoadMap() //add array
{
	//for (int row = 0; row < map_row; row++)
	{
		//for (int column = 0; column < map_row; column++);
	}

}

void Map::Draw()
{
	int type = 0;

	for (int row = 0; row < map_row; row++)
	{
		for (int column = 0; column < map_row; column++)
		{
			type = map[row][column];

			dst.x = column * 32;
			dst.y = row * 32;

			switch (type)
			{
			case 0:
				TextureManager::Draw(water, src, dst);
				//SDL_RenderCopy(Game::renderer, water, NULL, &dst);
				break;

			case 1:
				TextureManager::Draw(grass, src, dst);
				break;

			case 2:
				TextureManager::Draw(dirt, src, dst);
				break;

			default:
				break;
			}
		}
	} 
}
