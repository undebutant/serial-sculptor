#pragma once

#include <string>

#include "Item.h"
#include "SceneryItem.h"
#include "SceneryRectangleBasic.h"



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
	void setIsBoss(bool newBool);
	void setCurrentKeyIndice(int newIndice);
	void setIsDone();
	
	bool getIsRight();
	bool getIsBoss();
	int getCurrentKeyIndice();
	
	void addKey(enum sf::Keyboard::Key key);
	void addKey(char car);
	

	int getAlterKeyListSize();

	bool tryKeyInput(enum sf::Keyboard::Key key);

	virtual bool isDone();
	bool getIsTimeOut();
	

private:
	friend std::ostream& operator<<(std::ostream&, const Cloud&);

	SceneryItem spriteImage;
	SceneryRectangleBasic spriteRectangle;
	std::vector<SceneryItem> keyItemList;

	float timer = 1;
	float speed;

	bool isTimeOut;
	bool isEntered;
	bool isRight;
	bool isBoss;

	sf::Color color;

	int currentKeyIndice;
	std::vector<enum sf::Keyboard::Key> alterKeyList;
};
