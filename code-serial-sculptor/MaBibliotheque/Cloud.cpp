#include <SFML/Window/Keyboard.hpp>
#include <sstream>
#include "SceneryRectangleBasic.h"
#include "Cloud.h"
#include <assert.h>
#include <iostream>


Cloud::Cloud(){
	
	


}

Cloud::~Cloud() {

}

void Cloud::setIsBoss(bool newBool) {
	isBoss = newBool;
	setSize(200, 200);
	auto pos = getPosition();
	setPosition(pos.x , pos.y-100);

}

void Cloud::init() {
	currentKeyIndice = 0;
	isBoss = false;
	setPosition(10, 210);
	setSpeed(10.0);
	isRight = false;
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
	
	int n = (int)keyItemList.size();
	int number = 4;
	if (isBoss) {
		number = 8;
	}

	n = min(number+currentKeyIndice, n);
	for (int i = currentKeyIndice; i < (n); i++) {
		keyItemList[i].draw(target);

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
		
		if (isBoss) {
			spriteList[i].setSize(2*temp, 2*100);
		} else {
			spriteList[i].setSize(temp, 100);
		}
		if (isRight) {
			if (isBoss) {
				spriteList[i].setPosition(pos.x + (temp)*(2*i), pos.y);
			} else {
				spriteList[i].setPosition(pos.x + (temp)*(i), pos.y);
			}
		}
		else {
			if (isBoss) {
				spriteList[i].setPosition(pos.x + (temp)*(2*n - 2*i - 2), pos.y);
			} else {
				spriteList[i].setPosition(pos.x + (temp)*(n - i - 1), pos.y);
			}
		}
	}

	
	for (int i = currentKeyIndice; i < n; i++) {
		if (isRight) {
			keyItemList[i].setPosition(pos.x + (i - currentKeyIndice)*(25), pos.y - 50);
		}
		else {
			keyItemList[i].setPosition(pos.x + 75 - (i - currentKeyIndice)*(25), pos.y - 50);
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
	
	

	SceneryItem newKeySprite;
	newKeySprite.setSize(25, 25);
	newKeySprite.setPosition(0,0);


	if (key == sf::Keyboard::A) {
		newKeySprite.setTexture("A.png");
	} else 	if (key == sf::Keyboard::B) {
		newKeySprite.setTexture("B.png");
	} else 	if (key == sf::Keyboard::C) {
		newKeySprite.setTexture("C.png");
	} else 	if (key == sf::Keyboard::D) {
		newKeySprite.setTexture("D.png");
	} else 	if (key == sf::Keyboard::E) {
		newKeySprite.setTexture("E.png");
	} else 	if (key == sf::Keyboard::F) {
		newKeySprite.setTexture("F.png");
	} else 	if (key == sf::Keyboard::G) {
		newKeySprite.setTexture("G.png");
	} else 	if (key == sf::Keyboard::H) {
		newKeySprite.setTexture("H.png");
	} else 	if (key == sf::Keyboard::I) {
		newKeySprite.setTexture("I.png");
	} else 	if (key == sf::Keyboard::J) {
		newKeySprite.setTexture("J.png");
	} else 	if (key == sf::Keyboard::K) {
		newKeySprite.setTexture("K.png");
	} else 	if (key == sf::Keyboard::L) {
		newKeySprite.setTexture("L.png");
	} else 	if (key == sf::Keyboard::M) {
		newKeySprite.setTexture("M.png");
	} else 	if (key == sf::Keyboard::N) {
		newKeySprite.setTexture("N.png");
	} else 	if (key == sf::Keyboard::O) {
		newKeySprite.setTexture("O.png");
	} else 	if (key == sf::Keyboard::P) {
		newKeySprite.setTexture("P.png");
	} else 	if (key == sf::Keyboard::Q) {
		newKeySprite.setTexture("Q.png");
	} else 	if (key == sf::Keyboard::R) {
		newKeySprite.setTexture("R.png");
	} else 	if (key == sf::Keyboard::S) {
		newKeySprite.setTexture("S.png");
	} else 	if (key == sf::Keyboard::T) {
		newKeySprite.setTexture("T.png");
	} else 	if (key == sf::Keyboard::U) {
		newKeySprite.setTexture("U.png");
	} else 	if (key == sf::Keyboard::V) {
		newKeySprite.setTexture("V.png");
	} else 	if (key == sf::Keyboard::W) {
		newKeySprite.setTexture("W.png");
	} else 	if (key == sf::Keyboard::X) {
		newKeySprite.setTexture("X.png");
	} else 	if (key == sf::Keyboard::Y) {
		newKeySprite.setTexture("Y.png");
	} else 	if (key == sf::Keyboard::Z) {
		newKeySprite.setTexture("Z.png");
	} else {
		cout << "Ton ennemi n'a aucun sens"<< endl;
	}


	
	





	keyItemList.push_back(newKeySprite);


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
