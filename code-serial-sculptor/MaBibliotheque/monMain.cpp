#include <iostream>

#include "TextureManager.h"
#include "Engine.h"
#include "Config.h"
#include <c:/Software/pugixml-1.8/src/pugixml.hpp>


using namespace std;
using namespace sf;

std::vector<Config> vectorOfConfigEasy;
std::vector<Config> vectorOfConfigBoss;

bool hardMode;

int tab[4];

pugi::xml_document doc;

pugi::xml_node arrayLoad;

char source[] = "init.xml";



void createConfig() {
	// Creation of the config.xml for the first time to make sure we have a good xml file to work with
	// Not use anymore
	
	char config[] = "config.xml";
	pugi::xml_document docConfig;

	pugi::xml_node nodeCloud;
	pugi::xml_node nodeImage;
	pugi::xml_node nodeBoss;
	pugi::xml_node nodeRed;
	pugi::xml_node nodeGreen;
	pugi::xml_node nodeBlue;
	pugi::xml_node nodeImputArray;
	pugi::xml_node node1;
	pugi::xml_node node2;
	pugi::xml_node node3;
	pugi::xml_node node4;


	auto root = docConfig.append_child("Root");
	nodeCloud = root.append_child("Cloud");

	nodeImage = nodeCloud.append_child("Sprite");
	nodeImage.text().set("CloudEasy1.png");

	nodeBoss = nodeCloud.append_child("IsBoss");
	nodeBoss.text().set(false);

	nodeRed = nodeCloud.append_child("Red");
	nodeRed.text().set(0);

	nodeGreen = nodeCloud.append_child("Green");
	nodeGreen.text().set(255);

	nodeBlue = nodeCloud.append_child("Blue");
	nodeBlue.text().set(0);

	nodeImputArray = nodeCloud.append_child("ImputArray");

	node1 = nodeImputArray.append_child("Imput");
	node1.text().set("B");

	node2 = nodeImputArray.append_child("Imput");
	node2.text().set("O");

	node3 = nodeImputArray.append_child("Imput");
	node3.text().set("M");

	node4 = nodeImputArray.append_child("Imput");
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

	//Cloud Boss

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
	
}

int readConfig() {
	//reading the config.xml
	char sourceConfig[] = "config.xml";
	
	pugi::xml_document docConfig;
	pugi::xml_parse_result resultConfig = docConfig.load_file(sourceConfig);
	if (resultConfig)
	{
		std::cout << "XML [" << sourceConfig << "] parsed without errors, attr value: [" << docConfig.child("node").attribute("attr").value() << "]\n\n";
		auto root = docConfig.child("Root");
		auto nodes = root.select_nodes("Cloud");
		
		
		for (auto it = nodes.begin(); it != nodes.end(); it++)
		{

			Config newConfig;
			newConfig.setSprite(it->node().child("Sprite").text().as_string());
			

			newConfig.setIsBoss(it->node().child("IsBoss").text().as_bool());
			

			newConfig.setRed(it->node().child("Red").text().as_int());
			

			newConfig.setGreen(it->node().child("Green").text().as_int());
			

			newConfig.setBlue(it->node().child("Blue").text().as_int());
			

			auto nodesKey = it->node().child("ImputArray").select_nodes("Imput");

			
			newConfig.reserveVectorOfKeyChar(nodesKey.size());

			for (auto key = nodesKey.begin(); key != nodesKey.end(); key++)
			{
				std::string value = key->node().text().as_string();
				newConfig.addKeyChar(value[0]);
			}
			
		
			if (newConfig.getIsBoss()) {
				vectorOfConfigBoss.push_back(newConfig);
			} else {
				vectorOfConfigEasy.push_back(newConfig);
			}
			
		}


	}
	else
	{
		std::cout << "Parse Failled For Config.xml" << endl;
		return -1;
	}
	return 0;
}

void readInit() {
	
	
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

		pugi::xml_node node = root.append_child("Height");
		node.text().set(1200);
		
		node = root.append_child("Width");
		node.text().set(600);

		doc.save_file(source);
	}


	

	auto rootLoad = doc.child("Root");
	arrayLoad = rootLoad.child("Array");

	tab[0] = arrayLoad.attribute("hs0").as_int();
	tab[1] = arrayLoad.attribute("hs1").as_int();
	tab[2] = arrayLoad.attribute("hs2").as_int();
	tab[3] = arrayLoad.attribute("hs3").as_int();

	int height;

	int width;

	auto node = rootLoad.child("Height");
	height = node.text().as_int();

	node = rootLoad.child("Width");
	width = node.text().as_int();

	TextureManager::setHeight(height);
	TextureManager::setWidth(width);

	auto hardLoad = rootLoad.child("HardMode");

	hardMode = hardLoad.attribute("isHardMode").as_bool();
}

void saveInit() {
	arrayLoad.attribute("hs0") = tab[0];
	arrayLoad.attribute("hs1") = tab[1];
	arrayLoad.attribute("hs2") = tab[2];
	arrayLoad.attribute("hs3") = tab[3];

	doc.save_file(source);
}

int monMain()
{
	
	int ret = 0;
	ret = readConfig();
	if (ret == -1) {
		return -1;
	}
	
	readInit();


	Engine mainEngine = Engine(hardMode);
	mainEngine.setHighScore(tab);
	mainEngine.setVectorOfConfigEasy(vectorOfConfigEasy);
	mainEngine.setVectorOfConfigBoss(vectorOfConfigBoss);
	mainEngine.launchMainMenu();

	mainEngine.getHighScore(tab);

	saveInit();

	

	return 0;
}
