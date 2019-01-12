#pragma once

#include "MainEngine.h"

class WorldMap
{
public:
	WorldMap();
	~WorldMap();

	virtual void loadMap(int map[20][25]);
	virtual void render();

private:

	SDL_Rect src;
	SDL_Rect dst;

	SDL_Texture* dirt;
	SDL_Texture* grass;
	SDL_Texture* water;

	int map[20][25];
};

