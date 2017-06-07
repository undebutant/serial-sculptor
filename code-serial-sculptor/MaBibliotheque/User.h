#pragma once

#include <SFML/Graphics.hpp>

#include "Item.h"
#include "SceneryItem.h"


class User : public Item
{
public:
	User();
	~User();

	void draw(sf::RenderTarget &target);

	void setPosition(float x, float y);
	sf::Vector2f getPosition();
	void setSize(float x, float y);
	sf::Vector2f getSize();

	void setSprite(std::string pathToSprite);

	void setHealth(int a);
	int getHealth();
	void incrHealth(int a);
	void decrHealth(int a);
	void update(float time);
	virtual bool isGameOver() = 0;

private:
	SceneryItem sprite;
	int health;
};
