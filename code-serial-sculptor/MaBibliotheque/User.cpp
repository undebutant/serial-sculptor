#include "User.h"
#include <iostream>
#include "TextureManager.h"


User::User() : health(3) {

}

User::~User() {

}

void User::updateTexture(bool isRight) {
	if (isRight) {
		sprite.setTexture("sculptor_right.png");
	}
	else {
		sprite.setTexture("sculptor_left.png");
	}

}

void User::init() {
	sprite.setTexture("sculptor_right.png");
	sprite.setSize((float)TextureManager::getHeight()*150/1200, (float)TextureManager::getWidth()*200/600);
	sprite.setPosition((float)TextureManager::getHeight()*525/1200, (float)TextureManager::getWidth()*400/600);
}

void User::update(float time) {
	//TODO
}

void User::draw(sf::RenderTarget &target) {
	sprite.draw(target);
}


void User::setPosition(float x, float y) {
	sprite.setPosition(x, y);
}

sf::Vector2f User::getPosition() {
	return sprite.getPosition();
}

void User::setSize(float x, float y) {
	sprite.setSize(x, y);
}

sf::Vector2f User::getSize() {
	return sprite.getSize();
}


void User::setSprite(std::string newSpritePath) {
	sprite.setSprite(newSpritePath);
}


int User::getHealth() {
	return health;
}

void User::setHealth(int a) {
	health = a;
}

void User::incrHealth(int a) {
	if (health != 0) {
		int b = health + a;
		if (b > 3) {
			b = 3;
		}

		health = b;
	}
}

void User::decrHealth(int a) {
	int b = health - a;
	if (b < 0) {
		b = 0;
	}

	health = b;
}
