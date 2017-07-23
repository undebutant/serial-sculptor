#include "Engine.h"

using namespace std;
using namespace sf;


Engine::Engine(bool setHard) : hardMode(setHard){

}



void Engine::init() {
	invulnerable = 1;
	drawSculptor = true;

	// Resetting the time reference value
	srand((unsigned int)time(NULL));
	
	updateMenu();
}



/* Main loop of the game handling two main states :
   - Main menu (highscores, options, newgame, exit)
   - In game (3 phases detailed in the .h)
*/
void Engine::launchMainMenu() {
	TextureManagerSingleton &manager = TextureManagerSingleton::Instance();

	Clock clock;
	Event event;

	ContextSettings settings;
	settings.antialiasingLevel = 8;

	// Checking loading of music files and setting up
	// Losing life theme to put in private pointer variable
	sf::Music musicBad;
	if (!musicBad.openFromFile("music\\bad.wav")) {
		assert(false);
	}
	musicBad.setLoop(false);
	musicBadPtr = &musicBad;

	// Main theme to read in main menu
	sf::Music music;
	if (!music.openFromFile("music\\mainmenu-loop.wav")) {
		assert(false);
	}
	music.play();
	music.setLoop(true);

	// Creating the displayed window
	RenderWindow window(sf::VideoMode(manager.getHeight(), manager.getWidth()), "Serial sculptor", Style::Titlebar | Style::Close, settings);
	
	// Resetting main variables to fit the current window display size
	init();
	
	isGameLaunched = false;

	int lastphase = 0;					// Storing the last phase of the game handled properly by the loop
	bool lastisGameLaunched = false;	// One time trigger to reload main menu properly after a game over
	bool lastGameEnded = false;			// One time trigger to end a game properly

	bool nomadness = true;				// Preventing loops on the fullscreen shortcuts
	bool laltpressed = false;
	bool returnpressed = false;

	// Main loop of the game
	while (window.isOpen()) {

		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}

			// Key input handling
			if (event.type == Event::KeyPressed) {
				if (event.key.code == Keyboard::Escape) {
					window.close();
				}

			// Handling fullscreen shortcut with left alt + enter keys
				// Case left alt is pressed in the main menu
				if (!isGameLaunched && event.key.code == Keyboard::LAlt) {
					laltpressed = true;
					if (nomadness && returnpressed) {
						if (!manager.getFullscreen()) {
							// Getting the data on the used screen
							POINT Ecran = { GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN) };

							// Recreating the window
							window.create(sf::VideoMode(Ecran.x, Ecran.y), "Serial sculptor", Style::Fullscreen | Style::Close, settings);

							// Storing fullscreen data in the TextureManagerSingleton
							auto size = window.getSize();
							manager.setFullscreen(size.x, size.y);

							// Updating display and preventing loops
							updateMenu();
							nomadness = false;
						}
						else { // Already in fullscreen
							manager.setFullscreen(false);

							window.create(sf::VideoMode(manager.getHeight(), manager.getWidth()), "Serial sculptor", Style::Titlebar | Style::Close, settings);
							
							updateMenu();
							nomadness = false;
						}
					}
				}

				// Case enter is pressed in the main menu
				if (!isGameLaunched && event.key.code == Keyboard::Return) {
					returnpressed = true;
					if (nomadness && laltpressed) {
						if (!manager.getFullscreen()) {
							POINT Ecran = { GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN) };

							window.create(sf::VideoMode(Ecran.x, Ecran.y), "Serial sculptor", Style::Fullscreen | Style::Close, settings);
							
							auto size = window.getSize();
							manager.setFullscreen(size.x, size.y);
							
							updateMenu();
							nomadness = false;
						}
						else { // Already in fullscreen
							manager.setFullscreen(false);

							window.create(sf::VideoMode(manager.getHeight(), manager.getWidth()), "Serial sculptor", Style::Titlebar | Style::Close, settings);
							
							updateMenu();
							nomadness = false;
						}
					}
				}

				
			// Handling key input while in game
				if (isGameLaunched) {
					keyPressed(event.key.code);
				}

			}

			// Key released handling on main menu to reset antiloop fullscreen variable
			else if (!isGameLaunched && event.type == Event::KeyReleased) {
				if (event.key.code == Keyboard::LAlt) {
					laltpressed = false;
					if (!nomadness && !returnpressed) {
						nomadness = true;
					}
				}
				if (event.key.code == Keyboard::Return) {
					returnpressed = false;
					if (!nomadness && !laltpressed) {
						nomadness = true;
					}
				}
			}

			// Mouse click handling when on the main menu
			else if (!isGameLaunched && event.type == Event::MouseButtonPressed) {
				// When clicking on the new game button
				if (event.mouseButton.x > ((float)manager.getHeight() * 150 / 1200)
					&& event.mouseButton.x < ((float)manager.getHeight() * 716 / 1200)
					&& event.mouseButton.y >((float)manager.getWidth() * 140 / 675)
					&& event.mouseButton.y < ((float)manager.getWidth() * 220 / 675)) {
					
					
					if (!music.openFromFile("music\\phase0-loop.wav")) {
						assert(false);
					}
					music.play();
					music.setLoop(true);

					newGame();
				}

				// Clicking on the toggle hardModee button
				if (event.mouseButton.x >((float)manager.getHeight() * 242 / 1200)
					&& event.mouseButton.x < ((float)manager.getHeight() * 624 / 1200)
					&& event.mouseButton.y >((float)manager.getWidth() * 260 / 675)
					&& event.mouseButton.y < ((float)manager.getWidth() * 340 / 675)) {

					setIsHard();
				}

				// Clicking on the exit button
				if (event.mouseButton.x >((float)manager.getHeight() * 242 / 1200)
					&& event.mouseButton.x < ((float)manager.getHeight() * 624 / 1200)
					&& event.mouseButton.y >((float)manager.getWidth() * 380 / 675)
					&& event.mouseButton.y < ((float)manager.getWidth() * 460 / 675)) {

					window.close();
				}
			}
		} // End pollEvent loop

		
		window.clear();
		float time = clock.restart().asSeconds();		// Elapsed time since previous loop

		
		if (isGameLaunched) {
			lastisGameLaunched = isGameLaunched;
			
			if (gameEnded) {
				// If the end theme wasn't played yet
				if (lastGameEnded != gameEnded) {
					lastGameEnded = gameEnded;
					
					if (!music.openFromFile("music\\fail.wav")) {
						assert(false);
					}
					music.play();
					music.setLoop(false);
				}
			}
			else { // The game goes on
				// If the phase just changed
				if (lastphase != phase) {
					lastphase = phase;

					if (phase == 0) {			// Easy cloud phase
						if (!music.openFromFile("music\\phase0-loop.wav")) {
							assert(false);
						}
						music.play();
						music.setLoop(true);
					}
					else if (phase == 1) {		// Boss phase
						if (!music.openFromFile("music\\phase1-loop.wav")) {
							assert(false);
						}
						music.play();
						music.setLoop(true);
					}
					else if (phase == 2) {		// Transition between waves
						if (!music.openFromFile("music\\phase2.wav")) {
							assert(false);
						}
						music.play();
						music.setLoop(false);
					}
				}
			}

			// Resolving game progression using time and rendering the updated display
			update(time);
			drawAllInGame(window);
		}

		else { // Handling the window when on the main menu
			if (lastisGameLaunched != isGameLaunched) {
				if (!music.openFromFile("music\\mainmenu-loop.wav")) {
					assert(false);
				}
				music.play();
				music.setLoop(true);

				lastisGameLaunched = isGameLaunched;
				lastGameEnded = false;
			}
			drawMainMenu(window);
		}
		
		window.display();
	}
}


