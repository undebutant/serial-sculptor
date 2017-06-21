#include "TextureManager.h"
#include <iostream>
#include <SFML/Graphics.hpp>


static std::map<std::string, sf::Texture> textureLoaded;
static sf::Font fontLoaded;

static int height;
static int width;

bool loadTexture(std::string pathToTexture, std::string nameToStore) {
	sf::Texture newTexture;

	if (!newTexture.loadFromFile(pathToTexture)) {
		return false;
	}
	else {
		textureLoaded[nameToStore] = newTexture;
		return true;
	}
}


bool loadFont(std::string pathToFont) {
	sf::Font newFont;

	if (!newFont.loadFromFile(pathToFont)) {
		return false;
	}
	else {
		fontLoaded = newFont;
		return true;
	}
}


namespace TextureManager {
	bool loadAll() {
		if (!loadFont("font\\SilentReaction.ttf")) {
			std::cout << "Impossible de charger la police SilentReaction.ttf" << std::endl;
		}

		sf::Texture textureLoaded;

		std::string pathToSprite = "sprite\\";
		std::string nameForSprite;
		std::string iteratorToString;

		int const number = 9;
		std::string variousImages[number] = { "chaton.png", "mainMenuBackground.jpeg", "exitButton.png", "newGameButton.png" ,"gameBackground.jpeg","heartEmpty.png","heartFull.png","sculptor_left.png","sculptor_right.png" };

		for (int i = 0; i < number; i++) {
			if (!loadTexture(pathToSprite + variousImages[i], variousImages[i])) {
				std::cout << "Impossible de charger la texture " << nameForSprite << std::endl;
			}
		}

		for (int i = 1; i <= 6; i++) {
			pathToSprite = "sprite\\";
			nameForSprite = "CloudBoss";
			iteratorToString = std::to_string(i);

			nameForSprite = nameForSprite + iteratorToString + ".png";
			pathToSprite = pathToSprite + nameForSprite;

			if (!loadTexture(pathToSprite, nameForSprite)) {
				std::cout << "Impossible de charger la texture " << nameForSprite << std::endl;
			}
		}

		for (int i = 1; i <= 10; i++) {
			pathToSprite = "sprite\\";
			nameForSprite = "CloudEasy";
			iteratorToString = std::to_string(i);

			nameForSprite = nameForSprite + iteratorToString + ".png";
			pathToSprite = pathToSprite + nameForSprite;

			if (!loadTexture(pathToSprite, nameForSprite)) {
				std::cout << "Impossible de charger la texture " << nameForSprite << std::endl;
			}
		}

		for (char i = 'A'; i <= 'Z'; i++) {
			pathToSprite = "sprite\\";
			nameForSprite = "";

			nameForSprite.push_back(i);
			nameForSprite = nameForSprite + ".png";
			pathToSprite = pathToSprite + nameForSprite;

			if (!loadTexture(pathToSprite, nameForSprite)) {
				std::cout << "Impossible de charger la texture " << nameForSprite << std::endl;
			}
		}
		return true;
	}
	sf::Texture* getTexture(std::string texture) {
		return &(textureLoaded[texture]);
	}
	sf::Font getFont() {
		return fontLoaded;
	}


	int getHeight() {
		return height;
	}
	int getWidth() {
		return width;
	}
	void setHeight(int newHeight) {
		height = newHeight;
	}
	void setWidth(int newWidth) {
		width = newWidth;
	}

}