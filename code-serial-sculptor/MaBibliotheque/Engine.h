#pragma once

#include <vector>
#include <memory>
#include <SFML/Audio.hpp>
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
	Engine(bool setHard);
	~Engine();

	void init();

	void setVagueTitleFullScreen();
	void setVagueTitleCorner();

	void launchMainMenu();
	void drawMainMenu(sf::RenderWindow &renderer);

	void newGame();
	void endGame();

	void createNewCloud(int cloudToCreate);
	void createNewRandomEasy();
	void deleteCloudsDone();
	void deleteCloudsOld();
	
	void deleteHudItem(int indexOfHudItem);

	std::unique_ptr<SceneryItem> createNewSceneryItem(int sceneryItemToCreate);
	void destroySceneryItem(int indexOfSceneryItem);

	bool isHPLost(bool isCloudRight, bool isBoss, int posXcloud);
	void update(float time);
	void drawAllInGame(sf::RenderWindow &renderer);
	
	void keyPressed(sf::Keyboard::Key);

	void resetValue();

	void setHighScore(int tab[4]);

	void getHighScore(int tab[4]);

private:
	

	std::vector<int> topScores;

	sf::Music *musicBadPtr;

	sf::Text menuTitle;
	sf::Text vagueTitle;
	sf::Text failTitle;
	sf::Font fontLoaded;
	
	bool isGameLaunched;
	bool isRight;
	bool gameEnded;

	bool hardMod;

	int vague;
	int phase; // 0 phase easy, 1 phase boss, 2 phase pause
	int numberOfSpawnedClouds;
	int numberOfSpawnedBoss;

	float timeUntilNextSpawn;

	Sculptor sculptor;

	std::vector<std::unique_ptr<Cloud>> listOfClouds;
	std::vector<std::unique_ptr<Cloud>> listOfOldClouds;
	std::vector<std::unique_ptr<SceneryItem>> listOfHUDItems;
	std::vector<std::unique_ptr<SceneryItem>> listOfBackgroundItems;
	std::vector<std::unique_ptr<SceneryItem>> listOfBackgroundItemsMainMenu;
};
