#include <iostream>

#include "TextureManager.h"
#include "Engine.h"
#include <c:/Software/pugixml-1.8/src/pugixml.hpp>


using namespace std;
using namespace sf;


int monMain()
{
	char source[] = "init.xml";
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file(source);
	if (result)
	{
		std::cout << "XML [" << source << "] parsed without errors, attr value: [" << doc.child("node").attribute("attr").value() << "]\n\n";
	}
	else
	{
		int tab[4] = { 0, 0, 0, 0 };



		auto root = doc.append_child("Root");
		pugi::xml_node nodeArray = root.append_child("Array");
		nodeArray.append_attribute("hs0") = tab[0];
		nodeArray.append_attribute("hs1") = tab[1];
		nodeArray.append_attribute("hs2") = tab[2];
		nodeArray.append_attribute("hs3") = tab[3];



		pugi::xml_node nodeHard = root.append_child("HardMode");
		nodeHard.append_attribute("isHardMode") = false;

		doc.save_file(source);
	}


	int tab[4];

	auto rootLoad = doc.child("Root");
	auto arrayLoad = rootLoad.child("Array");
	
	tab[0] = arrayLoad.attribute("hs0").as_int();
	tab[1] = arrayLoad.attribute("hs1").as_int();
	tab[2] = arrayLoad.attribute("hs2").as_int();
	tab[3] = arrayLoad.attribute("hs3").as_int();

	auto hardLoad = rootLoad.child("HardMode");

	bool hardMode = hardLoad.attribute("isHardMode").as_bool();

	

	Engine mainEngine = Engine(hardMode);
	mainEngine.setHighScore(tab);
	mainEngine.launchMainMenu();

	mainEngine.getHighScore(tab);

	

	arrayLoad.attribute("hs0") = tab[0];
	arrayLoad.attribute("hs1") = tab[1];
	arrayLoad.attribute("hs2") = tab[2];
	arrayLoad.attribute("hs3") = tab[3];
	
	doc.save_file(source);

	return 0;
}
