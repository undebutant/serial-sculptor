#include "CloudEasy8.h"
#include "SceneryRectangleBasic.h"


CloudEasy8::CloudEasy8() {
	init();
	setColor(sf::Color(0, 0, 255)); // Setting color of the easy cloud to green

	setTexture("CloudEasy8.png");



	addKey(sf::Keyboard::P);
	addKey(sf::Keyboard::A);
	addKey(sf::Keyboard::C);
	addKey(sf::Keyboard::M);
	addKey(sf::Keyboard::A);
	addKey(sf::Keyboard::N);



	update();
}

CloudEasy8::~CloudEasy8() {

}


bool CloudEasy8::isDone() {
	return (getCurrentKeyIndice() == getAlterKeyListSize());
}
