#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>


class Item
{
public:
	Item();
	~Item();

	virtual void draw(sf::RenderTarget &target) = 0;
	virtual void update(float time) = 0;
};