// Function called to render the main menu
void Engine::drawMainMenu(RenderWindow &renderer) {
	for (int i = 0; i < ((int)listOfBackgroundItemsMainMenu.size()); i++) {
		listOfBackgroundItemsMainMenu[i]->draw(renderer);
	}

	renderer.draw(menuTitle);

	// Rendering known highscores
	if (!topScores.empty()) {
		TextureManagerSingleton &manager = TextureManagerSingleton::Instance();

		sf::Text topScoreTitle;
		topScoreTitle.setString(L"Top Score");
		topScoreTitle.setCharacterSize(manager.getHeight() * 70 / 1200);
		topScoreTitle.setFillColor(Color(255, 0, 0));
		topScoreTitle.setFont(fontLoaded);
		topScoreTitle.setStyle(Text::Bold);
		topScoreTitle.setPosition((float)manager.getHeight() * 800 / 1200, (float)manager.getWidth() * 30 / 600);

		renderer.draw(topScoreTitle);

		int j = 0;

		while (j < ((int)topScores.size()) && j < 4) {
			sf::Text topScore1Title;
			topScore1Title.setString(L"Top Score");

			std::string score = "Vague : ";
			score = score + std::to_string(topScores[topScores.size() - 1 - j]);

			topScore1Title.setString(score);
			topScore1Title.setCharacterSize(manager.getHeight() * 70 / 1200);
			topScore1Title.setFillColor(Color(255, 0, 0));
			topScore1Title.setFont(fontLoaded);
			topScore1Title.setStyle(Text::Bold);
			topScore1Title.setPosition((float)manager.getHeight() * 800 / 1200, (float)manager.getWidth()*(30.f + (100.f*j) + 100.f) / 600);

			renderer.draw(topScore1Title);

			j++;
		}
	}
}


