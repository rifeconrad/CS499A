#include "WorldObject.h"

#include "TextureManager.h"

WorldObject::WorldObject(const char * texture_path, int x, int y) : WorldObjectManager(this)
{
	this->texture = TextureManager::New(texture_path);
	this->x = x;
	this->y = y;
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
