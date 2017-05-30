#pragma once

#include <string>

#include "Item.h"
#include "SceneryItem.h"


class Cloud : public Item
{
public:
	Cloud();
	~Cloud();

	void draw(sf::RenderTarget &target);

	void setPosition(float x, float y);
	sf::Vector2f getPosition();
	void setSize(float x, float y);
	sf::Vector2f getSize();

	void setSprite(std::string pathToSprite);

	void setColor(sf::Color newcolor);
	sf::Color getColor();

	int getCurrentKeyIndice();
	void setAlterKeyList(std::vector<enum sf::Keyboard::Key> keyList);
	std::vector<enum sf::Keyboard::Key> getAlterKeyList();
	void addKey(enum sf::Keyboard::Key key);
	int getAlterKeyListSize();

	bool tryKeyInput(enum sf::Keyboard::Key key);
	virtual bool isDone() = 0;
	
private:
	friend std::ostream& operator<<(std::ostream&, const Cloud&);

	SceneryItem sprite;
	sf::Color color;
	int currentKeyIndice;
	std::vector<enum sf::Keyboard::Key> alterKeyList;
};
