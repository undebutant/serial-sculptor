#include "SceneryRectangleBasic.h"


using namespace std;

void SceneryRectangleBasic::setNewColor(sf::Color newcolor) {
	setColor(newcolor);
}
SceneryRectangleBasic::SceneryRectangleBasic()
{
	setPath("test");
	setPosition(10,20);
	setSize(100,100);
	setColor(sf::Color::Green);
	
	
}



SceneryRectangleBasic::~SceneryRectangleBasic()
{
}
