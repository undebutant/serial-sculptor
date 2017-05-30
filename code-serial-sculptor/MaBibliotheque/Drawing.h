#pragma once

#include "Graphic.h"


class Drawing
{
public:
	Drawing();
	~Drawing();

	void drawList(std::vector<Item> &listItemsToDraw, sf::RenderTarget &target);

private:

};
