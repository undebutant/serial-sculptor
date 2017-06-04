#include <iostream>

#include "Sculptor.h"
#include "CloudEasy.h"
#include "monMain.h"
#include "SceneryRectangleBasic.h"
#include "SceneryItem.h"

using namespace std;
using namespace sf;


int monMain()
{
	CloudEasy cloud1;
	cloud1.setIsRight(false);

	

	

	cout << cloud1 << "\n" << endl;

	sf::RenderWindow window(sf::VideoMode(800, 800), "serial scultor");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed) {
				bool a = cloud1.tryKeyInput(event.key.code);
				cout << "La touche appuyee est-elle correcte (0 pour non, 1 pour oui) ?" << endl;
				cout << "Resultat : " << a << endl;

				cout << "Le nuage a-t-il ete sculpte totalement (0 pour non, 1 pour oui) ?" << endl;
				cout << "Resultat : " << cloud1.isDone() << "\n" << endl;
			}
		}
		window.clear();
		cloud1.draw(window);
		window.display();
	}
	return 0;
}
