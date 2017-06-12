#include "CloudEasy3.h"
#include "SceneryRectangleBasic.h"


CloudEasy3::CloudEasy3() {
	init();
	setColor(sf::Color(100, 155, 0)); // Setting color of the easy cloud to green

	setTexture("CloudEasy3.png");



	addKey(sf::Keyboard::J);
	addKey(sf::Keyboard::I);
	addKey(sf::Keyboard::N);





	update();
}

CloudEasy3::~CloudEasy3() {

}


bool CloudEasy3::isDone() {
	return (getCurrentKeyIndice() == getAlterKeyListSize());
}
