#pragma once

#include "MainEngine.h"
#include "WorldMapManager.h"

#include <vector>

class WorldMap : public WorldMapManager
{
public:
	WorldMap();
	WorldMap(std::vector<std::vector<int>> map);
	~WorldMap();

	virtual void loadMap(std::vector<std::vector<int> > map);

	virtual void update();
	virtual void render();

	virtual void addTexture(const char* filename);

protected:
	SDL_Rect src;
	SDL_Rect dst;

	std::vector<SDL_Texture*> textures;
	std::vector<SDL_Surface*> surfaces;
	std::vector<std::vector<int>> map; // a vector of multiple maps (vector of multi-dimensional arrays)
};

