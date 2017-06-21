#pragma once

#include <vector>
#include <memory>
#include <SFML/Audio.hpp>
#include "Item.h"
#include "Cloud.h"
#include "Sculptor.h"
#include "SceneryRectangleBasic.h"
#include "SceneryItem.h"
#include "Config.h"



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
	

	std::unique_ptr<SceneryItem> createNewSceneryItem(int sceneryItemToCreate);
	void destroySceneryItem(int indexOfSceneryItem);

	bool isHPLost(bool isCloudRight, bool isBoss, int posXcloud);
	void update(float time);
	void drawAllInGame(sf::RenderWindow &renderer);
	
	void keyPressed(sf::Keyboard::Key);

	void resetValue();

	void setHighScore(int tab[4]);

	void getHighScore(int tab[4]);

	void setVectorOfConfig(std::vector<Config> newvectorOfConfig);

private:
	
	std::vector<Config> vectorOfConfig;

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
