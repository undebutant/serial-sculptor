#include "TextureManagerSingleton.h"

using namespace std;
using namespace sf;

// Creating global instance singleton of the TextureManager
TextureManagerSingleton TextureManagerSingleton::m_instance = TextureManagerSingleton();


TextureManagerSingleton::TextureManagerSingleton()
{
	isFullscreen = false;
	loadAll();
	cout << "Texture Loaded" << endl;
}


TextureManagerSingleton::~TextureManagerSingleton()
{
	cout << "Texture Unloaded" << endl;
}


// Loading the font and various sprites needed ingame
void TextureManagerSingleton::loadAll() {
	Texture textureLoaded;

	int const number = 11;

	string pathToSprite = "sprite\\";
	string nameForSprite;
	string iteratorToString;
	string variousImages[number] = { "chaton.png", "mainMenuBackground.jpeg", "exitButton.png","hardButton.png","hardOnButton.png",
		"newGameButton.png" ,"gameBackground.jpeg","heartEmpty.png","heartFull.png","sculptor_left.png","sculptor_right.png" };
	
	// Loading the font used for the game
	if (!loadFont("font\\SilentReaction.ttf")) {
		cout << "Impossible de charger la police SilentReaction.ttf" << endl;
	}
	
	// Loading various images whose name are stored in the variousImages vector
	for (int i = 0; i < number; i++) {
		if (!loadTexture(pathToSprite + variousImages[i], variousImages[i])) {
			cout << "Impossible de charger la texture " << nameForSprite << endl;
		}
	}

	// Loading all cloud bosses known
	// TODO use xml to add / remove cloud bosses easily
	for (int i = 1; i <= 6; i++) {
		pathToSprite = "sprite\\";
		nameForSprite = "CloudBoss";
		iteratorToString = to_string(i);

		nameForSprite = nameForSprite + iteratorToString + ".png";
		pathToSprite = pathToSprite + nameForSprite;

		if (!loadTexture(pathToSprite, nameForSprite)) {
			cout << "Impossible de charger la texture " << nameForSprite << endl;
		}
	}

	// Loading all cloud easy known
	// TODO use xml to add / remove cloud easy easily
	for (int i = 1; i <= 10; i++) {
		pathToSprite = "sprite\\";
		nameForSprite = "CloudEasy";
		iteratorToString = to_string(i);

		nameForSprite = nameForSprite + iteratorToString + ".png";
		pathToSprite = pathToSprite + nameForSprite;

		if (!loadTexture(pathToSprite, nameForSprite)) {
			cout << "Impossible de charger la texture " << nameForSprite << endl;
		}
	}

	// Loading keys sprite used above clouds
	for (char i = 'A'; i <= 'Z'; i++) {
		pathToSprite = "sprite\\";
		nameForSprite = "";

		nameForSprite.push_back(i);
		nameForSprite = nameForSprite + ".png";
		pathToSprite = pathToSprite + nameForSprite;

		if (!loadTexture(pathToSprite, nameForSprite)) {
			cout << "Impossible de charger la texture " << nameForSprite << endl;
		}
	}
}



TextureManagerSingleton& TextureManagerSingleton::Instance()
{
	return m_instance;
}



Texture* TextureManagerSingleton::getTexture(string texture) {
	return &(textureLoaded[texture]);
}


Font TextureManagerSingleton::getFont() {
	return fontLoaded;
}



int TextureManagerSingleton::getHeight() {
	return height;
}


void TextureManagerSingleton::setHeight(int newHeight) {
	height = newHeight;
	heightsaved = newHeight;
}



int TextureManagerSingleton::getWidth() {
	return width;
}


void TextureManagerSingleton::setWidth(int newWidth) {
	width = newWidth;
	widthsaved = newWidth;
}



bool TextureManagerSingleton::getFullscreen() {
	return isFullscreen;
}


void TextureManagerSingleton::setFullscreen(int newHeight, int newWidth) {
	height = newHeight;
	width = newWidth;

	isFullscreen = true;
}


void TextureManagerSingleton::setFullscreen(bool isFull) {
	height = heightsaved;
	width = widthsaved;

	isFullscreen = false;
}



// Loading a specific texture in memory with the following name, given the path
bool TextureManagerSingleton::loadTexture(string pathToTexture, string nameToStore) {
	Texture newTexture;

	if (!newTexture.loadFromFile(pathToTexture)) {
		return false;
	}
	else {
		textureLoaded[nameToStore] = newTexture;
		return true;
	}
}


// Loading a specific font in memory given the path
bool TextureManagerSingleton::loadFont(string pathToFont) {
	Font newFont;

	if (!newFont.loadFromFile(pathToFont)) {
		return false;
	}
	else {
		fontLoaded = newFont;
		return true;
	}
}
