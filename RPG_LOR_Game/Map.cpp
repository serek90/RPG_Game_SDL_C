#include "Map.h"
#include "TextureManager.h"


Map::Map()
{
	dirt = TextureManager::LoadTexture("graphics/dirt.png");
	grass = TextureManager::LoadTexture("graphics/grass.png");
	water = TextureManager::LoadTexture("graphics/water.png");
	tree = TextureManager::LoadTexture("graphics/tree.png");

	LoadMap();

	src.x = src.y = 0;
	src.w = dst.w = 64;
	src.h = dst.h = 64;

	dst.x = dst.y = 0;
}

Map::~Map()
{
	SDL_DestroyTexture(dirt);
	SDL_DestroyTexture(grass);
	SDL_DestroyTexture(water);
	SDL_DestroyTexture(tree);
}

void Map::LoadMap() //add array
{

	char c;
	int row = 0, column = 0;
	std::ifstream infile("resources/map_basic.txt");


	std::string line;
	while (infile >> c)
	{
		if (c == ',')continue;

		map[row][column] = c;

		column++;
		if (column >= map_column)
		{
			row++;
			column = 0;
		}

	}



}

void Map::Draw()
{
	char type;

	for (int row = 0; row < map_row; row++)
	{
		for (int column = 0; column < map_column; column++)
		{
			type = map[row][column];

			dst.x = column * 64;
			dst.y = row * 64;

			switch (type)
			{
			case '0':
				TextureManager::Draw(water, src, dst);
				break;

			case '1':
				TextureManager::Draw(grass, src, dst);
				break;

			case '2':
				TextureManager::Draw(dirt, src, dst);
				break;

			case '3':
				TextureManager::Draw(tree, src, dst);
				break;

			case '4':
				TextureManager::Draw(snow, src, dst);
				break;

			default:
				break;
			}
		}
	} 
}
