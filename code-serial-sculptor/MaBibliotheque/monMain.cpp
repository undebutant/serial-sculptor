#include <iostream>

#include "TextureManager.h"
#include "Engine.h"


using namespace std;
using namespace sf;


int monMain()
{

	bool hardMod = false;

	Engine mainEngine = Engine(hardMod);
	mainEngine.launchMainMenu();

	return 0;
}
