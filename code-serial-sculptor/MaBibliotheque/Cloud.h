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

	void update();
	void update(float time);
	void draw(sf::RenderTarget &target);
	void drawLetter(sf::RenderTarget &target);

	void setPosition(float x, float y);
	void setSize(float x, float y);
	void setColor(sf::Color newcolor);
	void setAlterKeyList(std::vector<enum sf::Keyboard::Key> keyList);

	sf::Vector2f getPosition();
	sf::Vector2f getSize();
	sf::Color getColor();
	std::vector<enum sf::Keyboard::Key> getAlterKeyList();

	void setSprite(std::string pathToSprite);
	void setTexture(std::string texture);
	void setSpeed(float newSpeed);
	void setIsRight(bool newBool);
	bool getIsRight();
	void setIsBoss(bool newBool);
	
	int getCurrentKeyIndice();
	
	void addKey(enum sf::Keyboard::Key key);
	void addSprite(SceneryItem newSprite);

	int getAlterKeyListSize();

	bool tryKeyInput(enum sf::Keyboard::Key key);

	virtual bool isDone() = 0;
	bool isTimeOut();
	

private:
	friend std::ostream& operator<<(std::ostream&, const Cloud&);

	SceneryItem spriteImage;
	std::vector<SceneryItem> spriteList;
	std::vector<SceneryItem> keyItemList;

	float timer = 1;
	float speed;

	bool isRight;
	bool isBoss;

	sf::Color color;

	int currentKeyIndice;
	std::vector<enum sf::Keyboard::Key> alterKeyList;
};
