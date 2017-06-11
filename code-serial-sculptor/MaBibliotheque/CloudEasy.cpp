#include "CloudEasy.h"
#include "SceneryRectangleBasic.h"


CloudEasy::CloudEasy() {
	init();
	setColor(sf::Color(0, 255, 0)); // Setting color of the easy cloud to green
	
	setTexture("chaton.png");
	


	addKey(sf::Keyboard::B);
	addKey(sf::Keyboard::O);
	addKey(sf::Keyboard::M);
	addKey(sf::Keyboard::G);

	


	update();
}

CloudEasy::~CloudEasy() {

}


bool CloudEasy::isDone() {
	return (getCurrentKeyIndice() == getAlterKeyListSize());
}
