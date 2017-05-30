#pragma once

#include <vector>

#include "Item.h"


class Engine
{
public:
	Engine();
	~Engine();

private:
	std::vector<Item> listOfExistingItem;
};
