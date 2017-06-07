#include "SceneryItem.h"
#include <iostream>

using namespace std;

SceneryItem::SceneryItem() {

}

SceneryItem::~SceneryItem() {

}


void SceneryItem::draw(sf::RenderTarget &target) {
	
	target.draw(shape);
}

void SceneryItem::setTexture(std::string texture) {
	
	
	
	
	shape.setTexture(getTexture(texture));
		
	
}

void SceneryItem::setColor(sf::Color newColor) {
	shape.setFillColor(newColor);
}

void SceneryItem::setPath(std::string newPath) {
	pathToSprite = newPath;
}

void SceneryItem::setPosition(float x, float y) {
	shape.setPosition(x, y);
}

sf::Vector2f SceneryItem::getPosition() {
	return shape.getPosition();
}

void SceneryItem::setSize(float x, float y) {
	sf::Vector2f newShapeSize(x, y);
	shape.setSize(newShapeSize);
}

sf::Vector2f SceneryItem::getSize() {
	return shape.getSize();
}


void SceneryItem::setSprite(std::string newSpritePath) {
	pathToSprite = newSpritePath;
}
