#include "Engine.h"
#include "TextureManager.h"
#include <assert.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Config.h"

using namespace std;
using namespace sf;


Engine::Engine(bool setHard) : hardMod(setHard){

}

Engine::~Engine() {

}

void Engine::init() {
	invulnerable = 1;
	drawSculptor = true;
	srand((unsigned int)time(NULL));
	

	//Main Menu
	std::unique_ptr<SceneryItem> menuBackground = std::unique_ptr<SceneryItem>(new SceneryItem());
	menuBackground->setSize(1200, 600);

	std::unique_ptr<SceneryItem> newGameButton = std::unique_ptr<SceneryItem>(new SceneryItem());
	newGameButton->setSize(566, 80);

	std::unique_ptr<SceneryItem> exitButton = std::unique_ptr<SceneryItem>(new SceneryItem());
	exitButton->setSize(382, 80);

	
	menuBackground->setTexture("mainMenuBackground.jpeg");
	newGameButton->setTexture("newGameButton.png");
	exitButton->setTexture("exitButton.png");

	
	newGameButton->setPosition(150, 140);
	exitButton->setPosition(242, 260);

	listOfBackgroundItemsMainMenu.push_back(move(menuBackground));
	listOfBackgroundItemsMainMenu.push_back(move(newGameButton));
	listOfBackgroundItemsMainMenu.push_back(move(exitButton));


	menuTitle.setString(L"Serial Sculptor");
	menuTitle.setCharacterSize(70);
	menuTitle.setFillColor(Color(255, 255, 255, 255));
	fontLoaded = TextureManager::getFont();
	menuTitle.setFont(fontLoaded);
	menuTitle.setStyle(Text::Bold);

	menuTitle.setPosition(210, 30);

	//Game layout

	std::unique_ptr<SceneryItem> gameBackground = std::unique_ptr<SceneryItem>(new SceneryItem());
	gameBackground->setSize(1200, 600);
	gameBackground->setTexture("gameBackground.jpeg");
	listOfBackgroundItems.push_back(move(gameBackground));

	//HUD layout

	vagueTitle.setString(L"Vague : 1");
	vagueTitle.setCharacterSize(70);
	vagueTitle.setFillColor(Color(255, 0, 0));
	vagueTitle.setFont(fontLoaded);
	vagueTitle.setStyle(Text::Bold);

	vagueTitle.setPosition(800, 30);

	

	failTitle.setString(L"YOU LOST");
	failTitle.setCharacterSize(200);
	failTitle.setFillColor(Color(255, 0, 0));
	failTitle.setFont(fontLoaded);
	failTitle.setStyle(Text::Bold);

	failTitle.setPosition(0, 200);

	std::unique_ptr<SceneryItem> heartContainer1 = std::unique_ptr<SceneryItem>(new SceneryItem());
	std::unique_ptr<SceneryItem> heartContainer2 = std::unique_ptr<SceneryItem>(new SceneryItem());
	std::unique_ptr<SceneryItem> heartContainer3 = std::unique_ptr<SceneryItem>(new SceneryItem());

	heartContainer1->setSize(100, 100);
	heartContainer2->setSize(100, 100);
	heartContainer3->setSize(100, 100);

	heartContainer1->setTexture("heartEmpty.png");
	heartContainer2->setTexture("heartEmpty.png");
	heartContainer3->setTexture("heartEmpty.png");

	heartContainer1->setPosition(20, 20);
	heartContainer2->setPosition(140, 20);
	heartContainer3->setPosition(260, 20);

	listOfHUDItems.push_back(move(heartContainer1));
	listOfHUDItems.push_back(move(heartContainer2));
	listOfHUDItems.push_back(move(heartContainer3));

	std::unique_ptr<SceneryItem> heartContainerFull1 = std::unique_ptr<SceneryItem>(new SceneryItem());
	std::unique_ptr<SceneryItem> heartContainerFull2 = std::unique_ptr<SceneryItem>(new SceneryItem());
	std::unique_ptr<SceneryItem> heartContainerFull3 = std::unique_ptr<SceneryItem>(new SceneryItem());

	heartContainerFull1->setSize(100, 100);
	heartContainerFull2->setSize(100, 100);
	heartContainerFull3->setSize(100, 100);

	heartContainerFull1->setTexture("heartFull.png");
	heartContainerFull2->setTexture("heartFull.png");
	heartContainerFull3->setTexture("heartFull.png");

	heartContainerFull1->setPosition(20, 20);
	heartContainerFull2->setPosition(140, 20);
	heartContainerFull3->setPosition(260, 20);

	listOfHUDItems.push_back(move(heartContainerFull1));
	listOfHUDItems.push_back(move(heartContainerFull2));
	listOfHUDItems.push_back(move(heartContainerFull3));
}