// Resizing all stored elements to fit the current window dimensions
void Engine::updateMenu() {
	listOfBackgroundItemsMainMenu.clear();
	listOfBackgroundItems.clear();
	listOfHUDItems.clear();

	TextureManagerSingleton &manager = TextureManagerSingleton::Instance();
	fontLoaded = manager.getFont();


	// Resizing elements for the main menu

	std::unique_ptr<SceneryItem> menuBackground = std::unique_ptr<SceneryItem>(new SceneryItem());
	menuBackground->setSize((float)manager.getHeight(), (float)manager.getWidth());

	std::unique_ptr<SceneryItem> newGameButton = std::unique_ptr<SceneryItem>(new SceneryItem());
	newGameButton->setSize((float)manager.getHeight() * 566 / 1200, (float)manager.getWidth() * 80 / 675);

	std::unique_ptr<SceneryItem> exitButton = std::unique_ptr<SceneryItem>(new SceneryItem());
	exitButton->setSize((float)manager.getHeight() * 382 / 1200, (float)manager.getWidth() * 80 / 675);

	std::unique_ptr<SceneryItem> hardButton = std::unique_ptr<SceneryItem>(new SceneryItem());
	hardButton->setSize((float)manager.getHeight() * 382 / 1200, (float)manager.getWidth() * 80 / 675);


	menuBackground->setTexture("mainMenuBackground.jpeg");
	newGameButton->setTexture("newGameButton.png");
	exitButton->setTexture("exitButton.png");

	if (hardMode) {
		hardButton->setTexture("hardOnButton.png");
	}
	else {
		hardButton->setTexture("hardButton.png");
	}


	newGameButton->setPosition((float)manager.getHeight() * 150 / 1200, (float)manager.getWidth() * 140 / 675);
	exitButton->setPosition((float)manager.getHeight() * 242 / 1200, (float)manager.getWidth() * 380 / 675);
	hardButton->setPosition((float)manager.getHeight() * 242 / 1200, (float)manager.getWidth() * 260 / 675);
	

	listOfBackgroundItemsMainMenu.push_back(move(menuBackground));
	listOfBackgroundItemsMainMenu.push_back(move(newGameButton));
	listOfBackgroundItemsMainMenu.push_back(move(exitButton));
	listOfBackgroundItemsMainMenu.push_back(move(hardButton));
	

	menuTitle.setString(L"Serial Sculptor");
	menuTitle.setCharacterSize(manager.getHeight() * 70 / 1200);
	menuTitle.setFillColor(Color(255, 255, 255, 255));
	menuTitle.setFont(fontLoaded);
	menuTitle.setStyle(Text::Bold);

	menuTitle.setPosition((float)manager.getHeight() * 210 / 1200, (float)manager.getWidth() * 30 / 675);


	//Resizing elements for the game layout

	std::unique_ptr<SceneryItem> gameBackground = std::unique_ptr<SceneryItem>(new SceneryItem());

	gameBackground->setSize((float)manager.getHeight(), (float)manager.getWidth());
	gameBackground->setTexture("gameBackground.jpeg");

	listOfBackgroundItems.push_back(move(gameBackground));


	// Resizing elements for the HUD layout

	vagueTitle.setString(L"Vague : 1");
	vagueTitle.setCharacterSize(manager.getHeight() * 70 / 1200);
	vagueTitle.setFillColor(Color(255, 0, 0));
	vagueTitle.setFont(fontLoaded);
	vagueTitle.setStyle(Text::Bold);

	vagueTitle.setPosition((float)manager.getHeight() * 800 / 1200, (float)manager.getWidth() * 30 / 675);
	

	failTitle.setString(L"YOU LOST");
	failTitle.setCharacterSize(manager.getHeight() * 200 / 1200);
	failTitle.setFillColor(Color(255, 0, 0));
	failTitle.setFont(fontLoaded);
	failTitle.setStyle(Text::Bold);

	failTitle.setPosition((float)manager.getHeight() * 0 / 1200, (float)manager.getWidth() * 200 / 600);


	std::unique_ptr<SceneryItem> heartContainer1 = std::unique_ptr<SceneryItem>(new SceneryItem());
	std::unique_ptr<SceneryItem> heartContainer2 = std::unique_ptr<SceneryItem>(new SceneryItem());
	std::unique_ptr<SceneryItem> heartContainer3 = std::unique_ptr<SceneryItem>(new SceneryItem());

	heartContainer1->setSize((float)manager.getHeight() * 100 / 1200, (float)manager.getWidth() * 100 / 675);
	heartContainer2->setSize((float)manager.getHeight() * 100 / 1200, (float)manager.getWidth() * 100 / 675);
	heartContainer3->setSize((float)manager.getHeight() * 100 / 1200, (float)manager.getWidth() * 100 / 675);

	heartContainer1->setTexture("heartEmpty.png");
	heartContainer2->setTexture("heartEmpty.png");
	heartContainer3->setTexture("heartEmpty.png");

	heartContainer1->setPosition((float)manager.getHeight() * 20 / 1200, (float)manager.getWidth() * 20 / 675);
	heartContainer2->setPosition((float)manager.getHeight() * 140 / 1200, (float)manager.getWidth() * 20 / 675);
	heartContainer3->setPosition((float)manager.getHeight() * 260 / 1200, (float)manager.getWidth() * 20 / 675);

	listOfHUDItems.push_back(move(heartContainer1));
	listOfHUDItems.push_back(move(heartContainer2));
	listOfHUDItems.push_back(move(heartContainer3));

	std::unique_ptr<SceneryItem> heartContainerFull1 = std::unique_ptr<SceneryItem>(new SceneryItem());
	std::unique_ptr<SceneryItem> heartContainerFull2 = std::unique_ptr<SceneryItem>(new SceneryItem());
	std::unique_ptr<SceneryItem> heartContainerFull3 = std::unique_ptr<SceneryItem>(new SceneryItem());

	heartContainerFull1->setSize((float)manager.getHeight() * 100 / 1200, (float)manager.getWidth() * 100 / 675);
	heartContainerFull2->setSize((float)manager.getHeight() * 100 / 1200, (float)manager.getWidth() * 100 / 675);
	heartContainerFull3->setSize((float)manager.getHeight() * 100 / 1200, (float)manager.getWidth() * 100 / 675);

	heartContainerFull1->setTexture("heartFull.png");
	heartContainerFull2->setTexture("heartFull.png");
	heartContainerFull3->setTexture("heartFull.png");

	heartContainerFull1->setPosition((float)manager.getHeight() * 20 / 1200, (float)manager.getWidth() * 20 / 675);
	heartContainerFull2->setPosition((float)manager.getHeight() * 140 / 1200, (float)manager.getWidth() * 20 / 675);
	heartContainerFull3->setPosition((float)manager.getHeight() * 260 / 1200, (float)manager.getWidth() * 20 / 675);

	listOfHUDItems.push_back(move(heartContainerFull1));
	listOfHUDItems.push_back(move(heartContainerFull2));
	listOfHUDItems.push_back(move(heartContainerFull3));
}



