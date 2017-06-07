#include <iostream>

#include "Sculptor.h"
#include "CloudBoss1.h"
#include "monMain.h"
#include "SceneryRectangleBasic.h"
#include "SceneryItem.h"

using namespace std;
using namespace sf;




map<string, sf::Texture> textureLoaded;

vector<Item*> vectorOfItem;

sf::Texture *getTexture(std::string texture) {
	
	return &(textureLoaded[texture]);
}




int monMain()
{
	sf::Texture mytexture;
	if (!mytexture.loadFromFile("sprite\\chaton.png"))
	{
		cout << "bug texture" << endl;
		// erreur...
	}
	else {
		cout << "Texture charge : " << "chaton.png"<< endl;
		textureLoaded["chaton.png"] = mytexture;
	}
	
	CloudBoss1 cloud1;
	cloud1.setIsRight(false);

	vectorOfItem.push_back(&cloud1);

	

	cout << cloud1 << "\n" << endl;

	sf::RenderWindow window(sf::VideoMode(800, 800), "serial scultor");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	sf::Clock clock;
	bool isRight= true;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Return) {
					
					vector<Item*> vectorOfItemTemp;

					for (int i = 0; i < (int)vectorOfItem.size();i++) {
						Item * item = vectorOfItem[i];
						Cloud * cloud = (Cloud *)item;
						if (cloud->isDone()) {
							CloudBoss1 cloud2;
							cloud2.setIsRight(isRight);
							isRight = !isRight;
							cloud1 = cloud2;

							
						} 
						vectorOfItemTemp.push_back(&cloud1);
					}

					vectorOfItem.swap(vectorOfItemTemp);

					
				}
				else {
					bool a = cloud1.tryKeyInput(event.key.code);
					cout << "La touche appuyee est-elle correcte (0 pour non, 1 pour oui) ?" << endl;
					cout << "Resultat : " << a << endl;

					cout << "Le nuage a-t-il ete sculpte totalement (0 pour non, 1 pour oui) ?" << endl;
					cout << "Resultat : " << cloud1.isDone() << "\n" << endl;
				}
			}
		}
		window.clear();
		
		
		
		float time = clock.restart().asSeconds();

		

		for (int i = 0; i < (int) vectorOfItem.size(); i++) {
			Item * item = vectorOfItem[i];
			item->update(time);

		}


		for (int i = 0; i < (int) vectorOfItem.size(); i++) {
			Item * item = vectorOfItem[i];
			item->draw(window);

		}


		
		window.display();
	}
	return 0;
}