void Engine::setVagueTitleFullScreen() {
	vagueTitle.setCharacterSize(200);
	vagueTitle.setPosition(200, 200);
}

void Engine::setVagueTitleCorner() {
	vagueTitle.setCharacterSize(70);
	vagueTitle.setPosition(800, 30);
}

void Engine::launchMainMenu() {
	TextureManager::loadAll();
	
	sf::Music musicBad;

	if (!musicBad.openFromFile("music\\bad.wav"))
		assert(false); // erreur
	musicBad.setLoop(false);
	musicBadPtr = &musicBad;

	sf::Music music;
	if (!music.openFromFile("music\\mainmenu-loop.wav"))
		assert(false); // erreur
	music.play();
	music.setLoop(true);

	isGameLaunched = false;
	ContextSettings settings;
	settings.antialiasingLevel = 8;
	
	RenderWindow window(sf::VideoMode(1200, 600), "Serial sculptor", Style::Titlebar | Style::Close, settings);

	Clock clock;
	Event event;
	
	init();

	int lastphase = 0;
	bool lastisGameLaunched = false;
	bool lastGameEnded = false;

	while (window.isOpen()) {
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::KeyPressed) {
				if (event.key.code == Keyboard::Escape) {
					window.close();
				}
				
				if (isGameLaunched) {
					keyPressed(event.key.code);
				}
			}

			
			// In other cases
			else {
				if (event.type == Event::MouseButtonPressed) {
					if (!isGameLaunched) {
						if (event.mouseButton.x > 150 && event.mouseButton.x < 716 && event.mouseButton.y > 140 && event.mouseButton.y < 220) {
							if (!music.openFromFile("music\\phase0-loop.wav"))
								assert(false); // erreur
							music.play();
							music.setLoop(true);
							newGame();

						}
						if (event.mouseButton.x > 242 && event.mouseButton.x < 624 && event.mouseButton.y > 260 && event.mouseButton.y < 340) {
							window.close();
						}
					}
				}
			}
		}
		window.clear();
		
		float time = clock.restart().asSeconds();

		
		if (isGameLaunched) {
			lastisGameLaunched = isGameLaunched;
			if (gameEnded) {
				if (lastGameEnded != gameEnded) {
					lastGameEnded = gameEnded;
					if (!music.openFromFile("music\\fail.wav"))
						assert(false); // erreur
					music.play();
					music.setLoop(false);
				}
			}
			else {
				if (lastphase != phase) {
					lastphase = phase;
					if (phase == 0) {

						if (!music.openFromFile("music\\phase0-loop.wav"))
							assert(false); // erreur
						music.play();
						music.setLoop(true);

					}
					else if (phase == 1) {

						if (!music.openFromFile("music\\phase1-loop.wav"))
							assert(false); // erreur
						music.play();
						music.setLoop(true);

					}
					else if (phase == 2) {

						if (!music.openFromFile("music\\phase2.wav"))
							assert(false); // erreur
						music.play();
						music.setLoop(false);

					}



				}
			}
			
			
			update(time);
			drawAllInGame(window);
		}
		else {
			if (lastisGameLaunched != isGameLaunched) {
				if (!music.openFromFile("music\\mainmenu-loop.wav"))
					assert(false); // erreur
				music.play();
				music.setLoop(true);
				lastisGameLaunched = isGameLaunched;
				lastGameEnded = false;
			}
			drawMainMenu(window);
		}
		

		window.display();
	}
}

