#include "CloudBoss4.h"
#include "SceneryRectangleBasic.h"


CloudBoss4::CloudBoss4() {
	init();



	setColor(sf::Color(155, 100, 0)); // Setting color of the easy cloud to green

	setTexture("CloudBoss4.png");

	setIsBoss(true);


	addKey(sf::Keyboard::M);
	addKey(sf::Keyboard::I);
	addKey(sf::Keyboard::C);
	addKey(sf::Keyboard::H);
	addKey(sf::Keyboard::E);
	addKey(sf::Keyboard::L);

	addKey(sf::Keyboard::S);
	addKey(sf::Keyboard::I);
	addKey(sf::Keyboard::M);
	addKey(sf::Keyboard::A);
	addKey(sf::Keyboard::T);
	addKey(sf::Keyboard::I);
	addKey(sf::Keyboard::C);
	





	update();
}

CloudBoss4::~CloudBoss4() {

}


bool CloudBoss4::isDone() {
	return (getCurrentKeyIndice() == getAlterKeyListSize());
}
