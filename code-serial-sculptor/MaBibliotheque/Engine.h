#pragma once

#include <vector>

#include "Item.h"


class Engine
{
public:
	Engine();
	~Engine();

	void launchGame();

	void addActiveItem(Item activeToAdd);
	void removeActiveItem(Item activeToAdd);

	void addSceneryItem(Item sceneryToAdd);
	void removeSceneryItem(Item activeToAdd);

	bool isTimeUp();
	void setTimer();

	void popupKeyAsked();
	void generateCloud();
	void destroyCloud();


private:
	std::vector<Item> listOfSceneryItems;
	std::vector<Item> listOfActiveItems;
};
