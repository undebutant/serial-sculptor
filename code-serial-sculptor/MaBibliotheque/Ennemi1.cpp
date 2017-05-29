#include "Ennemi1.h"

bool Ennemi1::isDead() {
	return (getIndice() == getSize());
}

Ennemi1::Ennemi1() 
{
	setColor("Red");
	addKey(sf::Keyboard::A);
	addKey(sf::Keyboard::B);
	addKey(sf::Keyboard::C);
}


Ennemi1::~Ennemi1()
{
}
