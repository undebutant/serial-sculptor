#pragma once

#include "SceneryItem.h"
#include <SFML/Graphics.hpp>

class SceneryRectangleBasic : public SceneryItem
{
public:
	SceneryRectangleBasic();
	~SceneryRectangleBasic();
	void setNewColor(sf::Color newcolor);
private:
	
};

