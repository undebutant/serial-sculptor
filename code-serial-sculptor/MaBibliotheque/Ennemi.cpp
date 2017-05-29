#include "Ennemi.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <sstream>

void Ennemi::draw(sf::RenderTarget &target) {

	target.draw(shape);
}

std::ostream& operator<<(std::ostream &strm, const Ennemi &a) {
	std::stringstream keys;
	for (int i = 0; i < (int) a.keyVector.size(); i++) {
		if (i != 0) {
			keys << ",";
		}
		keys << "[" << i << "] : ";
		char ch = a.keyVector[i] + 65;
		keys << ch;
		
	}

	return strm << "Ennemi (Color : "<<a.color<<", keyVector.size = " << a.keyVector.size()<< ","<< keys.str() <<")";
}

void Ennemi::setColor(std::string newcolor) {
	color = newcolor;
}

std::string Ennemi::getColor() {
	return color;
}
int Ennemi::getIndice() {
	return indice;
}

int Ennemi::getSize() {
	return keyVector.size();
}

void Ennemi::addKey(sf::Keyboard::Key key) {
	keyVector.push_back(key);
}

bool Ennemi::tryDestroy(sf::Keyboard::Key key) {
	if (!isDead()) {
		if (key == keyVector[indice]) {
			indice++;
			return true;
		}
		else {
			return false;
		}

	}
	return false;
}

Ennemi::Ennemi() : indice(0)
{
}


Ennemi::~Ennemi()
{
}
