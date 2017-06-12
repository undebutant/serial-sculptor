#pragma once

#include <vector>
#include <memory>

#include "Item.h"
#include "Cloud.h"
#include "CloudEasy1.h"
#include "CloudBoss1.h"


class Engine
{
public:
	Engine();
	~Engine();

	void launchMainMenu();
	void drawMainMenu(sf::RenderWindow &renderer);

	void newGame();
	void endGame();

	bool loadTexture(string pathToTexture, string nameToStore);
	bool loadFont(string pathToFont);
	void loadAll();
	sf::Texture* getTexture(std::string texture);

	void createNewCloud(int cloudToCreate, bool isRightCloud);
	void deleteCloudsDone();

	//std::unique_ptr<HudItems> createNewHudItem(int hudToCreate);
	//void destroyHudItem(int indexOfHudItem);
	//std::unique_ptr<HudItems> getHudItem(int indexOfHudItem);

	std::unique_ptr<SceneryItem> createNewSceneryItem(int sceneryItemToCreate);
	void destroySceneryItem(int indexOfSceneryItem);

	void updateItems(float time);
	void drawAll(sf::RenderWindow &renderer);
	
	void keyPressed(sf::Keyboard::Key);


private:
	map<string, sf::Texture> textureLoaded;
	sf::Font fontLoaded;

	std::vector<std::unique_ptr<Cloud>> listOfClouds;
	//std::vector<std::unique_ptr<HudItems>> listOfHUDItems;
	std::vector<std::unique_ptr<SceneryItem>> listOfBackgroundItems;
};
