#pragma once


#include <SFML/Graphics.hpp>

#include "Item.h"
#include "monMain.h"


class SceneryItem : public Item
{
public:
	SceneryItem();
	~SceneryItem();


	void setTexture();
	void draw(sf::RenderTarget &target);
	void setPath(std::string newPath);
	void setPosition(float x, float y);
	void setColor(sf::Color newColor);
	sf::Vector2f getPosition();
	void setSize(float x, float y);
	sf::Vector2f getSize();

	void setSprite(std::string pathToSprite);

private:
	sf::RectangleShape shape;
	sf::Texture mytexture;
	std::string pathToSprite;
};