// Resetting obsolete values between phases
void Engine::resetValue() {
	isRight = false;
	sculptor.updateTexture(isRight);

	numberOfSpawnedClouds = 0;
	timeUntilNextSpawn = 0;
	numberOfSpawnedBoss = 0;
}


// Resetting important values to start a new game
void Engine::newGame() {
	isRight = false;
	isGameLaunched = true;
	gameEnded = false;

	vague = 1;
	string newstr = "Vague : " + std::to_string(vague);
	vagueTitle.setString(newstr);
	
	timeUntilNextSpawn = 0;
	
	phase = 0;
	numberOfSpawnedClouds = 0;
	numberOfSpawnedBoss = 0;
	
	Sculptor newsculptor;
	sculptor = newsculptor;
	invulnerable = 1;
}



void Engine::keyPressed(Keyboard::Key keyPressed) {
	if (!gameEnded) {
		if (!listOfClouds.empty()) {
			bool a = listOfClouds.back()->tryKeyInput(keyPressed);
			if (!a) {
				if (invulnerable >= 1) {
					invulnerable = 0;
					sculptor.decrHealth(1);
					musicBadPtr->play();
					if (sculptor.getHealth() == 0) {
						gameEnded = true;
						timeUntilNextSpawn = 0;
					}
				}
			}
		}
	}
}



