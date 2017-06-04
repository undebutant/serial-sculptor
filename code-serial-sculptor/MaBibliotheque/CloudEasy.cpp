#include "CloudEasy.h"
#include "SceneryRectangleBasic.h"


CloudEasy::CloudEasy() {
	setColor(sf::Color(0, 255, 0)); // Setting color of the easy cloud to green
	setIsRight(false);
	setPosition(10,10);


	addKey(sf::Keyboard::A);
	SceneryRectangleBasic newSpriteA;
	newSpriteA.setColor(sf::Color::Green);
	addSprite(newSpriteA);
	addKey(sf::Keyboard::B);
	SceneryRectangleBasic newSpriteB;
	newSpriteB.setColor(sf::Color::Blue);
	addSprite(newSpriteB);
	addKey(sf::Keyboard::C);
	SceneryRectangleBasic newSpriteC;
	newSpriteC.setColor(sf::Color::Red);
	addSprite(newSpriteC);


	update();
}

CloudEasy::~CloudEasy() {

}


bool CloudEasy::isDone() {
	return (getCurrentKeyIndice() == getAlterKeyListSize());
}
