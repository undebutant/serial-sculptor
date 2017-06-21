#include <iostream>

#include "TextureManager.h"
#include "Engine.h"
#include <c:/Software/pugixml-1.8/src/pugixml.hpp>


using namespace std;
using namespace sf;


int monMain()
{
	
	char config[] = "config.xml";
	pugi::xml_document docConfig;
	
	



	auto root = docConfig.append_child("Root");
	pugi::xml_node nodeCloud = root.append_child("Cloud");

	pugi::xml_node nodeImage = nodeCloud.append_child("Sprite");
	nodeImage.text().set("CloudEasy1.png");

	pugi::xml_node nodeBoss = nodeCloud.append_child("IsBoss");
	nodeBoss.text().set(false);

	pugi::xml_node nodeRed = nodeCloud.append_child("Red");
	nodeRed.text().set(0);

	pugi::xml_node nodeGreen = nodeCloud.append_child("Green");
	nodeGreen.text().set(255);

	pugi::xml_node nodeBlue = nodeCloud.append_child("Blue");
	nodeBlue.text().set(0);

	pugi::xml_node nodeImputArray = nodeCloud.append_child("ImputArray");

	pugi::xml_node node1 = nodeImputArray.append_child("Imput");
	node1.text().set("B");

	pugi::xml_node node2 = nodeImputArray.append_child("Imput");
	node2.text().set("O");

	pugi::xml_node node3 = nodeImputArray.append_child("Imput");
	node3.text().set("M");

	pugi::xml_node node4 = nodeImputArray.append_child("Imput");
	node4.text().set("G");

	

	nodeCloud = root.append_child("Cloud");

	nodeImage = nodeCloud.append_child("Sprite");
	nodeImage.text().set("CloudEasy2.png");

	nodeBoss = nodeCloud.append_child("IsBoss");
	nodeBoss.text().set(false);

	nodeRed = nodeCloud.append_child("Red");
	nodeRed.text().set(0);

	nodeGreen = nodeCloud.append_child("Green");
	nodeGreen.text().set(155);

	nodeBlue = nodeCloud.append_child("Blue");
	nodeBlue.text().set(100);

	nodeImputArray = nodeCloud.append_child("ImputArray");

	node1 = nodeImputArray.append_child("Imput");
	node1.text().set("R");

	node2 = nodeImputArray.append_child("Imput");
	node2.text().set("C");

	node3 = nodeImputArray.append_child("Imput");
	node3.text().set("B");

	node4 = nodeImputArray.append_child("Imput");
	node4.text().set("O");

	nodeCloud = root.append_child("Cloud");

	nodeImage = nodeCloud.append_child("Sprite");
	nodeImage.text().set("CloudEasy3.png");

	nodeBoss = nodeCloud.append_child("IsBoss");
	nodeBoss.text().set(false);

	nodeRed = nodeCloud.append_child("Red");
	nodeRed.text().set(100);

	nodeGreen = nodeCloud.append_child("Green");
	nodeGreen.text().set(155);

	nodeBlue = nodeCloud.append_child("Blue");
	nodeBlue.text().set(0);

	nodeImputArray = nodeCloud.append_child("ImputArray");

	node1 = nodeImputArray.append_child("Imput");
	node1.text().set("J");

	node2 = nodeImputArray.append_child("Imput");
	node2.text().set("I");

	node3 = nodeImputArray.append_child("Imput");
	node3.text().set("N");

	nodeCloud = root.append_child("Cloud");

	nodeImage = nodeCloud.append_child("Sprite");
	nodeImage.text().set("CloudEasy4.png");

	nodeBoss = nodeCloud.append_child("IsBoss");
	nodeBoss.text().set(false);

	nodeRed = nodeCloud.append_child("Red");
	nodeRed.text().set(100);

	nodeGreen = nodeCloud.append_child("Green");
	nodeGreen.text().set(55);

	nodeBlue = nodeCloud.append_child("Blue");
	nodeBlue.text().set(100);

	nodeImputArray = nodeCloud.append_child("ImputArray");

	node1 = nodeImputArray.append_child("Imput");
	node1.text().set("T");

	node2 = nodeImputArray.append_child("Imput");
	node2.text().set("S");

	node3 = nodeImputArray.append_child("Imput");
	node3.text().set("P");


	nodeCloud = root.append_child("Cloud");

	nodeImage = nodeCloud.append_child("Sprite");
	nodeImage.text().set("CloudEasy5.png");

	nodeBoss = nodeCloud.append_child("IsBoss");
	nodeBoss.text().set(false);

	nodeRed = nodeCloud.append_child("Red");
	nodeRed.text().set(200);

	nodeGreen = nodeCloud.append_child("Green");
	nodeGreen.text().set(55);

	nodeBlue = nodeCloud.append_child("Blue");
	nodeBlue.text().set(0);

	nodeImputArray = nodeCloud.append_child("ImputArray");

	node1 = nodeImputArray.append_child("Imput");
	node1.text().set("T");

	node2 = nodeImputArray.append_child("Imput");
	node2.text().set("E");

	node3 = nodeImputArray.append_child("Imput");
	node3.text().set("M");


	nodeCloud = root.append_child("Cloud");

	nodeImage = nodeCloud.append_child("Sprite");
	nodeImage.text().set("CloudEasy6.png");

	nodeBoss = nodeCloud.append_child("IsBoss");
	nodeBoss.text().set(false);

	nodeRed = nodeCloud.append_child("Red");
	nodeRed.text().set(0);

	nodeGreen = nodeCloud.append_child("Green");
	nodeGreen.text().set(55);

	nodeBlue = nodeCloud.append_child("Blue");
	nodeBlue.text().set(200);

	nodeImputArray = nodeCloud.append_child("ImputArray");

	node1 = nodeImputArray.append_child("Imput");
	node1.text().set("I");

	node2 = nodeImputArray.append_child("Imput");
	node2.text().set("M");

	node3 = nodeImputArray.append_child("Imput");
	node3.text().set("T");

	nodeCloud = root.append_child("Cloud");

	nodeImage = nodeCloud.append_child("Sprite");
	nodeImage.text().set("CloudEasy7.png");

	nodeBoss = nodeCloud.append_child("IsBoss");
	nodeBoss.text().set(false);

	nodeRed = nodeCloud.append_child("Red");
	nodeRed.text().set(200);

	nodeGreen = nodeCloud.append_child("Green");
	nodeGreen.text().set(55);

	nodeBlue = nodeCloud.append_child("Blue");
	nodeBlue.text().set(0);

	nodeImputArray = nodeCloud.append_child("ImputArray");

	node1 = nodeImputArray.append_child("Imput");
	node1.text().set("L");

	node2 = nodeImputArray.append_child("Imput");
	node2.text().set("O");

	node3 = nodeImputArray.append_child("Imput");
	node3.text().set("L");

	

	nodeCloud = root.append_child("Cloud");

	nodeImage = nodeCloud.append_child("Sprite");
	nodeImage.text().set("CloudEasy8.png");

	nodeBoss = nodeCloud.append_child("IsBoss");
	nodeBoss.text().set(false);

	nodeRed = nodeCloud.append_child("Red");
	nodeRed.text().set(0);

	nodeGreen = nodeCloud.append_child("Green");
	nodeGreen.text().set(0);

	nodeBlue = nodeCloud.append_child("Blue");
	nodeBlue.text().set(255);

	nodeImputArray = nodeCloud.append_child("ImputArray");

	node1 = nodeImputArray.append_child("Imput");
	node1.text().set("P");

	node2 = nodeImputArray.append_child("Imput");
	node2.text().set("A");

	node3 = nodeImputArray.append_child("Imput");
	node3.text().set("C");

	node4 = nodeImputArray.append_child("Imput");
	node4.text().set("M");

	node4 = nodeImputArray.append_child("Imput");
	node4.text().set("A");

	node4 = nodeImputArray.append_child("Imput");
	node4.text().set("N");

	nodeCloud = root.append_child("Cloud");

	nodeImage = nodeCloud.append_child("Sprite");
	nodeImage.text().set("CloudEasy9.png");

	nodeBoss = nodeCloud.append_child("IsBoss");
	nodeBoss.text().set(false);

	nodeRed = nodeCloud.append_child("Red");
	nodeRed.text().set(255);

	nodeGreen = nodeCloud.append_child("Green");
	nodeGreen.text().set(0);

	nodeBlue = nodeCloud.append_child("Blue");
	nodeBlue.text().set(0);

	nodeImputArray = nodeCloud.append_child("ImputArray");

	node1 = nodeImputArray.append_child("Imput");
	node1.text().set("V");

	node2 = nodeImputArray.append_child("Imput");
	node2.text().set("V");

	node3 = nodeImputArray.append_child("Imput");
	node3.text().set("C");

	nodeCloud = root.append_child("Cloud");

	nodeImage = nodeCloud.append_child("Sprite");
	nodeImage.text().set("CloudEasy10.png");

	nodeBoss = nodeCloud.append_child("IsBoss");
	nodeBoss.text().set(false);

	nodeRed = nodeCloud.append_child("Red");
	nodeRed.text().set(20);

	nodeGreen = nodeCloud.append_child("Green");
	nodeGreen.text().set(20);

	nodeBlue = nodeCloud.append_child("Blue");
	nodeBlue.text().set(100);

	nodeImputArray = nodeCloud.append_child("ImputArray");

	node1 = nodeImputArray.append_child("Imput");
	node1.text().set("C");

	node2 = nodeImputArray.append_child("Imput");
	node2.text().set("O");

	node3 = nodeImputArray.append_child("Imput");
	node3.text().set("V");

	node4 = nodeImputArray.append_child("Imput");
	node4.text().set("F");

	node4 = nodeImputArray.append_child("Imput");
	node4.text().set("E");

	node4 = nodeImputArray.append_child("Imput");
	node4.text().set("F");

	node4 = nodeImputArray.append_child("Imput");
	node4.text().set("E");

		
	nodeCloud = root.append_child("Cloud");

	nodeImage = nodeCloud.append_child("Sprite");
	nodeImage.text().set("CloudBoss1.png");

	nodeBoss = nodeCloud.append_child("IsBoss");
	nodeBoss.text().set(true);

	nodeRed = nodeCloud.append_child("Red");
	nodeRed.text().set(255);

	nodeGreen = nodeCloud.append_child("Green");
	nodeGreen.text().set(0);

	nodeBlue = nodeCloud.append_child("Blue");
	nodeBlue.text().set(0);

	nodeImputArray = nodeCloud.append_child("ImputArray");

	node1 = nodeImputArray.append_child("Imput");
	node1.text().set("P");

	node2 = nodeImputArray.append_child("Imput");
	node2.text().set("S");

	node3 = nodeImputArray.append_child("Imput");
	node3.text().set("M");

	node4 = nodeImputArray.append_child("Imput");
	node4.text().set("C");

	node4 = nodeImputArray.append_child("Imput");
	node4.text().set("R");

	node1 = nodeImputArray.append_child("Imput");
	node1.text().set("P");

	node2 = nodeImputArray.append_child("Imput");
	node2.text().set("S");

	node3 = nodeImputArray.append_child("Imput");
	node3.text().set("V");

	node4 = nodeImputArray.append_child("Imput");
	node4.text().set("C");

	node4 = nodeImputArray.append_child("Imput");
	node4.text().set("R");

	node1 = nodeImputArray.append_child("Imput");
	node1.text().set("P");

	node2 = nodeImputArray.append_child("Imput");
	node2.text().set("S");

	node4 = nodeImputArray.append_child("Imput");
	node4.text().set("C");

	node4 = nodeImputArray.append_child("Imput");
	node4.text().set("R");

	nodeCloud = root.append_child("Cloud");

	nodeImage = nodeCloud.append_child("Sprite");
	nodeImage.text().set("CloudBoss2.png");

	nodeBoss = nodeCloud.append_child("IsBoss");
	nodeBoss.text().set(true);

	nodeRed = nodeCloud.append_child("Red");
	nodeRed.text().set(0);

	nodeGreen = nodeCloud.append_child("Green");
	nodeGreen.text().set(255);

	nodeBlue = nodeCloud.append_child("Blue");
	nodeBlue.text().set(0);

	nodeImputArray = nodeCloud.append_child("ImputArray");

	node1 = nodeImputArray.append_child("Imput");
	node1.text().set("L");

	node2 = nodeImputArray.append_child("Imput");
	node2.text().set("O");

	node3 = nodeImputArray.append_child("Imput");
	node3.text().set("U");

	node4 = nodeImputArray.append_child("Imput");
	node4.text().set("I");

	node4 = nodeImputArray.append_child("Imput");
	node4.text().set("S");

	node1 = nodeImputArray.append_child("Imput");
	node1.text().set("B");

	node2 = nodeImputArray.append_child("Imput");
	node2.text().set("A");

	node3 = nodeImputArray.append_child("Imput");
	node3.text().set("P");

	node4 = nodeImputArray.append_child("Imput");
	node4.text().set("T");

	node4 = nodeImputArray.append_child("Imput");
	node4.text().set("I");

	node1 = nodeImputArray.append_child("Imput");
	node1.text().set("S");

	node2 = nodeImputArray.append_child("Imput");
	node2.text().set("T");

	node4 = nodeImputArray.append_child("Imput");
	node4.text().set("E");

	node4 = nodeImputArray.append_child("Imput");
	node4.text().set("T");

	node4 = nodeImputArray.append_child("Imput");
	node4.text().set("R");

	node1 = nodeImputArray.append_child("Imput");
	node1.text().set("A");

	node2 = nodeImputArray.append_child("Imput");
	node2.text().set("I");

	node4 = nodeImputArray.append_child("Imput");
	node4.text().set("L");

	node4 = nodeImputArray.append_child("Imput");
	node4.text().set("I");

	node4 = nodeImputArray.append_child("Imput");
	node4.text().set("N");

	nodeCloud = root.append_child("Cloud");

	nodeImage = nodeCloud.append_child("Sprite");
	nodeImage.text().set("CloudBoss3.png");

	nodeBoss = nodeCloud.append_child("IsBoss");
	nodeBoss.text().set(true);

	nodeRed = nodeCloud.append_child("Red");
	nodeRed.text().set(0);

	nodeGreen = nodeCloud.append_child("Green");
	nodeGreen.text().set(0);

	nodeBlue = nodeCloud.append_child("Blue");
	nodeBlue.text().set(255);

	nodeImputArray = nodeCloud.append_child("ImputArray");

	node1 = nodeImputArray.append_child("Imput");
	node1.text().set("G");

	node2 = nodeImputArray.append_child("Imput");
	node2.text().set("U");

	node3 = nodeImputArray.append_child("Imput");
	node3.text().set("I");

	node4 = nodeImputArray.append_child("Imput");
	node4.text().set("L");

	node4 = nodeImputArray.append_child("Imput");
	node4.text().set("L");

	node1 = nodeImputArray.append_child("Imput");
	node1.text().set("A");

	node2 = nodeImputArray.append_child("Imput");
	node2.text().set("U");

	node3 = nodeImputArray.append_child("Imput");
	node3.text().set("M");

	node4 = nodeImputArray.append_child("Imput");
	node4.text().set("E");

	node4 = nodeImputArray.append_child("Imput");
	node4.text().set("G");

	node1 = nodeImputArray.append_child("Imput");
	node1.text().set("O");

	node2 = nodeImputArray.append_child("Imput");
	node2.text().set("N");

	node4 = nodeImputArray.append_child("Imput");
	node4.text().set("T");

	node4 = nodeImputArray.append_child("Imput");
	node4.text().set("H");

	node4 = nodeImputArray.append_child("Imput");
	node4.text().set("I");

	node1 = nodeImputArray.append_child("Imput");
	node1.text().set("E");

	node2 = nodeImputArray.append_child("Imput");
	node2.text().set("R");

	nodeCloud = root.append_child("Cloud");

	nodeImage = nodeCloud.append_child("Sprite");
	nodeImage.text().set("CloudBoss4.png");

	nodeBoss = nodeCloud.append_child("IsBoss");
	nodeBoss.text().set(true);

	nodeRed = nodeCloud.append_child("Red");
	nodeRed.text().set(155);

	nodeGreen = nodeCloud.append_child("Green");
	nodeGreen.text().set(100);

	nodeBlue = nodeCloud.append_child("Blue");
	nodeBlue.text().set(0);

	nodeImputArray = nodeCloud.append_child("ImputArray");

	node1 = nodeImputArray.append_child("Imput");
	node1.text().set("M");

	node2 = nodeImputArray.append_child("Imput");
	node2.text().set("I");

	node3 = nodeImputArray.append_child("Imput");
	node3.text().set("C");

	node4 = nodeImputArray.append_child("Imput");
	node4.text().set("H");

	node4 = nodeImputArray.append_child("Imput");
	node4.text().set("E");

	node1 = nodeImputArray.append_child("Imput");
	node1.text().set("L");

	node2 = nodeImputArray.append_child("Imput");
	node2.text().set("S");

	node3 = nodeImputArray.append_child("Imput");
	node3.text().set("I");

	node4 = nodeImputArray.append_child("Imput");
	node4.text().set("M");

	node4 = nodeImputArray.append_child("Imput");
	node4.text().set("A");

	node1 = nodeImputArray.append_child("Imput");
	node1.text().set("T");

	node2 = nodeImputArray.append_child("Imput");
	node2.text().set("I");

	node4 = nodeImputArray.append_child("Imput");
	node4.text().set("C");

	nodeCloud = root.append_child("Cloud");

	nodeImage = nodeCloud.append_child("Sprite");
	nodeImage.text().set("CloudBoss5.png");

	nodeBoss = nodeCloud.append_child("IsBoss");
	nodeBoss.text().set(true);

	nodeRed = nodeCloud.append_child("Red");
	nodeRed.text().set(155);

	nodeGreen = nodeCloud.append_child("Green");
	nodeGreen.text().set(0);

	nodeBlue = nodeCloud.append_child("Blue");
	nodeBlue.text().set(100);

	nodeImputArray = nodeCloud.append_child("ImputArray");

	node1 = nodeImputArray.append_child("Imput");
	node1.text().set("K");

	node2 = nodeImputArray.append_child("Imput");
	node2.text().set("S");

	node3 = nodeImputArray.append_child("Imput");
	node3.text().set("M");

	node4 = nodeImputArray.append_child("Imput");
	node4.text().set("P");

	node4 = nodeImputArray.append_child("Imput");
	node4.text().set("I");

	node1 = nodeImputArray.append_child("Imput");
	node1.text().set("B");

	node2 = nodeImputArray.append_child("Imput");
	node2.text().set("H");

	node3 = nodeImputArray.append_child("Imput");
	node3.text().set("C");

	node4 = nodeImputArray.append_child("Imput");
	node4.text().set("W");

	node4 = nodeImputArray.append_child("Imput");
	node4.text().set("U");

	node1 = nodeImputArray.append_child("Imput");
	node1.text().set("T");

	node2 = nodeImputArray.append_child("Imput");
	node2.text().set("D");

	node4 = nodeImputArray.append_child("Imput");
	node4.text().set("A");

	node2 = nodeImputArray.append_child("Imput");
	node2.text().set("G");

	node4 = nodeImputArray.append_child("Imput");
	node4.text().set("Y");

	node1 = nodeImputArray.append_child("Imput");
	node1.text().set("E");

	node2 = nodeImputArray.append_child("Imput");
	node2.text().set("L");

	node4 = nodeImputArray.append_child("Imput");
	node4.text().set("O");

	node2 = nodeImputArray.append_child("Imput");
	node2.text().set("Z");

	node4 = nodeImputArray.append_child("Imput");
	node4.text().set("R");

	nodeCloud = root.append_child("Cloud");

	nodeImage = nodeCloud.append_child("Sprite");
	nodeImage.text().set("CloudBoss6.png");

	nodeBoss = nodeCloud.append_child("IsBoss");
	nodeBoss.text().set(true);

	nodeRed = nodeCloud.append_child("Red");
	nodeRed.text().set(0);

	nodeGreen = nodeCloud.append_child("Green");
	nodeGreen.text().set(155);

	nodeBlue = nodeCloud.append_child("Blue");
	nodeBlue.text().set(100);

	nodeImputArray = nodeCloud.append_child("ImputArray");

	node1 = nodeImputArray.append_child("Imput");
	node1.text().set("T");

	node2 = nodeImputArray.append_child("Imput");
	node2.text().set("E");

	node3 = nodeImputArray.append_child("Imput");
	node3.text().set("L");

	node4 = nodeImputArray.append_child("Imput");
	node4.text().set("E");

	node4 = nodeImputArray.append_child("Imput");
	node4.text().set("C");

	node1 = nodeImputArray.append_child("Imput");
	node1.text().set("O");

	node2 = nodeImputArray.append_child("Imput");
	node2.text().set("M");

	node3 = nodeImputArray.append_child("Imput");
	node3.text().set("S");

	node4 = nodeImputArray.append_child("Imput");
	node4.text().set("U");

	node4 = nodeImputArray.append_child("Imput");
	node4.text().set("D");

	node1 = nodeImputArray.append_child("Imput");
	node1.text().set("G");

	node2 = nodeImputArray.append_child("Imput");
	node2.text().set("R");

	node4 = nodeImputArray.append_child("Imput");
	node4.text().set("E");

	node2 = nodeImputArray.append_child("Imput");
	node2.text().set("N");

	node4 = nodeImputArray.append_child("Imput");
	node4.text().set("O");

	node1 = nodeImputArray.append_child("Imput");
	node1.text().set("B");

	node2 = nodeImputArray.append_child("Imput");
	node2.text().set("L");

	node4 = nodeImputArray.append_child("Imput");
	node4.text().set("E");

	docConfig.save_file(config);
	


	
	
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
