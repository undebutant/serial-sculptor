#include "Engine.h"
#include "TextureManager.h"

using namespace std;
using namespace sf;


Engine::Engine() {

}

Engine::~Engine() {

}

void Engine::init() {
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
					//tryimput
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
			updateItems(time);
			drawAllInGame(window);
		}
		else {
			drawMainMenu(window);
		}
		

		window.display();
	}
}

void Engine::drawMainMenu(RenderWindow &renderer) {
	

	Text menuTitle;
	menuTitle.setString(L"Serial Sculptor");
	menuTitle.setCharacterSize(70);
	menuTitle.setFillColor(Color(255, 255, 255, 255));
	menuTitle.setFont(fontLoaded);
	menuTitle.setStyle(Text::Bold);

	menuTitle.setPosition(210, 30);
	
	
	
	for (int i = 0; i < ((int)listOfBackgroundItemsMainMenu.size()); i++) {
		listOfBackgroundItemsMainMenu[i]->draw(renderer);
	}

	renderer.draw(menuTitle);
}


void Engine::newGame() {
	isGameLaunched = true;

	Sculptor newsculptor;
	sculptor = newsculptor;
	

}

void Engine::bossPhase() {

}

void Engine::endGame() {
	//TODO
}











void Engine::createNewCloud(int cloudToCreate, bool isRightCloud) {
	Cloud *cloudToAdd;
	vector<unique_ptr<Cloud>> swapVector;

	if (cloudToCreate == 0) {
		cloudToAdd = new CloudEasy1();
	}
	else {
		cloudToAdd = new CloudBoss1();
	}

	unique_ptr<Cloud> ptrCloudToAdd(cloudToAdd);
	ptrCloudToAdd->setIsRight(isRightCloud);

	swapVector.push_back(move(ptrCloudToAdd));

	for (int i = 0; i < (int)listOfClouds.size(); i++) {
		swapVector.push_back(move(listOfClouds[i]));
	}

	listOfClouds.swap(swapVector);
}

void Engine::deleteCloudsDone() {
	if (!listOfClouds.empty()) {
		if (listOfClouds[listOfClouds.size() - 1]->isDone()) {
			listOfOldClouds.push_back(move(listOfClouds[listOfClouds.size() - 1]));
			listOfClouds.pop_back();
		}
	}

	vector<unique_ptr<Cloud>> swapVector;
	for (int i = 0; i < (int)listOfClouds.size(); i++) {
		if (!listOfClouds[i]->isDone()) {
			swapVector.push_back(move(listOfClouds[i]));
		}
	}

	listOfClouds.swap(swapVector);
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


void Engine::updateItems(float time) {
	deleteCloudsDone();

	for (int i = 0; i < (int) listOfClouds.size(); i++) {
		listOfClouds[i]->update(time);
	}
}

void Engine::drawAllInGame(sf::RenderWindow &renderer) {
	
	for (int i = 0; i < ((int)listOfBackgroundItems.size()); i++) {
		listOfBackgroundItems[i]->draw(renderer);
	}
	for (int i = 0; i < (int)listOfClouds.size(); i++) {
		listOfClouds[i]->draw(renderer);
	}
	sculptor.draw(renderer);
}

void Engine::keyPressed(Keyboard::Key keyPressed) {
	if (!listOfClouds.empty()) {
		listOfClouds[0]->tryKeyInput(keyPressed);
	}
}
