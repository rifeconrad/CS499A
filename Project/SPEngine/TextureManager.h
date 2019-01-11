#pragma once

#include "MainEngine.h"

class TextureManager
{
public:
	TextureManager();
	~TextureManager();

	static SDL_Texture * New(const char * filename, SDL_Renderer * renderer);
};

