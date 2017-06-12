#include "CloudBoss5.h"
#include "SceneryRectangleBasic.h"


CloudBoss5::CloudBoss5() {
	init();



	setColor(sf::Color(155, 0, 100)); // Setting color of the easy cloud to green

	setTexture("CloudBoss5.png");

	setIsBoss(true);



	

	addKey(sf::Keyboard::K);
	addKey(sf::Keyboard::S);
	addKey(sf::Keyboard::M);
	addKey(sf::Keyboard::P);
	addKey(sf::Keyboard::I);

	addKey(sf::Keyboard::B);
	addKey(sf::Keyboard::H);
	addKey(sf::Keyboard::C);
	addKey(sf::Keyboard::W);
	addKey(sf::Keyboard::U);

	

	addKey(sf::Keyboard::T);
	addKey(sf::Keyboard::D);
	addKey(sf::Keyboard::A);
	addKey(sf::Keyboard::G);
	addKey(sf::Keyboard::Y);

	addKey(sf::Keyboard::E);
	addKey(sf::Keyboard::L);
	addKey(sf::Keyboard::O);
	addKey(sf::Keyboard::Z);
	addKey(sf::Keyboard::R);
	





	update();
}

CloudBoss5::~CloudBoss5() {

}


bool CloudBoss5::isDone() {
	return (getCurrentKeyIndice() == getAlterKeyListSize());
}
