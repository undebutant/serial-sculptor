#include <iostream>

#include "Sculptor.h"
#include "CloudBoss1.h"
#include "CloudEasy1.h"
#include "monMain.h"
#include "SceneryRectangleBasic.h"
#include "SceneryItem.h"

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
	
	loadTexture();

	CloudBoss1 cloud1;
	cloud1.setIsRight(false);

	
	CloudEasy1 cloud2;
	cloud2.setIsRight(false);
	

	cout << cloud1 << "\n" << endl;

	sf::RenderWindow window(sf::VideoMode(800, 800), "serial scultor");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	sf::Clock clock;
	bool isRight= true;
	bool chat = false;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Return) {
					
					
						if ((cloud1.isDone()&&(!chat)) || (cloud2.isDone() && (chat))) {
							if (chat) {
								CloudEasy1 cloud2New;
								cloud2New.setIsRight(isRight);
								isRight = !isRight;
								cloud2 = cloud2New;


							}
							else {
								CloudBoss1 cloud1New;
								cloud1New.setIsRight(isRight);
								isRight = !isRight;
								cloud1 = cloud1New;
							}
							if (isRight) {
								
									chat = !chat;
							}

							
						} 
						
					

					

					
				}
				else {
					bool a;
					if (chat) {
						a = cloud2.tryKeyInput(event.key.code);
					}
					else {
						a = cloud1.tryKeyInput(event.key.code);
					}
					cout << "La touche appuyee est-elle correcte (0 pour non, 1 pour oui) ?" << endl;
					cout << "Resultat : " << a << endl;

					if (chat) {
						a = cloud2.isDone();
					}
					else {
						a = cloud1.isDone();
					}
					cout << "Ennemie mort (0 pour non, 1 pour oui) ?" << endl;
					cout << "Resultat : " << a << endl;

				}
			}
		}
		window.clear();
		
		
		
		float time = clock.restart().asSeconds();

		
		if (chat) {
			
			cloud2.update(time);
			cloud2.draw(window);
		}
		else {
			
			cloud1.update(time);
			cloud1.draw(window);
		}
		
		



		
		window.display();
	}
	return 0;
}