// Handling the creation of a new cloud, whether easy or boss, and adding it to the listOfClouds
void Engine::createNewCloud(int cloudToCreate, bool isBoss) {
	Cloud *cloudToAdd;

	cloudToAdd = new Cloud();
	cloudToAdd->init();

	if (isBoss) {
		cloudToAdd->setColor(sf::Color(vectorOfConfigBoss[cloudToCreate].getRed(), vectorOfConfigBoss[cloudToCreate].getGreen(), vectorOfConfigBoss[cloudToCreate].getBlue()));
		cloudToAdd->setTexture(vectorOfConfigBoss[cloudToCreate].getSprite());
		cloudToAdd->setIsBoss(vectorOfConfigBoss[cloudToCreate].getIsBoss());

		auto vect = vectorOfConfigBoss[cloudToCreate].getVectorOfKeyChar();

		for (int i = 0; i < (int)vect.size(); i++) {
			cloudToAdd->addKey(vect[i]);
		}
	}
	else {
		cloudToAdd->setColor(sf::Color(vectorOfConfigEasy[cloudToCreate].getRed(), vectorOfConfigEasy[cloudToCreate].getGreen(), vectorOfConfigEasy[cloudToCreate].getBlue()));
		cloudToAdd->setTexture(vectorOfConfigEasy[cloudToCreate].getSprite());
		cloudToAdd->setIsBoss(vectorOfConfigEasy[cloudToCreate].getIsBoss());
		
		auto vect = vectorOfConfigEasy[cloudToCreate].getVectorOfKeyChar();

		for (int i = 0; i < (int)vect.size(); i++) {
			cloudToAdd->addKey(vect[i]);
		}
	}

	// Initializing objects to render given the cloud created
	cloudToAdd->update();

	unique_ptr<Cloud> ptrCloudToAdd(cloudToAdd);
	ptrCloudToAdd->setIsRight(isRight);

	if (hardMode) {
		ptrCloudToAdd->setSpeed(20);
	}

	if (listOfClouds.empty()) {
		sculptor.updateTexture(isRight);
	}

	isRight = !isRight;

	listOfClouds.insert(listOfClouds.begin(), move(ptrCloudToAdd));
}


void Engine::createNewRandomEasy() {
	int i = rand() % ((int)vectorOfConfigEasy.size());
	createNewCloud(i, false);
}


// Handling cloud when all of its inputs are done
void Engine::deleteCloudsDone() {
	// Testing the last cloud of the vector, moving it to old if done
	if (!listOfClouds.empty()) {
		if (listOfClouds.back()->isDone()) {
			listOfOldClouds.push_back(move(listOfClouds[listOfClouds.size() - 1]));
			listOfClouds.pop_back();
			if (!listOfClouds.empty()) {
				sculptor.updateTexture(listOfClouds.back()->getIsRight());
			}
		}
	}

	// Scanning all the old cloud, testing if death animation is done, if so, deleting them
	vector<unique_ptr<Cloud>> swapVector;
	for (int i = 0; i < (int)listOfOldClouds.size(); i++) {
		if (!listOfOldClouds[i]->getIsTimeOut()) {
			swapVector.push_back(move(listOfOldClouds[i]));
		}
	}

	listOfOldClouds.swap(swapVector);
}



