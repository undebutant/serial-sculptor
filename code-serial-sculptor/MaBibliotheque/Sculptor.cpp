#include "Sculptor.h"


Sculptor::Sculptor() {

}

Sculptor::~Sculptor() {

}


bool Sculptor::isGameOver() {
	return (getHealth() == 0);
}
