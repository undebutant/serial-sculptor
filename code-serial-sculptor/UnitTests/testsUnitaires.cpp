#include "gtest/gtest.h"
#include "../MaBibliotheque/Scultor.h"
#include "../MaBibliotheque/User.h"
#include <SFML/Graphics.hpp>


TEST(Exemple1, ScultorCreated)
{
	
	Scultor scultor;

	EXPECT_FALSE(scultor.isDead());
	
}