// Handling collision between the sculptor and clouds
bool Engine::isHPLost(bool isCloudRight, bool isBoss, int posXcloud) {
	TextureManagerSingleton &manager = TextureManagerSingleton::Instance();
	int posXlim;
	
	// Defining hitbox for each cases
	if (isCloudRight) {
		posXlim = manager.getHeight() * 660/1200;
	}
	else {
		posXlim = manager.getHeight()*436/1200;
		if (isBoss) {
			posXlim -= (manager.getHeight()*100/1200);
		}
	}

	// Checking hitbox for the active cloud
	if (isCloudRight) {
		if (posXcloud <= posXlim) {
			sculptor.decrHealth(1);
			musicBadPtr->play();
			if (sculptor.getHealth() == 0) {
				gameEnded = true;
				timeUntilNextSpawn = 0;
			}
			return true;
		}
	}
	else {
		if (posXcloud >= posXlim) {
			sculptor.decrHealth(1);
			musicBadPtr->play();
			if (sculptor.getHealth() == 0) {
				gameEnded = true;
				timeUntilNextSpawn = 0;
			}
			return true;
		}
	}
	return false;
}


// Updating data about the cloud given the elapsed time
void Engine::update(float time) {
	if (!gameEnded) {
		timeUntilNextSpawn += time;

		if (invulnerable < 1) {
			invulnerable += time;
		}

		// Updating existing sprites
		for (int i = 0; i < (int)listOfClouds.size(); i++) {
			listOfClouds[i]->update(time);
			// Handling collision
			if (isHPLost(listOfClouds[i]->getIsRight(), listOfClouds[i]->getIsBoss(), (int)listOfClouds[i]->getPosition().x)) {
				listOfClouds[i]->setIsDone();
			}
		}

		for (int i = 0; i < (int)listOfOldClouds.size(); i++) {
			listOfOldClouds[i]->update(time);
		}

		deleteCloudsDone();

		// Defining references for spawning
		int n = vague / ((int)vectorOfConfigBoss.size());

		float spawnDelay = 2.f - (n*0.1f);
		if (spawnDelay < 1) {
			spawnDelay = 1;
		}

		int facteur = 2;
		if (hardMode) {
			facteur = 4;
			spawnDelay = spawnDelay / 2.f;
		}
		
		int maxSpawn = vague * facteur;

		// Handling phase progression
		if (phase == 0) {
			if (numberOfSpawnedClouds >= maxSpawn) {
				// All clouds spawned, checking if any left not done
				if (listOfClouds.empty()) {
					phase = 1;
					resetValue();
				}
			}
			else { // Still clouds to spawn, checking on timer
				if (timeUntilNextSpawn > spawnDelay) {
					createNewRandomEasy();

					timeUntilNextSpawn = 0;
					numberOfSpawnedClouds++;
				}
			}
		}
		else if (phase == 1) {
			if (numberOfSpawnedClouds >= maxSpawn) {
				if (listOfClouds.empty()) {
					phase = 2;
					vague++;
					sculptor.incrHealth(1); // Recovering one HP each wave done
					resetValue();
				}
			}
			else {
				if (timeUntilNextSpawn > spawnDelay) { // Fix adding delay between spawn
					if (numberOfSpawnedClouds % 2 == 1) {
						createNewRandomEasy();
					}
					int maxBoss = (n + 1);
					if (hardMode) {
						maxBoss = 2 * maxBoss;
					}
					if (numberOfSpawnedBoss < maxBoss) {

						createNewCloud(vague % ((int)vectorOfConfigBoss.size()), true);
						numberOfSpawnedBoss++;

					}
					if (numberOfSpawnedClouds % 2 == 0) {
						createNewRandomEasy();
					}

					timeUntilNextSpawn = 0;
					numberOfSpawnedClouds++;
				}
			}
		}
		else if (phase == 2) {
			if (timeUntilNextSpawn > 2) { // End of the break
				phase = 0;
				setVagueTitleCorner();
				resetValue();
			}
			else { // 2 seconds break between waves
				string newstr = "Vague : " + std::to_string(vague);
				vagueTitle.setString(newstr);
				setVagueTitleFullScreen();
			}
		}
		else {
			assert(false);
		}
	}
	else { // Game is ended, letting some time for game over screen
		timeUntilNextSpawn += time;
		setVagueTitleCorner();
		if (timeUntilNextSpawn > 5) {
			isGameLaunched = false;

			listOfClouds.clear();
			listOfOldClouds.clear();
			
			if (vague - 1 > 0) {
				topScores.push_back(vague - 1);
				std::sort(topScores.begin(), topScores.begin() + topScores.size());
			}
		}
	}
}


