#include "WorldObjectManager.h"



WorldObjectManager::WorldObjectManager() : Manager(this)
{
}

WorldObjectManager::~WorldObjectManager()
{
}

void WorldObjectManager::update()
{
	for (WorldObject* obj : children)
	{
		obj->update();
	}
}

void WorldObjectManager::render()
{
	for (WorldObject* obj : children)
	{
		obj->render();
	}
}

void WorldObjectManager::addChild(WorldObject* obj)
{
	this->children.push_back(obj);
}
