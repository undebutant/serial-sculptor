#pragma once

#include <string>
#include <vector>

class Config
{
public:
	Config();
	~Config();

	void setIsBoss(bool newBool);
	bool getIsBoss();

	void setRed(int newRed);
	int getRed();

	void setGreen(int newGreen);
	int getGreen();

	void setBlue(int newBlue);
	int getBlue();

	void setSprite(std::string newString);
	std::string getSprite();

	void reserveVectorOfKeyChar(int n);

	void addKeyChar(char newKeyChar);
	std::vector<char> getVectorOfKeyChar();

private:
	bool isBoss;
	int red;
	int green;
	int blue;
	std::string sprite;
	std::vector<char> vectorOfKeyChar;
};

