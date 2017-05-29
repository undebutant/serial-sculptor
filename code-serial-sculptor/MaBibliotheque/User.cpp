#include "User.h"

void User::draw(sf::RenderTarget &target) {
	
	target.draw(shape);
}

int User::getHealth() {
	return health;
}
void User::setHealth(int a) {
	health = a;
}

void User::incrHealth(int a) {
	if (health != 0) {
		int b = health + a;
		if (b > 100) {
			b = 100;
		}

		health = b;
	}
}

void User::decrHealth(int a) {
	int b = health - a;
	if (b < 0) {
		b = 0;
	}

	health = b;
}

User::User() : health(100)
{
}


User::~User()
{
}
