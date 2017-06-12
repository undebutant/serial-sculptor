#include "CloudEasy2.h"
#include "SceneryRectangleBasic.h"


CloudEasy2::CloudEasy2() {
	init();
	setColor(sf::Color(0, 155, 100)); // Setting color of the easy cloud to green

	setTexture("CloudEasy2.png");



	addKey(sf::Keyboard::R);
	addKey(sf::Keyboard::C);
	addKey(sf::Keyboard::B);
	addKey(sf::Keyboard::O);

	update();
}

CloudEasy2::~CloudEasy2() {

}


bool CloudEasy2::isDone() {
	return (getCurrentKeyIndice() == getAlterKeyListSize());
}
