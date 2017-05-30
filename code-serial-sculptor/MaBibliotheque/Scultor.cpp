#include "Scultor.h"


Scultor::Scultor() {

}

Scultor::~Scultor() {

}


bool Scultor::isDead() {
	return (getHealth() == 0);
}
