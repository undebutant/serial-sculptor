#include <SFML/Window/Keyboard.hpp>
#include <sstream>
#include <assert.h>
#include <iostream>


#include "SceneryRectangleBasic.h"
#include "Cloud.h"
#include "TextureManagerSingleton.h"


Cloud::Cloud(){
	
}

Cloud::~Cloud() {

}


void Cloud::init() {
	currentKeyIndice = 0;
	isBoss = false;
	isEntered = false;
	TextureManagerSingleton &manager = TextureManagerSingleton::Instance();
	setPosition((float)manager.getHeight()*10/1200, (float)manager.getWidth());
	setSpeed((float)manager.getHeight()*10.0f/1200);
	isRight = false;
	isTimeOut = false;
}


void Cloud::update() {
	int n = alterKeyList.size();
	auto pos = spriteImage.getPosition();
	TextureManagerSingleton &manager = TextureManagerSingleton::Instance();
	int centint = 100 * manager.getHeight() / 1200;
	float centfloatx = 100.0f * ((float)manager.getHeight()) / 1200;
	float centfloatysize = 100.0f * ((float)manager.getWidth()) / 675;
	float centfloaty = 100.0f * ((float)manager.getWidth()) / 600;

	for (int i = 0; i < n; i++) {
		float temp = (float)(centfloatx / n);

		if (isBoss) {
			spriteRectangle.setSize(2*(centfloatx -temp*currentKeyIndice), 2 * centfloatysize);
		}
		else {
			spriteRectangle.setSize(centfloatx - temp*currentKeyIndice, centfloatysize);
		}
		if (isRight) {
			if (isBoss) {
				spriteRectangle.setPosition(pos.x + 2*temp*currentKeyIndice, pos.y);
			}
			else {
				spriteRectangle.setPosition(pos.x+temp*currentKeyIndice, pos.y);
			}
		}
		else {
			spriteRectangle.setPosition(pos.x, pos.y);
		}
	}

	for (int i = currentKeyIndice; i < n; i++) {
		if (isBoss) {
			keyItemList[i].setPosition(pos.x + (i - currentKeyIndice)*(centfloatx/4), pos.y - centfloaty/4);
		}
		else {
			keyItemList[i].setPosition(pos.x + (i - currentKeyIndice)*(centfloatx/4), pos.y - centfloaty/4);
		}
	}
}

void Cloud::update(float time) {
	TextureManagerSingleton &manager = TextureManagerSingleton::Instance();
	if (!isEntered) {
		auto pos = spriteImage.getPosition();
		float y = pos.y;
		y -= time*((float)manager.getWidth()*150/600);

		float yValue = (float)manager.getWidth()*450/600;
		if (isBoss) {
			yValue -= (float)manager.getWidth()*100/600;
			y -= time*((float)manager.getWidth() * 150 / 600);
		}
		if (y <= yValue) {
			y = yValue;
			isEntered = true;
		}
		spriteImage.setPosition(pos.x, y);
		update();
	} else 	if (!isDone()) {
		auto pos = spriteImage.getPosition();
		float x = pos.x;
		float factSlow = 1;
		if (timer < 1) {
			factSlow = 0.5;
			timer += time;
		}

		if (isRight) {
			x -= time*speed*factSlow;
		}
		else {
			x += time*speed*factSlow;
		}


		spriteImage.setPosition(x, pos.y);

		update();
	}
	else {
		auto pos = spriteImage.getPosition();
		float y = pos.y;
		y -= time*((float)manager.getWidth()*150/600);
		
		spriteImage.setPosition(pos.x, y);
		if (y <= -((float)manager.getWidth()*200/600)) {
			isTimeOut = true;
		}
	}
}

void Cloud::draw(sf::RenderTarget &target) {
	spriteImage.draw(target);
	spriteRectangle.draw(target);
	

	
}
void Cloud::drawLetter(sf::RenderTarget &target) {
	if (isEntered) {
		int n = (int)keyItemList.size();
		int number = 4;
		if (isBoss) {
			number = 8;
		}

		n = min(number + currentKeyIndice, n);
		for (int i = currentKeyIndice; i < (n); i++) {
			keyItemList[i].draw(target);
		}
	}
}

