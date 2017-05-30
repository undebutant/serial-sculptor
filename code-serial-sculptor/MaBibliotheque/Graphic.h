#pragma once

#include "Engine.h"


class Graphic
{
public:
	Graphic();
	~Graphic();

	void initWindow(sf::RenderTarget &target, std::vector<Item> &listOfSceneryItems, std::vector<Item> &listOfActiveItems);

	void updateWindow(sf::RenderTarget &target, std::vector<Item> &listOfSceneryItems, std::vector<Item> &listOfActiveItems);
	void updateForInterruption(sf::RenderTarget &target, std::vector<Item> &listOfActiveItems);

private:

};
