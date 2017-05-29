#pragma once
#include "Item.h"
#include <SFML/Graphics.hpp>
class User : public Item
{
public:
	void draw(sf::RenderTarget &target);
	void incrHealth(int a);
	void decrHealth(int a);
	int getHealth();
	void setHealth(int a);
	virtual bool isDead() = 0;
	User();
	~User();
private:
	int health;
	sf::RectangleShape shape;
};

