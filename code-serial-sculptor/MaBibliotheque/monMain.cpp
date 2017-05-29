#include <SFML/Graphics.hpp>
#include <iostream>
#include "Item.h"
#include "User.h"
#include "Scultor.h"
#include "Ennemi.h"
#include "Ennemi1.h"
#include "monMain.h"



using namespace std;
using namespace sf;

int monMain()
{



	Ennemi1 ennemi1;

	cout << ennemi1 << endl;

	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
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
				bool a = ennemi1.tryDestroy(event.key.code);
				cout << "Good key : ?" << endl;
				cout << a << endl;

				cout << "Ennemi Dead : " << ennemi1.isDead() << endl;

			}
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}