void Engine::drawMainMenu(RenderWindow &renderer) {
	for (int i = 0; i < ((int)listOfBackgroundItemsMainMenu.size()); i++) {
		listOfBackgroundItemsMainMenu[i]->draw(renderer);
	}

	renderer.draw(menuTitle);

	if (!topScores.empty()) {
		sf::Text topScoreTitle;
		topScoreTitle.setString(L"Top Score");
		topScoreTitle.setCharacterSize(70);
		topScoreTitle.setFillColor(Color(255, 0, 0));
		topScoreTitle.setFont(fontLoaded);
		topScoreTitle.setStyle(Text::Bold);
		topScoreTitle.setPosition(800, 30);
		renderer.draw(topScoreTitle);

		int i = 0;

		while (i < ((int)topScores.size()) && i < 4) {

			sf::Text topScore1Title;
			topScore1Title.setString(L"Top Score");
			std::string score = "Vague : ";
			score = score + std::to_string(topScores[topScores.size() - 1 - i]);
			topScore1Title.setString(score);
			topScore1Title.setCharacterSize(70);
			topScore1Title.setFillColor(Color(255, 0, 0));
			topScore1Title.setFont(fontLoaded);
			topScore1Title.setStyle(Text::Bold);
			topScore1Title.setPosition(800, 30.f + (100.f*i) + 100.f);
			renderer.draw(topScore1Title);
			i++;
		}
	}
}


void Engine::newGame() {
	isRight = false;
	isGameLaunched = true;
	gameEnded = false;
	vague = 1;
	string newstr = "Vague : " + std::to_string(vague);
	vagueTitle.setString(newstr);
	timeUntilNextSpawn = 0;
	phase = 0;
	numberOfSpawnedClouds = 0;
	numberOfSpawnedBoss = 0;
	Sculptor newsculptor;
	sculptor = newsculptor;
}

void Engine::endGame() {
	//TODO
}


void Engine::createNewCloud(int cloudToCreate) {

	

	Cloud *cloudToAdd;


	
	cloudToAdd = new Cloud();
	cloudToAdd->init();
	
	cloudToAdd->setColor(sf::Color(vectorOfConfig[cloudToCreate].getRed(),
		vectorOfConfig[cloudToCreate].getGreen(), vectorOfConfig[cloudToCreate].getBlue()));
	cloudToAdd->setTexture(vectorOfConfig[cloudToCreate].getSprite());
	cloudToAdd->setIsBoss(vectorOfConfig[cloudToCreate].getIsBoss());
	
	
	
	auto vect = vectorOfConfig[cloudToCreate].getVectorOfKeyChar();

	for (int i = 0; i < (int)vect.size(); i++) {
		cloudToAdd->addKey(vect[i]);
	}
	
	cloudToAdd->update();

	unique_ptr<Cloud> ptrCloudToAdd(cloudToAdd);
	ptrCloudToAdd->setIsRight(isRight);

	if (hardMod) {
		ptrCloudToAdd->setSpeed(20);
	}
	
	if(listOfClouds.empty()) {
		sculptor.updateTexture(isRight);
	}

	isRight = !isRight;

	listOfClouds.insert(listOfClouds.begin(), move(ptrCloudToAdd));

}

void Engine::createNewRandomEasy() {

	int i = rand() % 10;
	createNewCloud(i);

}

void Engine::deleteCloudsDone() {
	if (!listOfClouds.empty()) {
		if (listOfClouds.back()->isDone()) {
			listOfOldClouds.push_back(move(listOfClouds[listOfClouds.size() - 1]));
			listOfClouds.pop_back();
			if (!listOfClouds.empty()) {
				sculptor.updateTexture(listOfClouds.back()->getIsRight());
			}
		}
	}

	vector<unique_ptr<Cloud>> swapVector;
	for (int i = 0; i < (int)listOfOldClouds.size(); i++) {
		if (!listOfOldClouds[i]->getIsTimeOut()) {
			swapVector.push_back(move(listOfOldClouds[i]));
		}
	}

	listOfOldClouds.swap(swapVector);
}


void Engine::deleteCloudsOld() {
	vector<unique_ptr<Cloud>> swapVector;

	for (int i = 0; i < (int)listOfOldClouds.size(); i++) {
		if (!listOfOldClouds[i]->getIsTimeOut()) {
			swapVector.push_back(move(listOfClouds[i]));
		}
	}

	listOfOldClouds.swap(swapVector);
}


