#include "WorldObject.h"

#include "TextureManager.h"

WorldObject::WorldObject(const char * texture_path, int x, int y)
{
	this->texture = TextureManager::New(texture_path);
	this->x = x;
	this->y = y;
}

WorldObject::~WorldObject()
{
}
#include <iostream>
void WorldObject::update()
{
	// perform actions
	x++;
	y++;

	src.h = 90;
	src.w = 80;
	src.x = 0;
	src.y = 0;

	dst.x = x;
	dst.y = y;
	dst.w = src.w * 2;
	dst.h = src.h * 2;
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
