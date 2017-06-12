#include "CloudEasy9.h"
#include "SceneryRectangleBasic.h"


CloudEasy9::CloudEasy9() {
	init();
	setColor(sf::Color(255, 0, 0)); // Setting color of the easy cloud to green

	setTexture("CloudEasy9.png");



	addKey(sf::Keyboard::V);
	addKey(sf::Keyboard::V);
	addKey(sf::Keyboard::C);




	update();
}

CloudEasy9::~CloudEasy9() {

}


bool CloudEasy9::isDone() {
	return (getCurrentKeyIndice() == getAlterKeyListSize());
}
