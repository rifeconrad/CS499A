#include "TextureManager.h"

TextureManager::TextureManager()
{
}


TextureManager::~TextureManager()
{
}

SDL_Texture * TextureManager::New(const char * filename)
{
	SDL_Surface* tmpSurface = IMG_Load(filename);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(MainEngine::RENDERER, tmpSurface);
	SDL_FreeSurface(tmpSurface);

	return texture;
}

void TextureManager::Draw(SDL_Texture * texture, SDL_Rect src, SDL_Rect dst)
{
	SDL_RenderCopy(MainEngine::RENDERER, texture, &src, &dst);
}
