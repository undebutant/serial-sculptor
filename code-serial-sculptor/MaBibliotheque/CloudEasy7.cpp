#include "CloudEasy7.h"
#include "SceneryRectangleBasic.h"


CloudEasy7::CloudEasy7() {
	init();
	setColor(sf::Color(200, 055, 0)); // Setting color of the easy cloud to green

	setTexture("CloudEasy7.png");



	addKey(sf::Keyboard::L);
	addKey(sf::Keyboard::O);
	addKey(sf::Keyboard::L);




	update();
}

CloudEasy7::~CloudEasy7() {

}


bool CloudEasy7::isDone() {
	return (getCurrentKeyIndice() == getAlterKeyListSize());
}
