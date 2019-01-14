#include "WorldObject.h"

#include "TextureManager.h"

#include <iostream>

WorldObject::WorldObject(const char * texture_path, int x, int y, int pixel_height, int pixel_width) : WorldObjectManager(this)
{
	std::cerr << "Object added\n";
	std::pair<SDL_Texture*, SDL_Surface*> img = TextureManager::New(texture_path);

	this->texture = img.first;
	this->surface = img.second;

	this->x = x;
	this->y = y;

	this->dst.x = this->dst.y = 0;
	this->src.x = this->src.y = 0;
	this->dst.h = this->src.h = pixel_height;
	this->src.w = this->dst.w = pixel_width;
}

WorldObject::~WorldObject()
{
}

void WorldObject::update()
{
}

void WorldObject::render()
{
	TextureManager::Draw(this->texture, this->src, this->dst);
}

void WorldObject::setSrc(int width, int height)
{
	this->src.w = width;
	this->src.h = height;
}

void WorldObject::setDst(int width, int height)
{
	this->dst.w = width;
	this->dst.h = height;
}
