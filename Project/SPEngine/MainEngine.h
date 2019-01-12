#pragma once
#include <SDL.h>
#include <SDL_image.h>

#include "TextureManager.h"
#include "WorldObject.h"
#include "WorldMap.h"

class WorldObject;
class WorldMap;
class MainEngine
{
public:
	MainEngine();
	~MainEngine();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void handleEvents();
	void update();
	void render();
	void clean();

	bool running();

	static SDL_Renderer* RENDERER;

private:
	bool engine_running;
	SDL_Window* window;
	WorldObject* player;
	WorldMap* map;
};

