#pragma once
#include "Item.h"
#include <SFML/Graphics.hpp>
class BaseItem : public Item
{
public:
	void draw(sf::RenderTarget &target);
	BaseItem();
	~BaseItem();
private:
	sf::RectangleShape shape;
};