// Rendering all elements while in game
void Engine::drawAllInGame(sf::RenderWindow &renderer) {
	for (int i = 0; i < ((int)listOfBackgroundItems.size()); i++) {
		listOfBackgroundItems[i]->draw(renderer);
	}

	for (int i = 0; i < (int)listOfClouds.size(); i++) {
		listOfClouds[i]->draw(renderer);
	}

	for (int i = 0; i < (int)listOfOldClouds.size(); i++) {
		listOfOldClouds[i]->draw(renderer);
	}
	
	// Drawing expected input letters for the active cloud
	if (!listOfClouds.empty()) {
		listOfClouds.back()->drawLetter(renderer);
	}
	
	// Drawing heart left
	for (int i = sculptor.getHealth(); i < sculptor.getHealth() + 3; i++) {
		listOfHUDItems[i]->draw(renderer);
	}

	// Drawing current wave number
	renderer.draw(vagueTitle);

	if (gameEnded) {
		sculptor.draw(renderer);
		renderer.draw(failTitle);
	}
	else {
		if (invulnerable >= 1) {
			sculptor.draw(renderer);
		}
		else { // Clipping while invulnerability is up
			if (drawSculptor) {
				sculptor.draw(renderer);
			}
			drawSculptor = !drawSculptor;
		}
	}
}



// Setting text announcing current wave in fullscreen
void Engine::setVagueTitleFullScreen() {
	TextureManagerSingleton &manager = TextureManagerSingleton::Instance();
	vagueTitle.setCharacterSize(manager.getHeight() * 200 / 1200);
	vagueTitle.setPosition((float)manager.getHeight() * 200 / 1200, (float)manager.getWidth() * 200 / 675);
}


// Setting text announcing current wave in corner
void Engine::setVagueTitleCorner() {
	TextureManagerSingleton &manager = TextureManagerSingleton::Instance();
	vagueTitle.setCharacterSize(manager.getHeight() * 70 / 1200);
	vagueTitle.setPosition((float)manager.getHeight() * 800 / 1200, (float)manager.getWidth() * 30 / 675);
}



// Setting up the vector of available easy clouds
void Engine::setVectorOfConfigEasy(std::vector<Config> newvectorOfConfigEasy) {
	vectorOfConfigEasy.clear();

	for (int i = 0; i < (int)newvectorOfConfigEasy.size(); i++) {
		vectorOfConfigEasy.push_back(newvectorOfConfigEasy[i]);
	}
}


// Setting up the vector of available boss clouds
void Engine::setVectorOfConfigBoss(std::vector<Config> newvectorOfConfigBoss) {
	vectorOfConfigBoss.clear();

	for (int i = 0; i < (int)newvectorOfConfigBoss.size(); i++) {
		vectorOfConfigBoss.push_back(newvectorOfConfigBoss[i]);
	}

}



void Engine::setHighScore(int tab[4]) {
	for (int i = 0; i < 4; i++) {
		if (tab[i] > 0) {
			topScores.push_back(tab[i]);
		}
	}
	std::sort(topScores.begin(), topScores.begin() + topScores.size());
}


void Engine::getHighScore(int tab[4]) {
	int i = 0;
	while ((!topScores.empty()) && i < 4) {
		tab[i]=topScores.back();
		topScores.pop_back();
		i++;
	}
	while (i < 4) {
		tab[i] = 0;
		i++;
	}
}



void Engine::setIsHard() {
	hardMode = !hardMode;
	
	if (hardMode) {
		listOfBackgroundItemsMainMenu[3]->setTexture("hardOnButton.png");
	}
	else {
		listOfBackgroundItemsMainMenu[3]->setTexture("hardButton.png");
	}
}


bool Engine::getIsHard() {
	return hardMode;
}
