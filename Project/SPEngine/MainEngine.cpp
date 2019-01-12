#include "MainEngine.h"

#include <iostream>

SDL_Renderer* MainEngine::RENDERER = nullptr;

MainEngine::MainEngine()
{
}

MainEngine::~MainEngine()
{
}

void MainEngine::init(const char * title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		this->window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		if (window != 0)
		{
			std::cout << "Window Created\n";
		}

		RENDERER = SDL_CreateRenderer(window, -1, 0);
		if (RENDERER != 0)
		{
			SDL_SetRenderDrawColor(RENDERER, 255, 255, 255, 255);
			std::cout << "Renderer Created\n";
		}

		this->engine_running = true;
	}
	else
	{
		this->engine_running = false;
	}

	player = new WorldObject("../../Sprites/Knight/knight-frame1.png", 0, 0);
	map = new WorldMap();
}

void MainEngine::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		this->engine_running = false;
		break;
	default:
		break;
	}
}

void MainEngine::update()
{
	player->update();
}

void MainEngine::render()
{
	SDL_RenderClear(RENDERER);

	// render here
	map->render();
	player->render();

	SDL_RenderPresent(RENDERER);
}

void MainEngine::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(RENDERER);
	SDL_Quit();

	std::cout << "Game Cleaned\n";
}

bool MainEngine::running()
{
	return engine_running;
}
