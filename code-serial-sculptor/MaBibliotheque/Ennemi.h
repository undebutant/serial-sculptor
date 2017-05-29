#pragma once
#include "Item.h"
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>





class Ennemi : public Item
{
public:
	void draw(sf::RenderTarget &target);
	bool tryDestroy(enum sf::Keyboard::Key key);
	virtual bool isDead() = 0;
	void setColor(std::string newcolor);
	std::string getColor();
	int getIndice();
	int getSize();
	void addKey(enum sf::Keyboard::Key key);
	Ennemi();
	~Ennemi();
	
private:
	std::string color;
	friend std::ostream& operator<<(std::ostream&, const Ennemi&);
	std::vector <enum sf::Keyboard::Key> keyVector;
	int indice;

	sf::RectangleShape shape;
};

