#include "Config.h"


void Config::setIsBoss(bool newBool) {
	isBoss = newBool;
}
bool Config::getIsBoss() {
	return isBoss;
}

void Config::setRed(int newRed) {
	red = newRed;
}
int Config::getRed() {
	return red;
}

void Config::setGreen(int newGreen) {
	green = newGreen;
}
int Config::getGreen() {
	return green;
}

void Config::setBlue(int newBlue) {
	blue = newBlue;
}
int Config::getBlue() {
	return blue;
}

void Config::setSprite(std::string newString) {
	sprite = newString;
}
std::string Config::getSprite() {
	return sprite;
}

void Config::addKeyChar(char newKeyChar) {
	vectorOfKeyChar.push_back(newKeyChar);
}
std::vector<char> Config::getVectorOfKeyChar() {
	return vectorOfKeyChar;
}


Config::Config()
{
}


Config::~Config()
{
}
