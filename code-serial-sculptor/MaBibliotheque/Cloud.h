#pragma once

#include <string>

#include "Item.h"
#include "SceneryItem.h"


class Cloud : public Item
{
public:
	Cloud();
	~Cloud();
	
	void init();
	void setSpeed(float newSpeed);

	void update(float time);

	void draw(sf::RenderTarget &target);

	void setPosition(float x, float y);
	sf::Vector2f getPosition();
	void setSize(float x, float y);
	sf::Vector2f getSize();

	void setSprite(std::string pathToSprite);

	void setTexture(std::string texture);

	void setColor(sf::Color newcolor);
	sf::Color getColor();

	int getCurrentKeyIndice();
	void setAlterKeyList(std::vector<enum sf::Keyboard::Key> keyList);
	std::vector<enum sf::Keyboard::Key> getAlterKeyList();
	void addKey(enum sf::Keyboard::Key key);
	void addSprite(SceneryItem newSprite);

	int getAlterKeyListSize();

	bool tryKeyInput(enum sf::Keyboard::Key key);
	virtual bool isDone() = 0;
	void setIsRight(bool newBool);
	void update();
	void setIsBoss(bool newBool);

	
private:
	friend std::ostream& operator<<(std::ostream&, const Cloud&);

	SceneryItem spriteImage;
	std::vector<SceneryItem> spriteList;
	std::vector<SceneryItem> keyItemList;

	bool isRight;

	bool isBoss;

	float speed;

	sf::Color color;
	int currentKeyIndice;
	std::vector<enum sf::Keyboard::Key> alterKeyList;
};