std::unique_ptr<SceneryItem> Engine::createNewSceneryItem(int sceneryItemToCreate) {
	SceneryItem *sceneryToAdd;
	if (sceneryItemToCreate == 0) {
		//TODO
	}
	else {
		//TODO
	}

	unique_ptr<SceneryItem> ptrCloudToAdd(sceneryToAdd);
	listOfBackgroundItems.push_back(move(ptrCloudToAdd));
}

void Engine::destroySceneryItem(int indexOfSceneryItem) {
	vector<unique_ptr<SceneryItem>> swapVector;
	listOfBackgroundItems.swap(swapVector);
}


bool Engine::isHPLost(bool isCloudRight, bool isBoss, int posXcloud) {
	int posXlim;
	if (isCloudRight) {
		posXlim = 660;
	}
	else {
		posXlim = 436;
		if (isBoss) {
			posXlim -= 100;
		}
	}

	if (isCloudRight) {
		if (posXcloud <= posXlim) {
			sculptor.decrHealth(1);
			musicBadPtr->play();
			if (sculptor.getHealth() == 0) {
				gameEnded = true;
				timeUntilNextSpawn = 0;
			}


			return true;
		}
	}
	else {
		if (posXcloud >= posXlim) {
			sculptor.decrHealth(1);
			musicBadPtr->play();
			if (sculptor.getHealth() == 0) {
				gameEnded = true;
				timeUntilNextSpawn = 0;
			}

			

			return true;
		}
	}
	return false;
}

void Engine::update(float time) {
	if (!gameEnded) {
		if (invulnerable < 1) {
			invulnerable += time;
		}
		timeUntilNextSpawn += time;
		for (int i = 0; i < (int)listOfClouds.size(); i++) {
			listOfClouds[i]->update(time);
			if (isHPLost(listOfClouds[i]->getIsRight(), listOfClouds[i]->getIsBoss(), (int)listOfClouds[i]->getPosition().x)) {
				listOfClouds[i]->setIsDone();
			}
		}
		deleteCloudsDone();

		for (int i = 0; i < (int)listOfOldClouds.size(); i++) {
			listOfOldClouds[i]->update(time);
		}

		int n = vague / 6;

		float spawnDelay = 2.f - (n*0.1f);
		if (spawnDelay < 1) {
			spawnDelay = 1;
		}
		int facteur = 2;
		if (hardMod) {
			facteur = 4;
			spawnDelay = spawnDelay / 2.f;
		}
		int maxSpawn = vague * facteur;

		if (phase == 0) {
			if (numberOfSpawnedClouds >= maxSpawn) {
				if (listOfClouds.empty()) {
					phase = 1;
					resetValue();
					if (vague % 6 == 0) {
						numberOfSpawnedBoss++;
						if (hardMod) {
							numberOfSpawnedBoss++;
						}
					}
				}
			}
			else {
				if (timeUntilNextSpawn > spawnDelay) {
					createNewRandomEasy();
					timeUntilNextSpawn = 0;
					numberOfSpawnedClouds++;
				}
			}
		}
		else if (phase == 1) {
			if (numberOfSpawnedClouds >= maxSpawn) {
				if (listOfClouds.empty()) {
					phase = 2;
					vague++;
					sculptor.incrHealth(1);
					resetValue();
				}
			}
			else {
				if (timeUntilNextSpawn > spawnDelay) {
					if (numberOfSpawnedClouds % 2 == 1) {
						createNewRandomEasy();
					}
					int maxBoss = (n + 1);
					if (hardMod) {
						maxBoss = 2 * maxBoss;
					}
					if (numberOfSpawnedBoss < maxBoss) {
						if (vague % 6 == 1) {
							createNewCloud(13);
							numberOfSpawnedBoss++;
						}
						else if (vague % 6 == 2) {
							createNewCloud(11);
							numberOfSpawnedBoss++;
						}
						else if (vague % 6 == 3) {
							createNewCloud(12);
							numberOfSpawnedBoss++;
						}
						else if (vague % 6 == 4) {
							createNewCloud(10);
							numberOfSpawnedBoss++;
						}
						else if (vague % 6 == 5) {
							createNewCloud(15);
							numberOfSpawnedBoss++;
						}
						else if (vague % 6 == 0) {
							createNewCloud(14);
							numberOfSpawnedBoss++;
						}
					}
					if (numberOfSpawnedClouds%2 == 0) {
						createNewRandomEasy();
					}
					
					timeUntilNextSpawn = 0;
					numberOfSpawnedClouds++;
				}
			}
		}
		else if (phase == 2) {




			if (timeUntilNextSpawn > 2) {

				phase = 0;

				setVagueTitleCorner();

				resetValue();

			}
			else {
				string newstr = "Vague : " + std::to_string(vague);
				vagueTitle.setString(newstr);
				setVagueTitleFullScreen();
			}
		}
		else {
			assert(false);
		}
	}
	else {
		timeUntilNextSpawn += time;
		setVagueTitleCorner();
		if (timeUntilNextSpawn > 5) {
			isGameLaunched = false;
			listOfClouds.clear();
			listOfOldClouds.clear();
			topScores.push_back(vague);
			std::sort(topScores.begin(), topScores.begin() + topScores.size());
			
			

		}
	}
}

