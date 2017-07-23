#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>



class TextureManagerSingleton
{
public:
	static TextureManagerSingleton& Instance();

	sf::Texture* getTexture(std::string texture);
	sf::Font getFont();

	int getHeight();
	void setHeight(int newHeight);

	int getWidth();
	void setWidth(int newWidth);

	bool getFullscreen();
	void setFullscreen(int newHeight,int newWidth);
	void setFullscreen(bool isFull);

private:
	bool isFullscreen;
	bool loadTexture(std::string pathToTexture, std::string nameToStore);
	bool loadFont(std::string pathToFont);

	int height;
	int width;
	int heightsaved;									// Last height used before fullscreen toggled on
	int widthsaved;										// Last width used before fullscreen toggled on
	
	static TextureManagerSingleton m_instance;

	sf::Font fontLoaded;

	std::map<std::string, sf::Texture> textureLoaded;	// Map between the name given to a texture and the pointer to the loaded texture in RAM
	

	TextureManagerSingleton();
	~TextureManagerSingleton();

	void loadAll();
};

