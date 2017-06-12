#include "User.h"
#include <iostream>


User::User() : health(3) {

}

User::~User() {

}

void User::init() {
	sprite.setTexture("sculptor_left.png");
	sprite.setSize(150,200);
	sprite.setPosition(525,400);
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
