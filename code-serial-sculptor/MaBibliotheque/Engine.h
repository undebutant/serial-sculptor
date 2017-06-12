#pragma once

#include <vector>
#include <memory>

#include "Item.h"
#include "Cloud.h"
#include "Sculptor.h"

#include "SceneryRectangleBasic.h"
#include "SceneryItem.h"

#include "CloudBoss1.h"
#include "CloudBoss2.h"
#include "CloudBoss3.h"
#include "CloudBoss4.h"
#include "CloudBoss5.h"
#include "CloudBoss6.h"
#include "CloudEasy1.h"
#include "CloudEasy2.h"
#include "CloudEasy3.h"
#include "CloudEasy4.h"
#include "CloudEasy5.h"
#include "CloudEasy6.h"
#include "CloudEasy7.h"
#include "CloudEasy8.h"
#include "CloudEasy9.h"
#include "CloudEasy10.h"


class Engine
{
public:
	Engine();
	~Engine();

	void launchMainMenu();
	void drawMainMenu(sf::RenderWindow &renderer);

	void newGame();
	void bossPhase();
	void endGame();

	bool loadTexture(string pathToTexture, string nameToStore);
	bool loadFont(string pathToFont);
	void loadAll();
	sf::Texture* getTexture(std::string texture);

	void createNewCloud(int cloudToCreate, bool isRightCloud);
	void deleteCloudsDone();
	void deleteCloudsOld();

	//std::unique_ptr<HudItems> createNewHudItem(int hudToCreate);
	//void destroyHudItem(int indexOfHudItem);
	//std::unique_ptr<HudItems> getHudItem(int indexOfHudItem);

	std::unique_ptr<SceneryItem> createNewSceneryItem(int sceneryItemToCreate);
	void destroySceneryItem(int indexOfSceneryItem);

	void updateItems(float time);
	void drawAllInGame(sf::RenderWindow &renderer);
	
	void keyPressed(sf::Keyboard::Key);


private:
	map<string, sf::Texture> textureLoaded;
	sf::Font fontLoaded;

	int numberOfSpawnedClouds;
	float timeUntilWaveEnd;

	std::vector<std::unique_ptr<Cloud>> listOfClouds;
	std::vector<std::unique_ptr<Cloud>> listOfOldClouds;
	//std::vector<std::unique_ptr<HudItems>> listOfHUDItems;
	std::vector<std::unique_ptr<SceneryItem>> listOfBackgroundItems;
};
