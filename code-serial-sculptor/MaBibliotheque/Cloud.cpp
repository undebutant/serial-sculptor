#include <SFML/Window/Keyboard.hpp>
#include <sstream>
#include "SceneryRectangleBasic.h"
#include "Cloud.h"
#include <assert.h>


Cloud::Cloud() : currentKeyIndice(0) {

}

Cloud::~Cloud() {

}


void Cloud::setSpeed(float newSpeed) {
	speed = newSpeed;
}

void Cloud::update(float time) {
	if (!isDone()) {
		auto pos = spriteImage.getPosition();
		float x = pos.x;
		if (isRight) {
			x -= time*speed;
		}
		else {
			x += time*speed;
		}
		

		spriteImage.setPosition(x, pos.y);

		update();
	}
}

void Cloud::draw(sf::RenderTarget &target) {
	spriteImage.draw(target);
	for (int i = currentKeyIndice; i < ((int) alterKeyList.size()); i++) {
		spriteList[i].draw(target);
	}
}

void Cloud::setIsRight(bool newBool) {
	isRight = newBool;

	if (newBool) {
		auto pos = getPosition();
		setPosition(800-pos.x-spriteImage.getSize().x, pos.y);
	}
	update();
}

void Cloud::setTexture(std::string texture) {
	spriteImage.setSize(100, 100);
	spriteImage.setTexture(texture);
}

void Cloud::update() {
	
	int n = alterKeyList.size();
	auto pos = spriteImage.getPosition();

	for (int i = 0; i < n; i++) {
		float temp = (float) (100.0 / n);
		spriteList[i].setSize(temp,100);
		if (isRight) {
			spriteList[i].setPosition(pos.x + (temp)*(i), pos.y);
		}
		else {
			spriteList[i].setPosition(pos.x + (temp)*(n - i - 1), pos.y);
		}
	}
}

void Cloud::setPosition(float x, float y) {
	spriteImage.setPosition(x, y);
}

sf::Vector2f Cloud::getPosition() {
	return spriteImage.getPosition();
}

void Cloud::setSize(float x, float y) {
	spriteImage.setSize(x, y);
}

sf::Vector2f Cloud::getSize() {
	return spriteImage.getSize();
}


void Cloud::setSprite(std::string newSpritePath) {
	spriteImage.setSprite(newSpritePath);
}


void Cloud::setColor(sf::Color newcolor) {
	color = newcolor;
}

sf::Color Cloud::getColor() {
	return color;
}


int Cloud::getCurrentKeyIndice() {
	return currentKeyIndice;
}

void Cloud::setAlterKeyList(std::vector<enum sf::Keyboard::Key> keyList) {
	alterKeyList.resize(keyList.size());

	for (int i = 0; i < (int) keyList.size(); i++) {
		alterKeyList[i] = keyList[i];
	}
}

std::vector<enum sf::Keyboard::Key> Cloud::getAlterKeyList() {
	return alterKeyList;
}

void Cloud::addKey(sf::Keyboard::Key key) {
	alterKeyList.push_back(key);

	
	SceneryRectangleBasic newSprite;
	newSprite.setColor(color);
	addSprite(newSprite);
	
	
	


}

void Cloud::addSprite(SceneryItem newSprite) {
	spriteList.push_back(newSprite);
}

int Cloud::getAlterKeyListSize() {
	return alterKeyList.size();
}


bool Cloud::tryKeyInput(sf::Keyboard::Key key) {
	if (!isDone()) {
		if (key == alterKeyList[currentKeyIndice]) {
			currentKeyIndice++;
			return true;
		}
		else {
			return false;
		}
	}
	return false;
}


std::ostream& operator<<(std::ostream &strm, const Cloud &a) {
	std::stringstream keys;
	for (int i = 0; i < (int) a.alterKeyList.size(); i++) {
		if (i != 0) {
			keys << ",";
		}
		keys << "[" << i << "] : ";
		char ch = a.alterKeyList[i] + 65;
		keys << ch;
	}

	return strm << "Nuage (keyVector.size = " << a.alterKeyList.size()<< ", " << keys.str() << ")";
}
