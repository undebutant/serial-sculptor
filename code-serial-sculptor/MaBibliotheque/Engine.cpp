#include "Engine.h"
#include "TextureManager.h"
#include <assert.h>

using namespace std;
using namespace sf;


Engine::Engine() {

}

Engine::~Engine() {

}

void Engine::init() {
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

	//Game
	std::unique_ptr<SceneryItem> gameBackground = std::unique_ptr<SceneryItem>(new SceneryItem());
	gameBackground->setSize(1200, 600);
	gameBackground->setTexture("gameBackground.jpeg");
	listOfBackgroundItems.push_back(move(gameBackground));
}

void Engine::launchMainMenu() {
	TextureManager::loadAll();
	
	isGameLaunched = false;
	ContextSettings settings;
	settings.antialiasingLevel = 8;
	
	RenderWindow window(sf::VideoMode(1200, 600), "Serial sculptor", Style::Titlebar | Style::Close, settings);

	Clock clock;
	Event event;

	
	init();
	cout << "init finished" << endl;
	

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
					if (event.mouseButton.x > 150 && event.mouseButton.x < 716 && event.mouseButton.y > 140 && event.mouseButton.y < 220) {
						newGame();
					}
					if (event.mouseButton.x > 242 && event.mouseButton.x < 624 && event.mouseButton.y > 260 && event.mouseButton.y < 340) {
						window.close();
					}
				}
			}
		}
		window.clear();
		
		float time = clock.restart().asSeconds();
		if (isGameLaunched) {
			update(time);
			drawAllInGame(window);
		}
		else {
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
}


void Engine::newGame() {
	isRight = false;
	isGameLaunched = true;
	vague = 1;
	timeUntilNextSpawn = 0;
	phase = 0;
	numberOfSpawnedClouds = 0;
	numberOfSpawnedBoss = 0;
	Sculptor newsculptor;
	sculptor = newsculptor;
	

}

void Engine::bossPhase() {

}

void Engine::endGame() {
	//TODO
}











void Engine::createNewCloud(int cloudToCreate) {
	Cloud *cloudToAdd;
	vector<unique_ptr<Cloud>> swapVector;

	if (cloudToCreate == 1) {
		cloudToAdd = new CloudEasy1();
	}	else if (cloudToCreate == 2) {
		cloudToAdd = new CloudEasy2();
	}	else if (cloudToCreate == 3) {
		cloudToAdd = new CloudEasy3();
	}	else if (cloudToCreate == 4) {
		cloudToAdd = new CloudEasy4();
	}	else if (cloudToCreate == 5) {
		cloudToAdd = new CloudEasy5();
	}	else if (cloudToCreate == 6) {
		cloudToAdd = new CloudEasy6();
	}	else if (cloudToCreate == 7) {
		cloudToAdd = new CloudEasy7();
	}   else if (cloudToCreate == 8) {
		cloudToAdd = new CloudEasy8();
	}	else if (cloudToCreate == 9) {
		cloudToAdd = new CloudEasy9();
	}	else if (cloudToCreate == 10) {
		cloudToAdd = new CloudEasy10();
	}   else if (cloudToCreate == 11) {
		cloudToAdd = new CloudBoss1();
	}	else if (cloudToCreate == 12) {
		cloudToAdd = new CloudBoss2();
	}	else if (cloudToCreate == 13) {
		cloudToAdd = new CloudBoss3();
	}	else if (cloudToCreate == 14) {
		cloudToAdd = new CloudBoss4();
	}	else if (cloudToCreate == 15) {
		cloudToAdd = new CloudBoss5();
	}	else if (cloudToCreate == 16) {
		cloudToAdd = new CloudBoss6();
	}
	

	unique_ptr<Cloud> ptrCloudToAdd(cloudToAdd);
	ptrCloudToAdd->setIsRight(isRight);
	

	if(listOfClouds.empty()) {
		cout << "appel updateTexture depuis createNewClous: " << isRight << endl;
		sculptor.updateTexture(isRight);
	}

	isRight = !isRight;
	swapVector.push_back(move(ptrCloudToAdd));

	for (int i = 0; i < (int)listOfClouds.size(); i++) {
		swapVector.push_back(move(listOfClouds[i]));
	}

	listOfClouds.swap(swapVector);
}

void Engine::createNewRandomEasy() {

	int i = rand() % 10 + 1;
	createNewCloud(i);

}

