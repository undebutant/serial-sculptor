#include "Graphic.h"
#include "Drawing.h"


using namespace std;
using namespace sf;


Graphic::Graphic() {

}


Graphic::~Graphic() {

}


void Graphic::initWindow(RenderTarget &target, vector<Item> &listOfSceneryItems, vector<Item> &listOfActiveItems) {
	//Drawing.drawList(target, listOfSceneryItems);
}


void Graphic::updateWindow(RenderTarget &target, vector<Item> &listOfSceneryItems, vector<Item> &listOfActiveItems) {

}

void Graphic::updateForInterruption(RenderTarget &target, vector<Item> &listOfActiveItems) {

}
