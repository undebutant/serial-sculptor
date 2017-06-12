#include "CloudBoss2.h"
#include "SceneryRectangleBasic.h"


CloudBoss2::CloudBoss2() {
	init();



	setColor(sf::Color(0, 255, 0)); // Setting color of the easy cloud to green

	setTexture("CloudBoss2.png");

	setIsBoss(true);



	addKey(sf::Keyboard::L);
	addKey(sf::Keyboard::O);
	addKey(sf::Keyboard::U);
	addKey(sf::Keyboard::I);
	addKey(sf::Keyboard::S);

	addKey(sf::Keyboard::B);
	addKey(sf::Keyboard::A);
	addKey(sf::Keyboard::P);
	addKey(sf::Keyboard::T);
	addKey(sf::Keyboard::I);
	addKey(sf::Keyboard::S);
	addKey(sf::Keyboard::T);
	addKey(sf::Keyboard::E);

	addKey(sf::Keyboard::T);
	addKey(sf::Keyboard::R);
	addKey(sf::Keyboard::A);
	addKey(sf::Keyboard::I);
	addKey(sf::Keyboard::L);
	addKey(sf::Keyboard::I);
	addKey(sf::Keyboard::N);





	update();
}

CloudBoss2::~CloudBoss2() {

}


bool CloudBoss2::isDone() {
	return (getCurrentKeyIndice() == getAlterKeyListSize());
}
