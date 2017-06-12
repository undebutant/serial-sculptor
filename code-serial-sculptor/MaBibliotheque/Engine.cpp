#include "Engine.h"

using namespace std;
using namespace sf;


Engine::Engine() {

}

Engine::~Engine() {

}


void Engine::launchMainMenu() {
	ContextSettings settings;
	settings.antialiasingLevel = 8;
	
	RenderWindow window(sf::VideoMode(1200, 600), "Serial sculptor", Style::Resize, settings);

	Clock clock;
	Event event;

	loadAll();

	while (window.isOpen()) {
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::KeyPressed) {
				if (event.key.code == Keyboard::Escape) {
					window.close();
				}
			}
		}
		window.clear();
		
		float time = clock.restart().asSeconds();
		//TODO call update functions
		drawMainMenu(window);

		window.display();
	}
}

void Engine::drawMainMenu(RenderWindow &renderer) {
	RectangleShape menuBackground(Vector2f(1200, 600));
	RectangleShape newGameButton(Vector2f(566, 80));
	RectangleShape exitButton(Vector2f(382, 80));

	menuBackground.setTexture(getTexture("mainMenuBackground.jpeg"));
	newGameButton.setTexture(getTexture("newGameButton.png"));
	exitButton.setTexture(getTexture("exitButton.png"));

	Text menuTitle;
	menuTitle.setString(L"Serial Sculptor");
	menuTitle.setCharacterSize(70);
	menuTitle.setFillColor(Color(255, 255, 255, 255));
	menuTitle.setFont(fontLoaded);
	menuTitle.setStyle(Text::Bold);

	newGameButton.setPosition(150, 140);
	exitButton.setPosition(242, 260);
	menuTitle.setPosition(210, 30);

	renderer.draw(menuBackground);
	renderer.draw(newGameButton);
	renderer.draw(exitButton);
	renderer.draw(menuTitle);
}


void Engine::newGame() {
	//TODO
}

void Engine::endGame() {
	//TODO
}


bool Engine::loadTexture(string pathToTexture, string nameToStore) {
	Texture newTexture;

	if (!newTexture.loadFromFile(pathToTexture)) {
		return false;
	}
	else {
		textureLoaded[nameToStore] = newTexture;
		return true;
	}
}

bool Engine::loadFont(string pathToFont) {
	Font newFont;

	if (!newFont.loadFromFile(pathToFont)) {
		return false;
	}
	else {
		fontLoaded = newFont;
		return true;
	}
}

void Engine::loadAll() {
	if (!loadFont("font\\SilentReaction.ttf")) {
		cout << "Impossible de charger la police SilentReaction.ttf" << endl;
	}

	Texture textureLoaded;

	string pathToSprite = "sprite\\";
	string nameForSprite;
	string iteratorToString;

	string variousImages[4] = { "chaton.png", "mainMenuBackground.jpeg", "exitButton.png", "newGameButton.png" };

	for (int i = 0; i < 4; i++) {
		if (!loadTexture(pathToSprite + variousImages[i], variousImages[i])) {
			cout << "Impossible de charger la texture " << nameForSprite << endl;
		}
	}

	for (int i = 1; i < 6; i++) {
		pathToSprite = "sprite\\";
		nameForSprite = "CloudBoss";
		iteratorToString = to_string(i);

		nameForSprite = nameForSprite + iteratorToString + ".png";
		pathToSprite = pathToSprite + nameForSprite;

		if (!loadTexture(pathToSprite, nameForSprite)) {
			cout << "Impossible de charger la texture " << nameForSprite << endl;
		}
	}

	for (int i = 1; i <= 10; i++) {
		pathToSprite = "sprite\\";
		nameForSprite = "CloudEasy";
		iteratorToString = to_string(i);

		nameForSprite = nameForSprite + iteratorToString + ".png";
		pathToSprite = pathToSprite + nameForSprite;

		if (!loadTexture(pathToSprite, nameForSprite)) {
			cout << "Impossible de charger la texture " << nameForSprite << endl;
		}
	}

	for (char i = 'A'; i <= 'Z'; i++) {
		pathToSprite = "sprite\\";
		nameForSprite = "";

		nameForSprite.push_back(i);
		nameForSprite = nameForSprite + ".png";
		pathToSprite = pathToSprite + nameForSprite;

		if (!loadTexture(pathToSprite, nameForSprite)) {
			cout << "Impossible de charger la texture " << nameForSprite << endl;
		}
	}
}

sf::Texture* Engine::getTexture(std::string texture) {
	return &(textureLoaded[texture]);
}


void Engine::createNewCloud(int cloudToCreate, bool isRightCloud) {
	Cloud *cloudToAdd;
	if (cloudToCreate == 0) {
		cloudToAdd = new CloudEasy1();
	}
	else {
		cloudToAdd = new CloudBoss1();
	}

	unique_ptr<Cloud> ptrCloudToAdd(cloudToAdd);
	ptrCloudToAdd->setIsRight(isRightCloud);

	listOfClouds.push_back(move(ptrCloudToAdd));
}

void Engine::deleteCloudsDone() {
	vector<unique_ptr<Cloud>> swapVector;
	for (int i = 0; i < (int)listOfClouds.size(); i++) {
		if (!listOfClouds[i]->isDone()) {
			swapVector.push_back(move(listOfClouds[i]));
		}
	}

	listOfClouds.swap(swapVector);
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

void Engine::drawAll(sf::RenderWindow &renderer) {
	for (int i = 0; i < (int)listOfClouds.size(); i++) {
		listOfClouds[i]->draw(renderer);
	}
}

void Engine::keyPressed(Keyboard::Key keyPressed) {
	if (!listOfClouds.empty()) {
		listOfClouds[0]->tryKeyInput(keyPressed);
	}
}
