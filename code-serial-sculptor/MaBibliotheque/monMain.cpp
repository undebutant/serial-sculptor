#include <iostream>

#include "Sculptor.h"
#include "CloudBoss1.h"
#include "CloudBoss2.h"
#include "CloudBoss3.h"
#include "CloudBoss4.h"
#include "CloudBoss5.h"
#include "CloudBoss6.h"
#include "CloudEasy1.h"
#include "CloudEasy2.h"
#include "CloudEasy3.h"
#include "CloudEasy4.h"
#include "CloudEasy5.h"
#include "CloudEasy6.h"
#include "CloudEasy7.h"
#include "CloudEasy8.h"
#include "CloudEasy9.h"
#include "CloudEasy10.h"
#include "monMain.h"
#include "SceneryRectangleBasic.h"
#include "SceneryItem.h"

#include "Engine.h"

using namespace std;
using namespace sf;




map<string, sf::Texture> textureLoaded;



sf::Texture *getTexture(std::string texture) {

	return &(textureLoaded[texture]);
}

void loadTexture() {
	sf::Texture mytexture;
	if (!mytexture.loadFromFile("sprite\\chaton.png"))
	{
		cout << "bug texture" << endl;
		// erreur...
	}
	else {
		cout << "Texture charge : " << "chaton.png" << endl;
		textureLoaded["chaton.png"] = mytexture;
	}



	for (int i = 1; i <= 6; i++) {
		sf::Texture mytexture;
		std::string path = "sprite\\";
		std::string name;
		name = "CloudBoss";
		std::string str = std::to_string(i);
		name = name + str;
		name = name + ".png";
		path = path + name;
		cout << endl;
		cout << path << endl;
		if (!mytexture.loadFromFile(path))
		{
			cout << "bug texture" << endl;
			// erreur...
		}
		else {
			cout << "Texture charge : " << name << endl;
			textureLoaded[name] = mytexture;
		}
	}

	for (int i = 1; i <= 10; i++) {
		sf::Texture mytexture;
		std::string path = "sprite\\";
		std::string name;
		name = "CloudEasy";
		std::string str = std::to_string(i);
		name = name + str;
		name = name + ".png";
		path = path + name;
		cout << endl;
		cout << path << endl;
		if (!mytexture.loadFromFile(path))
		{
			cout << "bug texture" << endl;
			// erreur...
		}
		else {
			cout << "Texture charge : " << name << endl;
			textureLoaded[name] = mytexture;
		}
	}

	for (char i = 'A'; i <= 'Z'; i++) {
		sf::Texture mytexture;
		std::string path = "sprite\\";
		std::string name;
		name.push_back(i);
		name = name + ".png";
		path = path + name;
		cout << endl;
		cout << path << endl;
		if (!mytexture.loadFromFile(path))
		{
			cout << "bug texture" << endl;
			// erreur...
		}
		else {
			cout << "Texture charge : " << name << endl;
			textureLoaded[name] = mytexture;
		}
	}
}


int monMain()
{
	Engine mainEngine = Engine();
	mainEngine.launchMainMenu();





	loadTexture();
	Cloud* cloud = new CloudBoss1;
	int number = 2;
	


	

	sf::RenderWindow window(sf::VideoMode(800, 800), "serial scultor");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	sf::Clock clock;
	bool isRight = true;
	bool chat = false;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed) {
				
				bool a;
				a = cloud->tryKeyInput(event.key.code);
				
			}
		}
		window.clear();



		float time = clock.restart().asSeconds();

		
		cloud->update(time);
		if (cloud->isDone()) {
			if (cloud->isTimeOut()) {
				if (number == 1) {
					cloud = new CloudBoss1;

				}
				else  if (number == 2) {
					cloud = new CloudBoss2;

				}
				else if (number == 3) {
					cloud = new CloudBoss3;

				}
				else if (number == 4) {
					cloud = new CloudBoss4;

				}
				else if (number == 5) {
					cloud = new CloudBoss5;

				}
				else if (number == 6) {
					cloud = new CloudBoss6;

				}
				else if (number == 7) {
					cloud = new CloudEasy1;

				}
				else if (number == 8) {
					cloud = new CloudEasy2;
				}
				else if (number == 9) {
					cloud = new CloudEasy3;

				}
				else if (number == 10) {
					cloud = new CloudEasy4;

				}
				else if (number == 11) {
					cloud = new CloudEasy5;

				}
				else if (number == 12) {
					cloud = new CloudEasy6;

				}
				else if (number == 13) {
					cloud = new CloudEasy7;

				}
				else if (number == 14) {
					cloud = new CloudEasy8;

				}
				else if (number == 15) {
					cloud = new CloudEasy9;

				}
				else if (number == 16) {
					cloud = new CloudEasy10;

				}

				cloud->setIsRight(isRight);
				isRight = !isRight;

				number++;
				if (number == 17) {
					number = 1;

				}
			}
		}
		cloud->draw(window);






		window.display();
	}
	return 0;
}
