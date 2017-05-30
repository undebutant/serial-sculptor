#include <SFML/Graphics.hpp>

#include "gtest/gtest.h"
#include "../MaBibliotheque/Scultor.h"
#include "../MaBibliotheque/User.h"


TEST(Exemple1, ScultorCreated)
{
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	EXPECT_TRUE(shape.getRadius() == 100.f);
	EXPECT_TRUE(shape.getFillColor() == sf::Color::Green);
}
