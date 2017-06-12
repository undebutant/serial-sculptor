#include "CloudEasy6.h"
#include "SceneryRectangleBasic.h"


CloudEasy6::CloudEasy6() {
	init();
	setColor(sf::Color(0, 055, 200)); // Setting color of the easy cloud to green

	setTexture("CloudEasy6.png");



	addKey(sf::Keyboard::I);
	addKey(sf::Keyboard::M);
	addKey(sf::Keyboard::T);




	update();
}

CloudEasy6::~CloudEasy6() {

}


bool CloudEasy6::isDone() {
	return (getCurrentKeyIndice() == getAlterKeyListSize());
}
