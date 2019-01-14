#pragma once

#include <vector>

/*********************************
* WorldObjectManager
* Updates and renders all world
* objects (children).
*********************************/
class WorldObject;
class WorldObjectManager
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

