#include "CloudEasy.h"
#include "SceneryRectangleBasic.h"


CloudEasy::CloudEasy() {
	setColor(sf::Color(0, 255, 0)); // Setting color of the easy cloud to green
	setIsRight(false);
	setPosition(10,10);


	addKey(sf::Keyboard::A);
	addKey(sf::Keyboard::B);
	addKey(sf::Keyboard::C);
	


	update();
}

CloudEasy::~CloudEasy() {

}


bool CloudEasy::isDone() {
	return (getCurrentKeyIndice() == getAlterKeyListSize());
}
