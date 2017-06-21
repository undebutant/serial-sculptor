#pragma once

#include <iostream>
#include <map>
#include <SFML/Graphics.hpp>






namespace TextureManager {
	bool loadAll();
	sf::Texture* getTexture(std::string texture);
	sf::Font getFont();
	int getHeight();
	int getWidth();
	void setHeight(int newHeight);
	void setWidth(int newWidth);
}
