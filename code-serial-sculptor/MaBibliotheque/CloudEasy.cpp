#include "CloudEasy.h"


CloudEasy::CloudEasy() {
	setColor(sf::Color(0, 255, 0)); // Setting color of the easy cloud to green

	addKey(sf::Keyboard::A);
	addKey(sf::Keyboard::B);
	addKey(sf::Keyboard::C);
}

CloudEasy::~CloudEasy() {

}


bool CloudEasy::isDone() {
	return (getCurrentKeyIndice() == getAlterKeyListSize());
}
