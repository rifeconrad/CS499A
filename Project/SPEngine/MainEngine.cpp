#include "MainEngine.h"

#include <iostream>

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

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer != 0)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer Created\n";
		}

		this->engine_running = true;
	}
	else
	{
		this->engine_running = false;
	}

	playerTex = TextureManager::New("../../Sprites/Knight/knight-frame1.png", renderer);
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
}

void MainEngine::render()
{
	SDL_RenderClear(renderer);

	// render here
	// srcRect - part of rectangle to be drawn
	// dstRect - where to be drawn on screen
	SDL_RenderCopy(renderer, playerTex, NULL, NULL);

	SDL_RenderPresent(renderer);
}

void MainEngine::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

	std::cout << "Game Cleaned\n";
}

bool MainEngine::running()
{
	return engine_running;
}
