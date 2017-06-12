#pragma once
#include <iostream>
#include <map>
#include <SFML/Graphics.hpp>


static std::map<std::string, sf::Texture> textureLoaded;
static sf::Font fontLoaded;


bool loadTexture(std::string pathToTexture, std::string nameToStore);

bool loadFont(std::string pathToFont);

namespace TextureManager {
	bool loadAll();
	sf::Texture* getTexture(std::string texture);
}



