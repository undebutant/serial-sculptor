#include "CloudEasy4.h"
#include "SceneryRectangleBasic.h"


CloudEasy4::CloudEasy4() {
	init();
	setColor(sf::Color(100, 055, 100)); // Setting color of the easy cloud to green

	setTexture("CloudEasy4.png");



	addKey(sf::Keyboard::T);
	addKey(sf::Keyboard::S);
	addKey(sf::Keyboard::P);




	update();
}

CloudEasy4::~CloudEasy4() {

}


bool CloudEasy4::isDone() {
	return (getCurrentKeyIndice() == getAlterKeyListSize());
}
