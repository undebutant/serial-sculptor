#pragma once

#include <vector>
#include <memory>
#include <assert.h>
#include <windows.h>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "Item.h"
#include "Cloud.h"
#include "Sculptor.h"
#include "SceneryRectangleBasic.h"
#include "SceneryItem.h"
#include "Config.h"
#include "Engine.h"
#include "TextureManagerSingleton.h"



class Engine
{
public:
	Engine(bool setHard);

	void init();

	void launchMainMenu();									// Main loop of the game
	void drawMainMenu(sf::RenderWindow &renderer);
	void updateMenu();

	void resetValue();
	void newGame();

	void keyPressed(sf::Keyboard::Key);

	void createNewCloud(int cloudToCreate, bool isBoss);
	void createNewRandomEasy();
	void deleteCloudsDone();

	bool isHPLost(bool isCloudRight, bool isBoss, int posXcloud);
	void update(float time);
	void drawAllInGame(sf::RenderWindow &renderer);

	void setVagueTitleFullScreen();
	void setVagueTitleCorner();

	void setVectorOfConfigEasy(std::vector<Config> newvectorOfConfigEasy);
	void setVectorOfConfigBoss(std::vector<Config> newvectorOfConfigBoss);

	void setHighScore(int tab[4]);
	void getHighScore(int tab[4]);

	void setIsHard();
	bool getIsHard();
	
private:
	bool drawSculptor;				// Allows clipping of the sculptor when losing life
	bool isGameLaunched;
	bool isRight;					// Defining if the next cloud to deal with is at our right, or left
	bool gameEnded;
	bool hardMode;

	int vague;
	int phase;						// 0 = easy cloud phase, 1 = boss phase, 2 = transition between waves
	int numberOfSpawnedClouds;
	int numberOfSpawnedBoss;

	float invulnerable;
	float timeUntilNextSpawn;
	
	sf::Music *musicBadPtr;
	sf::Font fontLoaded;
	sf::Text menuTitle;
	sf::Text vagueTitle;
	sf::Text failTitle;

	Sculptor sculptor;

	std::vector<int> topScores;

	std::vector<Config> vectorOfConfigEasy;
	std::vector<Config> vectorOfConfigBoss;

	std::vector<std::unique_ptr<Cloud>> listOfClouds;
	std::vector<std::unique_ptr<Cloud>> listOfOldClouds;

	std::vector<std::unique_ptr<SceneryItem>> listOfHUDItems;
	std::vector<std::unique_ptr<SceneryItem>> listOfBackgroundItems;
	std::vector<std::unique_ptr<SceneryItem>> listOfBackgroundItemsMainMenu;
};
