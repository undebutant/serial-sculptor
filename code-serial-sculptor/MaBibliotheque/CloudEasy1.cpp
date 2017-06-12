#include "CloudEasy1.h"
#include "SceneryRectangleBasic.h"


CloudEasy1::CloudEasy1() {
	init();
	setColor(sf::Color(0, 255, 0)); // Setting color of the easy cloud to green
	
	setTexture("CloudEasy1.png");
	


	addKey(sf::Keyboard::B);
	addKey(sf::Keyboard::O);
	addKey(sf::Keyboard::M);
	addKey(sf::Keyboard::G);

	


	update();
}

CloudEasy1::~CloudEasy1() {

}


bool CloudEasy1::isDone() {
	return (getCurrentKeyIndice() == getAlterKeyListSize());
}
