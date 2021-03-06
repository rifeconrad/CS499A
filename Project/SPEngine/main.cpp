#include <iostream>
#include <SDL.h>

#include "MainEngine.h"

int main(int argc, char* argv[])
{
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	// creates, initializes, and begins running the engine
	MainEngine* engine = new MainEngine("SPEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);

	while (engine->running())
	{
		// time at frame start
		frameStart = SDL_GetTicks();

		// engine logic
		engine->handleEvents();
		engine->update();
		engine->render();

		// how long did the frame take to perform all actions?
		frameTime = SDL_GetTicks() - frameStart;

		// if we are going too fast, delay frame speed
		if (frameDelay > frameTime)
			SDL_Delay(frameDelay - frameTime);

	}

	engine->clean();

	delete engine;

	return 0;
}