#pragma once
#include <SFML/Graphics.hpp>
class TextureManagerSingleton
{
public:
	static TextureManagerSingleton& Instance();
	sf::Texture* getTexture(std::string texture);
	sf::Font getFont();
	int getHeight();
	int getWidth();
	void setHeight(int newHeight);
	void setWidth(int newWidth);
	void setFullscreen(int newHeight,int newWidth);
	void setFullscreen(bool isFull);
	bool getFullscreen();

private:
	
	static TextureManagerSingleton m_instance;
	std::map<std::string, sf::Texture> textureLoaded;
	sf::Font fontLoaded;
	int height;
	int width;
	int heightsaved;
	int widthsaved;
	bool isFullscreen;
	bool loadTexture(std::string pathToTexture, std::string nameToStore);
	bool loadFont(std::string pathToFont);
	void loadAll();
	TextureManagerSingleton();
	~TextureManagerSingleton();
};
