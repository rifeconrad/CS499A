#pragma once
#include <SDL.h>
#include <SDL_image.h>

#include "Manager.h"

class Manager;
class MainEngine
{
public:
	MainEngine();
	MainEngine(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	~MainEngine();

	virtual void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	virtual void handleEvents();
	virtual void update();
	virtual void render();
	virtual void clean();

	virtual void setUp();

	virtual bool running();

	static SDL_Renderer* RENDERER;

protected:
	bool engine_running;
	SDL_Window* window;

	Manager* manager;
};

