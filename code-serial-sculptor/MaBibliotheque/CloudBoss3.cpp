#include "CloudBoss3.h"
#include "SceneryRectangleBasic.h"


CloudBoss3::CloudBoss3() {
	init();



	setColor(sf::Color(0, 0, 255)); // Setting color of the easy cloud to green

	setTexture("CloudBoss3.png");

	setIsBoss(true);



	addKey(sf::Keyboard::G);
	addKey(sf::Keyboard::U);
	addKey(sf::Keyboard::I);
	addKey(sf::Keyboard::L);
	addKey(sf::Keyboard::L);
	addKey(sf::Keyboard::A);
	addKey(sf::Keyboard::U);
	addKey(sf::Keyboard::M);
	addKey(sf::Keyboard::E);
	


	addKey(sf::Keyboard::G);
	addKey(sf::Keyboard::O);
	addKey(sf::Keyboard::N);
	addKey(sf::Keyboard::T);
	addKey(sf::Keyboard::H);
	addKey(sf::Keyboard::I);
	addKey(sf::Keyboard::E);
	addKey(sf::Keyboard::R);




	update();
}

CloudBoss3::~CloudBoss3() {

}


bool CloudBoss3::isDone() {
	return (getCurrentKeyIndice() == getAlterKeyListSize());
}
