#pragma once
#include <SDL.h>
#include <SDL_image.h>

#include "TextureManager.h"

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

private:
	bool engine_running;
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Texture* playerTex;
};

