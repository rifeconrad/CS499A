#pragma once

#include "WorldObject.h"
#include "Manager.h"

#include <vector>

/*********************************
* WorldObjectManager
* Updates and renders all world
* objects (children).
*********************************/
class WorldObject;
class WorldObjectManager : public Manager
{
public:
	WorldObjectManager();
	~WorldObjectManager();

	virtual void update();
	virtual void render();

	virtual void addChild(WorldObject* obj);

protected:
	std::vector<WorldObject*> children;
};

