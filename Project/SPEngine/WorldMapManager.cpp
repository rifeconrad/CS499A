#include "WorldMapManager.h"

#include <iostream>

int WorldMapManager::current_map_to_manage = 0;
std::vector<WorldMapManager*> WorldMapManager::maps;

WorldMapManager::WorldMapManager()
{
}

WorldMapManager::WorldMapManager(WorldMapManager* map)
{
	this->static_map = true;
	this->maps.push_back(map);
}


WorldMapManager::~WorldMapManager()
{
}

void WorldMapManager::update()
{
	// update is changing the position,
	// static maps do not need to change
	// their position
	if (this->static_map)
		return;

	if (!this->maps.empty())
		this->maps[this->current_map_to_manage]->update();
}

void WorldMapManager::render()
{
	if (!this->maps.empty())
		this->maps[this->current_map_to_manage]->render();
}

void WorldMapManager::isStaticMap()
{
	this->static_map = true;
}

void WorldMapManager::isDynamicMap()
{
	this->static_map = false;
}

void WorldMapManager::nextMap()
{
	if (this->current_map_to_manage + 1 <= this->maps.size() - 1)
		this->current_map_to_manage++;
	else
		std::cerr << "There is no further map.\n";
}

void WorldMapManager::previousMap()
{
	if (this->current_map_to_manage - 1 >= 0)
		this->current_map_to_manage--;
	else
		std::cerr << "There is no further map.\n";
}

void WorldMapManager::chooseMap(int map)
{
	if (map > 0 && map <= this->maps.size() - 1)
		this->current_map_to_manage = map;
	else
		std::cerr << "That map location does not exist.\n";
}

void WorldMapManager::addMap(WorldMapManager * map)
{
	this->maps.push_back(map);
}

int WorldMapManager::getNumberOfMaps()
{
	return this->maps.size();
}
