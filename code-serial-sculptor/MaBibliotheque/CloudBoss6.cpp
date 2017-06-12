#include "CloudBoss6.h"
#include "SceneryRectangleBasic.h"


CloudBoss6::CloudBoss6() {
	init();



	setColor(sf::Color(0, 155, 100)); // Setting color of the easy cloud to green

	setTexture("CloudBoss6.png");

	setIsBoss(true);




	addKey(sf::Keyboard::T);
	addKey(sf::Keyboard::E);
	addKey(sf::Keyboard::L);
	addKey(sf::Keyboard::E);
	addKey(sf::Keyboard::C);
	addKey(sf::Keyboard::O);
	addKey(sf::Keyboard::M);

	addKey(sf::Keyboard::S);
	addKey(sf::Keyboard::U);
	addKey(sf::Keyboard::D);


	addKey(sf::Keyboard::G);
	addKey(sf::Keyboard::R);
	addKey(sf::Keyboard::E);
	addKey(sf::Keyboard::N);
	addKey(sf::Keyboard::O);
	addKey(sf::Keyboard::B);
	addKey(sf::Keyboard::L);
	addKey(sf::Keyboard::E);


	update();
}

CloudBoss6::~CloudBoss6() {

}


bool CloudBoss6::isDone() {
	return (getCurrentKeyIndice() == getAlterKeyListSize());
}
