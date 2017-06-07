#include <SFML/Window/Keyboard.hpp>
#include <sstream>
#include "SceneryRectangleBasic.h"
#include "Cloud.h"
#include <assert.h>


Cloud::Cloud() : currentKeyIndice(0) {

}

Cloud::~Cloud() {

}


void Cloud::draw(sf::RenderTarget &target) {
	spriteImage.draw(target);
	for (int i = currentKeyIndice; i < alterKeyList.size(); i++) {
		spriteList[i].draw(target);
	}
}

void Cloud::setIsRight(bool newBool) {
	isRight = newBool;
	update();
}

void Cloud::setTexture() {
	spriteImage.setTexture();
}

void Cloud::update() {
	spriteImage.setSize(100,100);
	int n = alterKeyList.size();
	auto pos = spriteImage.getPosition();

	for (int i = 0; i < n; i++) {
		spriteList[i].setSize(100./n,100);
		if (isRight) {
			spriteList[i].setPosition(pos.x + (100. / n)*(i), pos.y);
		}
		else {
			spriteList[i].setPosition(pos.x + (100. / n)*(n - i - 1), pos.y);
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

	if (key == sf::Keyboard::A) {
		SceneryRectangleBasic newSprite;
		newSprite.setColor(sf::Color(236, 94, 233));
		addSprite(newSprite);
	} else if (key == sf::Keyboard::B) {
		SceneryRectangleBasic newSprite;
		newSprite.setColor(sf::Color::Blue);
		addSprite(newSprite);
	}
	else if(key == sf::Keyboard::C) {
		SceneryRectangleBasic newSprite;
		newSprite.setColor(sf::Color::Cyan);
		addSprite(newSprite);
	}
	else if(key == sf::Keyboard::D) {
		SceneryRectangleBasic newSprite;
		newSprite.setColor(sf::Color(236, 94, 233));
		addSprite(newSprite);
	}
	else if(key == sf::Keyboard::E) {
		SceneryRectangleBasic newSprite;
		newSprite.setColor(sf::Color(236, 94, 233));
		addSprite(newSprite);
	}
	else if(key == sf::Keyboard::F) {
		SceneryRectangleBasic newSprite;
		newSprite.setColor(sf::Color(236, 94, 233));
		addSprite(newSprite);
	}
	else if(key == sf::Keyboard::G) {
		SceneryRectangleBasic newSprite;
		newSprite.setColor(sf::Color::Green);
		addSprite(newSprite);
	}
	else if(key == sf::Keyboard::H) {
		SceneryRectangleBasic newSprite;
		newSprite.setColor(sf::Color(236, 94, 233));
		addSprite(newSprite);
	}
	else if(key == sf::Keyboard::I) {
		SceneryRectangleBasic newSprite;
		newSprite.setColor(sf::Color(236, 94, 233));
		addSprite(newSprite);
	}
	else if(key == sf::Keyboard::J) {
		SceneryRectangleBasic newSprite;
		newSprite.setColor(sf::Color(236, 94, 233));
		addSprite(newSprite);
	}
	else if(key == sf::Keyboard::K) {
		SceneryRectangleBasic newSprite;
		newSprite.setColor(sf::Color(236, 94, 233));
		addSprite(newSprite);
	}
	else if(key == sf::Keyboard::L) {
		SceneryRectangleBasic newSprite;
		newSprite.setColor(sf::Color(236, 94, 233));
		addSprite(newSprite);
	}
	else if(key == sf::Keyboard::M) {
		SceneryRectangleBasic newSprite;
		newSprite.setColor(sf::Color::Magenta);
		addSprite(newSprite);
	}
	else if(key == sf::Keyboard::O) {
		SceneryRectangleBasic newSprite;
		newSprite.setColor(sf::Color(236, 94, 233));
		addSprite(newSprite);
	}
	else if(key == sf::Keyboard::P) {
		SceneryRectangleBasic newSprite;
		newSprite.setColor(sf::Color(236, 94, 233));
		addSprite(newSprite);
	}
	else if(key == sf::Keyboard::Q) {
		SceneryRectangleBasic newSprite;
		newSprite.setColor(sf::Color(236, 94, 233));
		addSprite(newSprite);
	}
	else if(key == sf::Keyboard::R) {
		SceneryRectangleBasic newSprite;
		newSprite.setColor(sf::Color::Red);
		addSprite(newSprite);
	}
	else if(key == sf::Keyboard::S) {
		SceneryRectangleBasic newSprite;
		newSprite.setColor(sf::Color(236, 94, 233));
		addSprite(newSprite);
	}
	else if(key == sf::Keyboard::T) {
		SceneryRectangleBasic newSprite;
		newSprite.setColor(sf::Color(236, 94, 233));
		addSprite(newSprite);
	}
	else if(key == sf::Keyboard::U) {
		SceneryRectangleBasic newSprite;
		newSprite.setColor(sf::Color(236, 94, 233));
		addSprite(newSprite);
	}
	else if(key == sf::Keyboard::V) {
		SceneryRectangleBasic newSprite;
		newSprite.setColor(sf::Color(236, 94, 233));
		addSprite(newSprite);
	}
	else if(key == sf::Keyboard::W) {
		SceneryRectangleBasic newSprite;
		newSprite.setColor(sf::Color::White);
		addSprite(newSprite);
	}
	else if(key == sf::Keyboard::X) {
		SceneryRectangleBasic newSprite;
		newSprite.setColor(sf::Color(236, 94, 233));
		addSprite(newSprite);
	}
	else if(key == sf::Keyboard::Y) {
		SceneryRectangleBasic newSprite;
		newSprite.setColor(sf::Color::Yellow);
		addSprite(newSprite);
	}
	else if(key == sf::Keyboard::Z) {
		SceneryRectangleBasic newSprite;
		newSprite.setColor(sf::Color(236, 94, 233));
		addSprite(newSprite);
	}
	else {
		assert(false);
	}
	
	


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
