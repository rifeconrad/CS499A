#pragma once

#include <vector>

class WorldMap;
class WorldMapManager
{
public:
	WorldMapManager();
	WorldMapManager(WorldMapManager* map);
	~WorldMapManager();

	virtual void update();
	virtual void render();

	// set the map as static or dynamic
	virtual void isStaticMap();
	virtual void isDynamicMap();

	// change the map texture
	virtual void nextMap();
	virtual void previousMap();
	virtual void chooseMap(int map);
	virtual void addMap(WorldMapManager* map);

	virtual int getNumberOfMaps();

	virtual int getCurrentMap() { return current_map_to_manage; }

protected:

private:
	// the maps are ever-changing, so
	// this will point to our current map
	static int current_map_to_manage;

	// holds all WorldMap objects (WorldMap
	// inherits WorldMapManager)
	static std::vector<WorldMapManager*> maps;

	// there are two types of maps available:
	// - either the map will move with the character
	// - or the map will remain static as the character moves
	bool static_map;
};

