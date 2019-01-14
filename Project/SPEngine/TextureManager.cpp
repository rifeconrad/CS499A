#include "TextureManager.h"

TextureManager::TextureManager()
{
}


TextureManager::~TextureManager()
{
}
#include <iostream>
std::pair<SDL_Texture*, SDL_Surface*> TextureManager::New(const char * filename)
{
	SDL_Surface* surface = IMG_Load(filename);
	if (surface == NULL)
		std::cerr << "Error: " << IMG_GetError() << "\n";

	SDL_Texture* texture = SDL_CreateTextureFromSurface(MainEngine::RENDERER, surface);

	if (texture == NULL)
		std::cerr << "Error: " << SDL_GetError() << "\n";

	SDL_FreeSurface(surface);

	std::pair<SDL_Texture*, SDL_Surface*> img(texture, surface);

	return img;
}

void TextureManager::Draw(SDL_Texture * texture, SDL_Rect src, SDL_Rect dst)
{
	SDL_RenderCopy(MainEngine::RENDERER, texture, &src, &dst);
}