void Engine::deleteCloudsDone() {
	if (!listOfClouds.empty()) {
		if (listOfClouds.back()->isDone()) {
			listOfOldClouds.push_back(move(listOfClouds[listOfClouds.size() - 1]));
			listOfClouds.pop_back();
			if (!listOfClouds.empty()) {
				cout << "appel updateTexture depuis deleteClouds: " << listOfClouds.back()->getIsRight() << endl;
				sculptor.updateTexture(listOfClouds.back()->getIsRight());
			}
		}
	}

	vector<unique_ptr<Cloud>> swapVector;
	for (int i = 0; i < (int)listOfOldClouds.size(); i++) {
		if (!listOfOldClouds[i]->isTimeOut()) {
			swapVector.push_back(move(listOfOldClouds[i]));
		}
	}

	listOfOldClouds.swap(swapVector);
}


void Engine::deleteCloudsOld() {
	vector<unique_ptr<Cloud>> swapVector;

	for (int i = 0; i < (int)listOfOldClouds.size(); i++) {
		if (!listOfOldClouds[i]->isTimeOut()) {
			swapVector.push_back(move(listOfClouds[i]));
		}
	}

	listOfOldClouds.swap(swapVector);
}

/*
std::unique_ptr<HudItems> Engine::createNewHudItem(int hudToCreate) {
	
}
void Engine::destroyHudItem(int indexOfHudItem) {
	
}
*/


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


void Engine::update(float time) {
	deleteCloudsDone();
	timeUntilNextSpawn += time;
	for (int i = 0; i < (int) listOfClouds.size(); i++) {
		listOfClouds[i]->update(time);
	}

	for (int i = 0; i < (int)listOfOldClouds.size(); i++) {
		listOfOldClouds[i]->update(time);
	}

	int n = vague / 6;

	float spawnDelay = 2.f-(n*0.1f);
	if (spawnDelay < 1) {
		spawnDelay = 1;
	}
	int maxSpawn = vague * 2;

	if (phase == 0) {
		if (numberOfSpawnedClouds >= maxSpawn) {
			if (listOfClouds.empty()) {
				phase = 1;
				resetValue();
				if (vague % 6 == 0) {
					numberOfSpawnedBoss++;
				}
			}
		}
		else {
			if (timeUntilNextSpawn>spawnDelay) {
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
				resetValue();
			}
		}
		else {
			if (timeUntilNextSpawn>spawnDelay) {
				if (numberOfSpawnedBoss < (n+1)) {
					if (vague % 6 == 1) {
						createNewCloud(14);
						numberOfSpawnedBoss++;
					}
					else if (vague % 6 == 2) {
						createNewCloud(12);
						numberOfSpawnedBoss++;
					}
					else if (vague % 6 == 3) {
						createNewCloud(13);
						numberOfSpawnedBoss++;
					}
					else if (vague % 6 == 4) {
						createNewCloud(11);
						numberOfSpawnedBoss++;
					}
					else if (vague % 6 == 5) {
						createNewCloud(16);
						numberOfSpawnedBoss++;
					}
					else if (vague % 6 == 0) {
						createNewCloud(15);
						numberOfSpawnedBoss++;
					}
				}
				createNewRandomEasy();
				timeUntilNextSpawn = 0;
				numberOfSpawnedClouds++;
			}

		}
	}
	else if (phase == 2) {
		
		if (timeUntilNextSpawn>spawnDelay) {
			if (listOfOldClouds.empty()) {
				phase = 0;
				vague++;
				resetValue();
			}
		}

		
	}
	else {
		assert(false);
	}

	
	
}

void Engine::drawAllInGame(sf::RenderWindow &renderer) {
	
	for (int i = 0; i < ((int)listOfBackgroundItems.size()); i++) {
		listOfBackgroundItems[i]->draw(renderer);
	}
	for (int i = 0; i < (int)listOfOldClouds.size(); i++) {
		listOfOldClouds[i]->draw(renderer);
	}
	for (int i = 0; i < (int)listOfClouds.size(); i++) {
		listOfClouds[i]->draw(renderer);
	}
	if (!listOfClouds.empty()) {
		listOfClouds.back()->drawLetter(renderer);
	}
	sculptor.draw(renderer);
}

void Engine::keyPressed(Keyboard::Key keyPressed) {
	if (!listOfClouds.empty()) {
		listOfClouds.back()->tryKeyInput(keyPressed);
	}
}

void Engine::resetValue() {
	isRight = false;
	sculptor.updateTexture(isRight);
	numberOfSpawnedClouds = 0;
	timeUntilNextSpawn = 0;
	numberOfSpawnedBoss = 0;
}
