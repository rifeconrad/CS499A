#pragma once

#include "MainEngine.h"
#include "WorldObjectManager.h"

class WorldObject : public WorldObjectManager
{
public:
	WorldObject(const char* texture_path, int x, int y, int pixel_height, int pixel_width);
	~WorldObject();

	virtual void update();
	virtual void render();

	virtual void setSrc(int width, int height);
	virtual void setDst(int width, int height);

protected:
	// world object world position
	int x;
	int y;

	// texture and renderer for world object
	SDL_Texture* texture;
	SDL_Surface* surface;

	SDL_Rect src; // the part of the texture to be drawn
	SDL_Rect dst; // the part of the texture to be drawn on the screen
};

