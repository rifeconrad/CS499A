#include "Manager.h"

std::vector<Manager*> Manager::managers;

Manager::Manager()
{
}

Manager::Manager(Manager* manager)
{
	this->managers.push_back(manager);
}

Manager::~Manager()
{
}

void Manager::update()
{
	for (Manager* m : this->managers)
	{
		m->update();
	}
}

void Manager::render()
{
	for (Manager* m : this->managers)
	{
		m->render();
	}
}
