#pragma once

#include "MainEngine.h"

#include <vector>

class WorldMap
{
public:
	WorldMap();
	~WorldMap();

	virtual void loadMap(int map[20][25]);

	virtual void update();
	virtual void render();

	virtual void addTexture(SDL_Texture* texture);
	virtual void addLevel(int** level);

protected:
	SDL_Rect src;
	SDL_Rect dst;

	std::vector<SDL_Texture*> textures;
	std::vector<int**> levels;

	/*
	SDL_Texture* dirt;
	SDL_Texture* grass;
	SDL_Texture* water;
	*/

	int map[20][25];
};

