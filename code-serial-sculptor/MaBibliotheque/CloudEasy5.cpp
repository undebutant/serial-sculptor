#include "CloudEasy5.h"
#include "SceneryRectangleBasic.h"


CloudEasy5::CloudEasy5() {
	init();
	setColor(sf::Color(200, 055, 0)); // Setting color of the easy cloud to green

	setTexture("CloudEasy5.png");



	addKey(sf::Keyboard::T);
	addKey(sf::Keyboard::E);
	addKey(sf::Keyboard::M);




	update();
}

CloudEasy5::~CloudEasy5() {

}


bool CloudEasy5::isDone() {
	return (getCurrentKeyIndice() == getAlterKeyListSize());
}
