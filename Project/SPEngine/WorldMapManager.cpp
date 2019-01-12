#include "WorldMapManager.h"

#include <iostream>

WorldMapManager::WorldMapManager() : Manager(this)
{
	this->current_map = 0;
	this->static_map = true;
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
		this->maps[this->current_map]->update();
}

void WorldMapManager::render()
{
	if (!this->maps.empty())
		this->maps[this->current_map]->render();
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
	if (this->current_map + 1 <= this->maps.size() - 1)
		this->current_map++;
	else
		std::cerr << "There is no further map.\n";
}

void WorldMapManager::previousMap()
{
	if (this->current_map - 1 >= 0)
		this->current_map--;
	else
		std::cerr << "There is no further map.\n";
}

void WorldMapManager::chooseMap(int map)
{
	if (map > 0 && map <= this->maps.size() - 1)
		this->current_map = map;
	else
		std::cerr << "That map location does not exist.\n";
}

void WorldMapManager::addMap(WorldMap * map)
{
	this->maps.push_back(map);
}
