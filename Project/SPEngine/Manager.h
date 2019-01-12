#pragma once

#include <vector>

class Manager
{
public:
	Manager();
	Manager(Manager* m);
	~Manager();

	virtual void update();
	virtual void render();

private:
	static std::vector<Manager*> managers;
};

