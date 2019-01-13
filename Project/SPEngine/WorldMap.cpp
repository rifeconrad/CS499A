#include "WorldMap.h"

#include "TextureManager.h"

WorldMap::WorldMap()
{
}
#include <iostream>
WorldMap::WorldMap(std::vector<std::vector<int>> map, int map_id) : WorldMapManager(this)
{
	this->map_id = map_id;
	std::cerr << "Added map\n";
	this->map = map;

	src.x = 0;
	src.y = 0;

	src.w = 32;
	src.h = 32;

	dst.w = 32;
	dst.h = 32;

	dst.x = 0;
	dst.y = 0;
}


WorldMap::~WorldMap()
{
}

void WorldMap::loadMap(std::vector<std::vector<int> > map)
{

}
void WorldMap::update()
{
}
#include <iostream>
void WorldMap::render()
{
	//std::cerr << "Verify map id: " << this->map_id << "\n";
	int type = 0;
	for (int row = 0; row < map.size(); row++)
	{
		for (int col = 0; col < map[row].size(); col++)
		{
			type = this->map[row][col];

			this->dst.x = col * this->src.w;
			this->dst.y = row * this->src.h;
			TextureManager::Draw(this->textures[type], this->src, this->dst);
		}
	}
}

void WorldMap::addTexture(SDL_Texture* texture)
{
	this->textures.push_back(texture);
}

