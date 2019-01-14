#include "WorldObjectManager.h"

std::vector<WorldObjectManager*> WorldObjectManager::children;

WorldObjectManager::WorldObjectManager()
{
}

WorldObjectManager::WorldObjectManager(WorldObjectManager* obj)
{
	this->children.push_back(obj);
}

WorldObjectManager::~WorldObjectManager()
{
}

void WorldObjectManager::update()
{
	for (WorldObjectManager* obj : children)
	{
		obj->update();
	}
}

void WorldObjectManager::render()
{
	for (WorldObjectManager* obj : children)
	{
		obj->render();
	}
}

void WorldObjectManager::addChild(WorldObjectManager* obj)
{
	this->children.push_back(obj);
}
