#include "CloudEasy10.h"
#include "SceneryRectangleBasic.h"


CloudEasy10::CloudEasy10() {
	init();
	setColor(sf::Color(20, 20, 100)); // Setting color of the easy cloud to green

	setTexture("CloudEasy10.png");

	addKey(sf::Keyboard::C);
	addKey(sf::Keyboard::O);
	addKey(sf::Keyboard::V);
	addKey(sf::Keyboard::F);
	addKey(sf::Keyboard::E);
	addKey(sf::Keyboard::F);
	addKey(sf::Keyboard::E);



	update();
}

CloudEasy10::~CloudEasy10() {

}


bool CloudEasy10::isDone() {
	return (getCurrentKeyIndice() == getAlterKeyListSize());
}
