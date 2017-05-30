#include "Drawing.h"


using namespace std;
using namespace sf;


Drawing::Drawing() {

}

Drawing::~Drawing() {

}


void Drawing::drawList(vector<Item> &listItemsToDraw, sf::RenderTarget &target) {
	for (auto itemToDraw : listItemsToDraw) {
		itemToDraw.draw(target);
	}
}
