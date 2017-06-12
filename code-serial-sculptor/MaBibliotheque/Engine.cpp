#include "Engine.h"

using namespace std;
using namespace sf;


Engine::Engine() {

}

Engine::~Engine() {

}


void Engine::launchMainMenu() {
	//TODO
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


void Engine::createNewCloud(int cloudToCreate, bool isRightCloud) {
	Cloud *cloudToAdd;
	if (cloudToCreate == 0) {
		CloudEasy *cloudToAdd = new CloudEasy();
	}
	else {
		CloudBoss1 *cloudToAdd = new CloudBoss1();
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
