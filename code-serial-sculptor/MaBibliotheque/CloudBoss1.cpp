#include "CloudBoss1.h"
#include "SceneryRectangleBasic.h"


CloudBoss1::CloudBoss1() {
	setColor(sf::Color(255, 0, 0)); // Setting color of the easy cloud to green
	setIsRight(false);
	setPosition(10, 10);
	setSpeed(10.0);
	setTexture("chaton.png");
	

	addKey(sf::Keyboard::P);
	addKey(sf::Keyboard::S);
	addKey(sf::Keyboard::M);
	addKey(sf::Keyboard::C);
	addKey(sf::Keyboard::R);

	addKey(sf::Keyboard::P);
	addKey(sf::Keyboard::S);
	addKey(sf::Keyboard::V);
	addKey(sf::Keyboard::C);
	addKey(sf::Keyboard::R);

	
	addKey(sf::Keyboard::P);
	addKey(sf::Keyboard::S);
	addKey(sf::Keyboard::C);
	addKey(sf::Keyboard::R);


	update();
}

CloudBoss1::~CloudBoss1() {

}


bool CloudBoss1::isDone() {
	return (getCurrentKeyIndice() == getAlterKeyListSize());
}
