#pragma once
#include <SFML/Graphics.hpp>
class Item
{
public:
	virtual void draw(sf::RenderTarget &target) = 0;
	Item();
	~Item();
};

