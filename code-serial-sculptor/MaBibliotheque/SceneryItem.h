#pragma once


#include <SFML/Graphics.hpp>

#include "Item.h"


class SceneryItem : public Item
{
public:
	SceneryItem();
	~SceneryItem();

	void draw(sf::RenderTarget &target);

	void setPosition(float x, float y);
	sf::Vector2f getPosition();
	void setSize(float x, float y);
	sf::Vector2f getSize();

	void setSprite(std::string pathToSprite);

private:
	sf::RectangleShape shape;
	std::string pathToSprite;
};