void Engine::drawAllInGame(sf::RenderWindow &renderer) {
	
	for (int i = 0; i < ((int)listOfBackgroundItems.size()); i++) {
		listOfBackgroundItems[i]->draw(renderer);
	}
	for (int i = 0; i < (int)listOfClouds.size(); i++) {
		listOfClouds[i]->draw(renderer);
	}

	for (int i = 0; i < (int)listOfOldClouds.size(); i++) {
		listOfOldClouds[i]->draw(renderer);
	}
	if (!listOfClouds.empty()) {
		listOfClouds.back()->drawLetter(renderer);
	}
	for (int i = 0; i < ((int)listOfHUDItems.size()); i++) {
		if (i >= 3 && i < 6) {
			if (i == 3 && sculptor.getHealth() >= 1) {
				listOfHUDItems[i]->draw(renderer);
			}
			else if (i == 4 && sculptor.getHealth() >= 2) {
				listOfHUDItems[i]->draw(renderer);
			}
			else if (i == 5 && sculptor.getHealth() >= 3) {
				listOfHUDItems[i]->draw(renderer);
			}


		}
		else {
			listOfHUDItems[i]->draw(renderer);
		}
		
	}
	renderer.draw(vagueTitle);
	if (gameEnded) {
		renderer.draw(failTitle);
	}
	if (invulnerable>=1) {
		sculptor.draw(renderer);
	}
	else {
		if (drawSculptor) {
			sculptor.draw(renderer);
		}
		drawSculptor = !drawSculptor;
	}
}

void Engine::keyPressed(Keyboard::Key keyPressed) {
	if (!gameEnded) {
		if (!listOfClouds.empty()) {
			bool a = listOfClouds.back()->tryKeyInput(keyPressed);
			if (!a) {
				if (invulnerable >= 1) {
					invulnerable = 0;
					sculptor.decrHealth(1);
					musicBadPtr->play();
					if (sculptor.getHealth() == 0) {
						gameEnded = true;
						timeUntilNextSpawn = 0;
					}
				}
			}
			
		}
	}
}

void Engine::resetValue() {
	isRight = false;
	sculptor.updateTexture(isRight);
	numberOfSpawnedClouds = 0;
	timeUntilNextSpawn = 0;
	numberOfSpawnedBoss = 0;
}

void Engine::setHighScore(int tab[4]) {
	for (int i = 0; i < 4; i++) {
		if (tab[i] > 0) {
			topScores.push_back(tab[i]);
		}

	}
	std::sort(topScores.begin(), topScores.begin() + topScores.size());
}

void Engine::getHighScore(int tab[4]) {
	int i = 0;
	while ((!topScores.empty()) && i < 4) {
		tab[i]=topScores.back();
		topScores.pop_back();
		i++;
	}
	while (i < 4) {
		tab[i] = 0;
		i++;
	}

	

}

void Engine::setVectorOfConfig(std::vector<Config> newvectorOfConfig) {
	vectorOfConfig.clear();

	for (int i = 0; i < (int)newvectorOfConfig.size(); i++) {
		vectorOfConfig.push_back(newvectorOfConfig[i]);
	}

}