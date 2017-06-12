#include "CloudEasy10.h"
#include "SceneryRectangleBasic.h"


CloudEasy10::CloudEasy10() {
	init();
	setColor(sf::Color(255, 255, 255)); // Setting color of the easy cloud to green

	setTexture("CloudEasy10.png");

	addKey(sf::Keyboard::B);
	addKey(sf::Keyboard::B);
	addKey(sf::Keyboard::H);
	addKey(sf::Keyboard::W);
	addKey(sf::Keyboard::N);




	update();
}

CloudEasy10::~CloudEasy10() {

}


bool CloudEasy10::isDone() {
	return (getCurrentKeyIndice() == getAlterKeyListSize());
}
