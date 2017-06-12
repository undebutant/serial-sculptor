#include "Sculptor.h"


Sculptor::Sculptor() {
	init();
}

Sculptor::~Sculptor() {

}


bool Sculptor::isGameOver() {
	return (getHealth() == 0);
}
