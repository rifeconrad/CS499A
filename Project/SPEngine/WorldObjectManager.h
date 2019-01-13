#pragma once

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
	WorldObjectManager(WorldObjectManager* obj);
	~WorldObjectManager();

	virtual void update();
	virtual void render();

	virtual void addChild(WorldObjectManager* obj);

protected:

private:
	static std::vector<WorldObjectManager*> children;
};