void Cloud::setPosition(float x, float y) {
	spriteImage.setPosition(x, y);
}

void Cloud::setSize(float x, float y) {
	spriteImage.setSize(x, y);
}

void Cloud::setColor(sf::Color newcolor) {
	color = newcolor;
}

void Cloud::setAlterKeyList(std::vector<enum sf::Keyboard::Key> keyList) {
	alterKeyList.resize(keyList.size());

	for (int i = 0; i < (int)keyList.size(); i++) {
		alterKeyList[i] = keyList[i];
	}
}


sf::Vector2f Cloud::getPosition() {
	return spriteImage.getPosition();
}

sf::Vector2f Cloud::getSize() {
	return spriteImage.getSize();
}

sf::Color Cloud::getColor() {
	return color;
}

std::vector<enum sf::Keyboard::Key> Cloud::getAlterKeyList() {
	return alterKeyList;
}


void Cloud::setSprite(std::string newSpritePath) {
	spriteImage.setSprite(newSpritePath);
}

void Cloud::setTexture(std::string texture) {
	TextureManagerSingleton &manager = TextureManagerSingleton::Instance();
	spriteImage.setSize((float)manager.getHeight()*100/1200, (float)manager.getWidth()*100/675);
	spriteImage.setTexture(texture);

	
	spriteRectangle.setColor(color);
}

void Cloud::setSpeed(float newSpeed) {
	speed = newSpeed;
}

void Cloud::setIsRight(bool newBool) {
	isRight = newBool;
	TextureManagerSingleton &manager = TextureManagerSingleton::Instance();
	if (newBool) {
		auto pos = getPosition();
		setPosition((float)manager.getHeight() - pos.x - spriteImage.getSize().x, pos.y);
	}
	update();
}
bool Cloud::getIsRight() {
	return isRight;
}

bool Cloud::getIsBoss() {
	return isBoss;
}

void Cloud::setIsBoss(bool newBool) {
	isBoss = newBool;
	TextureManagerSingleton &manager = TextureManagerSingleton::Instance();
	if (isBoss) {
		setSize((float)manager.getHeight()*200/1200, (float)manager.getWidth()*200/675);
		
	}
}

void Cloud::setCurrentKeyIndice(int newIndice) {
	currentKeyIndice = newIndice;
}

void Cloud::setIsDone() {
	setCurrentKeyIndice(getAlterKeyListSize());
	update();
}


int Cloud::getCurrentKeyIndice() {
	return currentKeyIndice;
}


void Cloud::addKey(char car) {
	if (car == 'A') {
		addKey(sf::Keyboard::A);
	}
	else if (car == 'B') {
		addKey(sf::Keyboard::B);
	}
	else if (car == 'C') {
		addKey(sf::Keyboard::C);
	}
	else if (car == 'D') {
		addKey(sf::Keyboard::D);
	}
	else if (car == 'E') {
		addKey(sf::Keyboard::E);
	}
	else if (car == 'F') {
		addKey(sf::Keyboard::F);
	}
	else if (car == 'G') {
		addKey(sf::Keyboard::G);
	}
	else if (car == 'H') {
		addKey(sf::Keyboard::H);
	}
	else if (car == 'I') {
		addKey(sf::Keyboard::I);
	}
	else if (car == 'J') {
		addKey(sf::Keyboard::J);
	}
	else if (car == 'K') {
		addKey(sf::Keyboard::K);
	}
	else if (car == 'L') {
		addKey(sf::Keyboard::L);
	}
	else if (car == 'M') {
		addKey(sf::Keyboard::M);
	}
	else if (car == 'N') {
		addKey(sf::Keyboard::N);
	}
	else if (car == 'O') {
		addKey(sf::Keyboard::O);
	}
	else if (car == 'P') {
		addKey(sf::Keyboard::P);
	}
	else if (car == 'Q') {
		addKey(sf::Keyboard::Q);
	}
	else if (car == 'R') {
		addKey(sf::Keyboard::R);
	}
	else if (car == 'S') {
		addKey(sf::Keyboard::S);
	}
	else if (car == 'T') {
		addKey(sf::Keyboard::T);
	}
	else if (car == 'U') {
		addKey(sf::Keyboard::U);
	}
	else if (car == 'V') {
		addKey(sf::Keyboard::V);
	}
	else if (car == 'W') {
		addKey(sf::Keyboard::W);
	}
	else if (car == 'X') {
		addKey(sf::Keyboard::X);
	}
	else if (car == 'Y') {
		addKey(sf::Keyboard::Y);
	}
	else if (car == 'Z') {
		addKey(sf::Keyboard::Z);
	}
	else {
		assert(false);
	}
}

