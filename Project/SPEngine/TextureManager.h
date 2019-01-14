#pragma once

#include "MainEngine.h"

class TextureManager
{
public:
	TextureManager();
	~TextureManager();

	static std::pair<SDL_Texture*, SDL_Surface*> New(const char * filename);
	static void Draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dst);
};

