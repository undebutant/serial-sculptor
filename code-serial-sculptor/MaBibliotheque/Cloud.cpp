#include <SFML/Window/Keyboard.hpp>
#include <sstream>

#include "Cloud.h"


Cloud::Cloud() : currentKeyIndice(0) {

}

Cloud::~Cloud() {

}


void Cloud::draw(sf::RenderTarget &target) {
	sprite.draw(target);
}


void Cloud::setPosition(float x, float y) {
	sprite.setPosition(x, y);
}

sf::Vector2f Cloud::getPosition() {
	return sprite.getPosition();
}

void Cloud::setSize(float x, float y) {
	sprite.setSize(x, y);
}

sf::Vector2f Cloud::getSize() {
	return sprite.getSize();
}


void Cloud::setSprite(std::string newSpritePath) {
	sprite.setSprite(newSpritePath);
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