void Cloud::addKey(sf::Keyboard::Key key) {
	alterKeyList.push_back(key);
	TextureManagerSingleton &manager = TextureManagerSingleton::Instance();
	SceneryItem newKeySprite;
	newKeySprite.setSize((float)manager.getHeight()*25/1200, (float)manager.getWidth()*25/675);
	newKeySprite.setPosition(0, 0);

	if (key == sf::Keyboard::A) {
		newKeySprite.setTexture("A.png");
	}
	else 	if (key == sf::Keyboard::B) {
		newKeySprite.setTexture("B.png");
	}
	else 	if (key == sf::Keyboard::C) {
		newKeySprite.setTexture("C.png");
	}
	else 	if (key == sf::Keyboard::D) {
		newKeySprite.setTexture("D.png");
	}
	else 	if (key == sf::Keyboard::E) {
		newKeySprite.setTexture("E.png");
	}
	else 	if (key == sf::Keyboard::F) {
		newKeySprite.setTexture("F.png");
	}
	else 	if (key == sf::Keyboard::G) {
		newKeySprite.setTexture("G.png");
	}
	else 	if (key == sf::Keyboard::H) {
		newKeySprite.setTexture("H.png");
	}
	else 	if (key == sf::Keyboard::I) {
		newKeySprite.setTexture("I.png");
	}
	else 	if (key == sf::Keyboard::J) {
		newKeySprite.setTexture("J.png");
	}
	else 	if (key == sf::Keyboard::K) {
		newKeySprite.setTexture("K.png");
	}
	else 	if (key == sf::Keyboard::L) {
		newKeySprite.setTexture("L.png");
	}
	else 	if (key == sf::Keyboard::M) {
		newKeySprite.setTexture("M.png");
	}
	else 	if (key == sf::Keyboard::N) {
		newKeySprite.setTexture("N.png");
	}
	else 	if (key == sf::Keyboard::O) {
		newKeySprite.setTexture("O.png");
	}
	else 	if (key == sf::Keyboard::P) {
		newKeySprite.setTexture("P.png");
	}
	else 	if (key == sf::Keyboard::Q) {
		newKeySprite.setTexture("Q.png");
	}
	else 	if (key == sf::Keyboard::R) {
		newKeySprite.setTexture("R.png");
	}
	else 	if (key == sf::Keyboard::S) {
		newKeySprite.setTexture("S.png");
	}
	else 	if (key == sf::Keyboard::T) {
		newKeySprite.setTexture("T.png");
	}
	else 	if (key == sf::Keyboard::U) {
		newKeySprite.setTexture("U.png");
	}
	else 	if (key == sf::Keyboard::V) {
		newKeySprite.setTexture("V.png");
	}
	else 	if (key == sf::Keyboard::W) {
		newKeySprite.setTexture("W.png");
	}
	else 	if (key == sf::Keyboard::X) {
		newKeySprite.setTexture("X.png");
	}
	else 	if (key == sf::Keyboard::Y) {
		newKeySprite.setTexture("Y.png");
	}
	else 	if (key == sf::Keyboard::Z) {
		newKeySprite.setTexture("Z.png");
	}
	else {
		cout << "Ton ennemi n'a aucun sens" << endl;
	}

	keyItemList.push_back(newKeySprite);
}




int Cloud::getAlterKeyListSize() {
	return alterKeyList.size();
}


bool Cloud::tryKeyInput(sf::Keyboard::Key key) {
	if (!isDone()) {
		if (key == alterKeyList[currentKeyIndice]) {
			currentKeyIndice++;
			timer = 0;
			update();
			return true;
		}
		else {
			timer = 1;
			return false;
		}
	}
	return false;
}


bool Cloud::getIsTimeOut() {
	return isTimeOut;
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

bool Cloud::isDone() {
	return (getCurrentKeyIndice() == getAlterKeyListSize());
}
